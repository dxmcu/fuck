#include "task_thread.h"

namespace nav{

bool TaskThread::start()
{
	cout << _name << " start" << endl;
	unique_lock<mutex> lock(_mt);
	if (_running) return true;

	_running = true;	
	if (_thd == nullptr)
	{
		_thd = new thread(&_thread_proc_cb, this);
		_thd->detach();
	}

	cout << _name << " start ok" << endl;

	return true;
}

bool TaskThread::stop(){
	cout << _name << " stop..." << endl;
	unique_lock<mutex> lock(_mt);
	if (_thd == nullptr || !_running) return true;

	_running = false;	
	_cv.notify_one();
	lock.unlock();
	
	if (_thd->joinable())
		_thd->join();

	cout << _name << " stop ok" << endl;
	return true;
}

bool TaskThread::push(Task* t){
	cout << _name << " push task" << endl;
	if (t == nullptr) return false;

	unique_lock<mutex> lock(_mt);
	if (_t && _t->is_finished()){
		cout << "pre task still running" << endl;
		return false;
	}

	_t = t;
	_cv.notify_one();
	lock.unlock();

	_t->Task::wait_ready();
	cout << _name << " push " << t->name() << endl;
	return true;
}

void TaskThread::_thread_proc()
{
	cout << _name << " running" << endl;
	
	while (_running)
	{
		unique_lock<mutex> lock(_mt);
		cout << _name << " wait..." << endl;
		while (_running && (_t == nullptr || _t->is_finished())) _cv.wait(lock);
	
		cout << _name << " wait:" << _t->name() << " st:" << _t->status() << endl;

		if (!_running)
		{
			cout << _name << " break..." << endl;
			break;
		}

		while (!_t->is_finished()){
			_t->wait();
		}
	}
	_exited = true;
	cout << _name << " exit" << endl;
}

}

