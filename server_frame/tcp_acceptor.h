#pragma once
#include "io_handler.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/types.h>
#include <tr1/functional>

namespace comm
{

typedef std::tr1::function<int(int,sockaddr_in*)> accept_cb;
class tcp_acceptor:public io_handler
{
public:
	tcp_acceptor(){};
	~tcp_acceptor(){};
	int open(int fd, const string& ip, ushort port, accept_cb cb);
	void close();

protected:
	virtual void on_read();
	virtual void on_write();
	virtual void on_error();

private:
	accept_cb _cb;	
};
}
