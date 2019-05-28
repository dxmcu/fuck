#include "ubtmsgmapping.h"
#include "ubtmsg.h"
#include "UBTUIProxy/ubtuidefine.h"
#include "UBTAudioProxy/ubtaudioevent.h"
#include "UBTMscProxy/ubtmscevent.h"
#include "UBTSystemKeyProxy/ubtsystemkeyevent.h"
#include "UBTSystemSettingProxy/ubtsystemevent.h"
#include "UBTReminderProxy/ubtreminderevent.h"
#include "UBTAlarmProxy/ubtalarmevent.h"
#include "UBTUpdateProxy/ubtupdateevent.h"
#include "UBTInitialBootProxy/ubtinitialbootevent.h"
#include "UBTGSensorProxy/ubtgsensorevent.h"
#include "UBTBatteryProxy/ubtbatteryevent.h"
#include "UBTBluetoothProxy/ubtbluetoothevent.h"
#include "UBTWIFIProxy/ubtwifievent.h"


unordered_map<UBTMSG, string> UBTMsgMapping::s_int2str_msg =
{
    {UBTMSG_MSC_WAKEUP,string(UBTEVENT_MSC_WAKEUP)},
    {UBTMSG_MSC_RECOGCMD_START,string(UBTEVENT_MSC_RECOGCMD_START)},
    {UBTMSG_MSC_RECOGCMD_RESTART,string(UBTEVENT_MSC_RECOGCMD_RESTART)},
    {UBTMSG_MSC_RECOGCMD_PARSING,string(UBTEVENT_MSC_RECOGCMD_PARSING)},
    {UBTMSG_MSC_RECOGCMD_END,string(UBTEVENT_MSC_RECOGCMD_END)},
    {UBTMSG_MSC_RECOGCMD_OFFLINERESULT,string(UBTEVENT_MSC_RECOGCMD_OFFLINERESULT)},
    {UBTMSG_MSC_RECOGCMD_ONLINERESULT,string(UBTEVENT_MSC_RECOGCMD_ONLINERESULT)},
    {UBTMSG_MSC_RECOGCMD_RESULT_DETAILS,string(UBTEVENT_MSC_RECOGCMD_RESULT_DETAILS)},
    {UBTMSG_MSC_RECOGCMD_NORESULT,string(UBTEVENT_MSC_RECOGCMD_NORESULT)},
    {UBTMSG_MSC_RECOGCMD_ERROR,string(UBTEVENT_MSC_RECOGCMD_ERROR)},
    {UBTMSG_MSC_SEMANTIC_RESULT,string(UBTEVENT_MSC_SEMANTIC_RESULT)},
    {UBTMSG_MSC_EXPECT_SPEECH_START,string(UBTEVENT_MSC_EXPECT_SPEECH_START)},
    {UBTMSG_MSC_VAD_TIMEOUT,string(UBTEVENT_MSC_VAD_TIMEOUT)},
    {UBTMSG_MSC_TTS_RECVDATA,string(UBTEVENT_MSC_TTS_RECVDATA)},
    {UBTMSG_MSC_TTS_END,string(UBTEVENT_MSC_TTS_END)},
    {UBTMSG_DINGDANG_MSC_TTS_FACE_EVENT,string(UBTEVENT_DINGDANG_MSC_TTS_FACE_EVENT)},
    {UBTMSG_DINGDANG_MSC_TTS_FACE_END_EVENT,string(UBTEVENT_DINGDANG_MSC_TTS_FACE_END_EVENT)},
    {UBTMSG_DINGDANG_MSC_WINDOW_EVENT,string(UBTEVENT_DINGDANG_MSC_WINDOW_EVENT)},
    {UBTMSG_DINGDANG_MSC_PLAYMODE_EVENT,string(UBTEVENT_DINGDANG_MSC_PLAYMODE_EVENT)},
    {UBTMSG_DINGDANG_MSC_SHUTDOWN,string(UBTEVENT_DINGDANG_MSC_SHUTDOWN)},
    {UBTMSG_DINGDANG_MSC_SHOW_QRCODE,string(UBTEVENT_DINGDANG_MSC_SHOW_QRCODE)},
    {UBTMSG_DINGDANG_MSC_MUTE,string(UBTEVENT_DINGDANG_MSC_MUTE)},
    {UBTMSG_UBTAUDIO_ERROR,string(UBTEVENT_UBTAUDIO_ERROR)},
    {UBTMSG_UBTAUDIO_PLAYER_NOTHING,string(UBTEVENT_UBTAUDIO_PLAYER_NOTHING)},
    {UBTMSG_UBTAUDIO_URI_PLAYSTART,string(UBTEVENT_UBTAUDIO_URI_PLAYSTART)},
    {UBTMSG_UBTAUDIO_URI_PLAYSTOP,string(UBTEVENT_UBTAUDIO_URI_PLAYSTOP)},
    {UBTMSG_UBTAUDIO_URI_PLAYPAUSE,string(UBTEVENT_UBTAUDIO_URI_PLAYPAUSE)},
    {UBTMSG_UBTAUDIO_URI_PLAYFINISH,string(UBTEVENT_UBTAUDIO_URI_PLAYFINISH)},
    {UBTMSG_UBTAUDIO_URI_PLAYRESUME,string(UBTEVENT_UBTAUDIO_URI_PLAYRESUME)},
    {UBTMSG_UBTAUDIO_URI_PLAYPROGRESS,string(UBTEVENT_UBTAUDIO_URI_PLAYPROGRESS)},
    {UBTMSG_UBTAUDIO_URI_DROP,string(UBTEVENT_UBTAUDIO_URI_DROP)},
    {UBTMSG_UBTAUDIO_URI_FAILED,string(UBTEVENT_UBTAUDIO_URI_FAILED)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYSTART,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYSTART)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYSTOP,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYSTOP)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYPAUSE,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYPAUSE)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYFINISH,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYFINISH)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYRESUME,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYRESUME)},
    {UBTMSG_UBTAUDIO_PROMPT_PLAYPROGRESS,string(UBTEVENT_UBTAUDIO_PROMPT_PLAYPROGRESS)},
    {UBTMSG_UBTAUDIO_PROMPT_DROP,string(UBTEVENT_UBTAUDIO_PROMPT_DROP)},
    {UBTMSG_UBTAUDIO_TTS_PLAYSTART,string(UBTEVENT_UBTAUDIO_TTS_PLAYSTART)},
    {UBTMSG_UBTAUDIO_TTS_PLAYSTOP,string(UBTEVENT_UBTAUDIO_TTS_PLAYSTOP)},
    {UBTMSG_UBTAUDIO_TTS_PLAYPAUSE,string(UBTEVENT_UBTAUDIO_TTS_PLAYPAUSE)},
    {UBTMSG_UBTAUDIO_TTS_PLAYFINISH,string(UBTEVENT_UBTAUDIO_TTS_PLAYFINISH)},
    {UBTMSG_UBTAUDIO_TTS_PLAYRESUME,string(UBTEVENT_UBTAUDIO_TTS_PLAYRESUME)},
    {UBTMSG_UBTAUDIO_TTS_PLAYPROGRESS,string(UBTEVENT_UBTAUDIO_TTS_PLAYPROGRESS)},
    {UBTMSG_UBTAUDIO_TTS_DROP,string(UBTEVENT_UBTAUDIO_TTS_DROP)},
    {UBTMSG_UBTAUDIO_BT_PLAYSTART,string(UBTEVENT_UBTAUDIO_BT_PLAYSTART)},
    {UBTMSG_UBTAUDIO_BT_PLAYSTOP,string(UBTEVENT_UBTAUDIO_BT_PLAYSTOP)},
    {UBTMSG_UBTAUDIO_BT_PLAYPAUSE,string(UBTEVENT_UBTAUDIO_BT_PLAYPAUSE)},
    {UBTMSG_UBTAUDIO_BT_PLAYFINISH,string(UBTEVENT_UBTAUDIO_BT_PLAYFINISH)},
    {UBTMSG_UBTAUDIO_BT_PLAYRESUME,string(UBTEVENT_UBTAUDIO_BT_PLAYRESUME)},
    {UBTMSG_UBTAUDIO_BT_PLAYPROGRESS,string(UBTEVENT_UBTAUDIO_BT_PLAYPROGRESS)},
    {UBTMSG_UBTAUDIO_BT_DROP,string(UBTEVENT_UBTAUDIO_BT_DROP)},
    {UBTMSG_UBTAUDIO_RECORD_RECVDATA,string(UBTEVENT_UBTAUDIO_RECORD_RECVDATA)},
    {UBTMSG_UBTAUDIO_EXPERSSION_DIR,string(UBTEVENT_UBTAUDIO_EXPERSSION_DIR)},
    {UBTMSG_UBTAUDIO_RECOGNISE_TIMEOUT,string(UBTEVENT_UBTAUDIO_RECOGNISE_TIMEOUT)},
    {UBTMSG_UBTAUDIO_CLOSED_BT_DIR,string(UBTEVENT_UBTAUDIO_CLOSED_BT_DIR)},
    {UBTMSG_UBTAUDIO_OPENNED_BT_DIR,string(UBTEVENT_UBTAUDIO_OPENNED_BT_DIR)},
    {UBTMSG_UBTAUDIO_SHOW_BATTERY_DIR,string(UBTEVENT_UBTAUDIO_SHOW_BATTERY_DIR)},
    {UBTMSG_UBTAUDIO_NET_CONFIG_DIR,string(UBTEVENT_UBTAUDIO_NET_CONFIG_DIR)},
    {UBTMSG_UBTAUDIO_WAKE_UP_DIR,string(UBTEVENT_UBTAUDIO_WAKE_UP_DIR)},
    {UBTMSG_UBTAUDIO_ALERT,string(UBTEVENT_UBTAUDIO_ALERT)},
    {UBTMSG_UBTAUDIO_COIN,string(UBTEVENT_UBTAUDIO_COIN)},
    {UBTMSG_ROBOT_FALLED_DOWN,string(UBTEVENT_ROBOT_FALLED_DOWN)},
    {UBTMSG_ROBOT_FALLED_DOWN_SOFT,string(UBTEVENT_ROBOT_FALLED_DOWN_SOFT)},
    {UBTMSG_ROBOT_TILT_EVENT,string(UBTEVENT_ROBOT_TILT_EVENT)},
    {UBTMSG_ALERT_ALARM_TIMEOUT_START,string(UBTEVENT_ALERT_ALARM_TIMEOUT_START)},
    {UBTMSG_ALERT_ALARM_TIMEOUT_END,string(UBTEVENT_ALERT_ALARM_TIMEOUT_END)},
    {UBTMSG_ALERT_ALARM_REAL_START,string(UBTEVENT_ALERT_ALARM_REAL_START)},
    {UBTMSG_BATTERY_LOWPOWER,string(UBTEVENT_BATTERY_LOWPOWER)},
    {UBTMSG_BATTERY_NORMALPOWER,string(UBTEVENT_BATTERY_NORMALPOWER)},
    {UBTMSG_BATTERY_CHARGINE,string(UBTEVENT_BATTERY_CHARGINE)},
    {UBTMSG_BATTERY_FULLCHARGED,string(UBTEVENT_BATTERY_FULLCHARGED)},
    {UBTMSG_BATTERY_DISCHARGINE,string(UBTEVENT_BATTERY_DISCHARGINE)},
    {UBTMSG_BATTERY_VALUE_CHANGE,string(UBTEVENT_BATTERY_VALUE_CHANGE)},
    {UBTMSG_BATTERY_STAT_CHANGE,string(UBTEVENT_BATTERY_STAT_CHANGE)},
    {UBTMSG_BATTERY_STANDBY_MODE,string(UBTEVENT_BATTERY_STANDBY_MODE)},
    {UBTMSG_BATTERY_NORMAL_MODE,string(UBTEVENT_BATTERY_NORMAL_MODE)},
    {UBTMSG_BLUETOOTH_LINEOFF,string(UBTEVENT_BLUETOOTH_LINEOFF)},
    {UBTMSG_BLUETOOTH_LINEON,string(UBTEVENT_BLUETOOTH_LINEON)},
    {UBTMSG_BLUETOOTH_RECEIVEDATA,string(UBTEVENT_BLUETOOTH_RECEIVEDATA)},
    {UBTMSG_BLUETOOTH_DEVICE_OPEN,string(UBTEVENT_BLUETOOTH_DEVICE_OPEN)},
    {UBTMSG_BLUETOOTH_DEVICE_CLOSE,string(UBTEVENT_BLUETOOTH_DEVICE_CLOSE)},
    {UBTMSG_INITIAL_BOOT_SHOWQR_ENTER,string(UBTEVENT_INITIAL_BOOT_SHOWQR_ENTER)},
    {UBTMSG_INITIAL_BOOT_SHOWQR_LEAVE,string(UBTEVENT_INITIAL_BOOT_SHOWQR_LEAVE)},
    {UBTMSG_INITIAL_BOOT_ENTER_NETWORKCONFIG,string(UBTEVENT_INITIAL_BOOT_ENTER_NETWORKCONFIG)},
    {UBTMSG_INITIAL_BOOT_LEAVE_NETWORKCONFIG,string(UBTEVENT_INITIAL_BOOT_LEAVE_NETWORKCONFIG)},
    {UBTMSG_INITIAL_BOOT_INTRADUCTION_ENTER,string(UBTEVENT_INITIAL_BOOT_INTRADUCTION_ENTER)},
    {UBTMSG_INITIAL_BOOT_RE_ENTER,string(UBTEVENT_INITIAL_BOOT_RE_ENTER)},
    {UBTMSG_INITIAL_BOOT_ENTER,string(UBTEVENT_INITIAL_BOOT_ENTER)},
    {UBTMSG_INITIAL_BOOT_LEAVE,string(UBTEVENT_INITIAL_BOOT_LEAVE)},
    {UBTMSG_ALERT_REMINDER_TIMEOUT_START,string(UBTEVENT_ALERT_REMINDER_TIMEOUT_START)},
    {UBTMSG_ALERT_REMINDER_TIMEOUT_END,string(UBTEVENT_ALERT_REMINDER_TIMEOUT_END)},
    {UBTMSG_ALERT_REMINDER_REAL_START,string(UBTEVENT_ALERT_REMINDER_REAL_START)},
    {UBTMSG_ALERT_REMINDER_TIMEOUT_INTERRUPT,string(UBTEVENT_ALERT_REMINDER_TIMEOUT_INTERRUPT)},
    {UBTMSG_SYSTEMKEY_POWERKEY_LONGPRESS,string(UBTEVENT_SYSTEMKEY_POWERKEY_LONGPRESS)},
    {UBTMSG_SYSTEMKEY_POWER_ONECLICK_EVENT,string(UBTEVENT_SYSTEMKEY_POWER_ONECLICK_EVENT)},
    {UBTMSG_SYSTEMKEY_INSERTCOIN,string(UBTEVENT_SYSTEMKEY_INSERTCOIN)},
    {UBTMSG_SYSTEMKEY_VOLUMEUP_PRESS,string(UBTEVENT_SYSTEMKEY_VOLUMEUP_PRESS)},
    {UBTMSG_SYSTEMKEY_VOLUMEUP_RELEASE,string(UBTEVENT_SYSTEMKEY_VOLUMEUP_RELEASE)},
    {UBTMSG_SYSTEMKEY_VOLUMEDOWN_PRESS,string(UBTEVENT_SYSTEMKEY_VOLUMEDOWN_PRESS)},
    {UBTMSG_SYSTEMKEY_VOLUMEDOWN_RELEASE,string(UBTEVENT_SYSTEMKEY_VOLUMEDOWN_RELEASE)},
    {UBTMSG_SYSTEMKEY_VOLUME_BOTH_PRESS,string(UBTEVENT_SYSTEMKEY_VOLUME_BOTH_PRESS)},
    {UBTMSG_SYSTEMKEY_NET_CONFIG,string(UBTEVENT_SYSTEMKEY_NET_CONFIG)},
    {UBTMSG_SYSTEMKEY_EXIT_NET_CONFIG,string(UBTEVENT_SYSTEMKEY_EXIT_NET_CONFIG)},
    {UBTMSG_FACTORY_RESET_EVENT,string(UBTEVENT_FACTORY_RESET_EVENT)},
    {UBTMSG_SYSTEMKEY_TOUCHED,string(UBTEVENT_SYSTEMKEY_TOUCHED)},
    /*
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_A,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_A)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_A,string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_A)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B1,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B1)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B1,string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B1)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B2,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B2)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B2,string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B2)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2,string(UBTEVENT_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2)},
    {UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3,string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3)},*/
    {UBTMSG_SYSTEMKEY_TOUCHED_HEAD,string(UBTEVENT_SYSTEMKEY_TOUCHED_HEAD)},
    {UBTMSG_SYSTEM_CLOCKALARM,string(UBTEVENT_SYSTEM_CLOCKALARM)},
    {UBTMSG_SYSTEMKEY_EVENT_PRESS,string(UBTEVENT_SYSTEMKEY_EVENT_PRESS)},
    {UBTMSG_SYSTEMKEY_EVENT_DOUBLE_PRESS,string(UBTEVENT_SYSTEMKEY_EVENT_DOUBLE_PRESS)},
    {UBTMSG_SYSTEMKEY_EVENT_RELEASE,string(UBTEVENT_SYSTEMKEY_EVENT_RELEASE)},
    {UBTMSG_SYSVOLUME_SETTING,string(UBTEVENT_SYSVOLUME_SETTING)},
    {UBTMSG_SYSTEM_STATUS_CHANGE,string(UBTEVENT_SYSTEM_STATUS_CHANGE)},
    {UBTMSG_GET_SPEAKER_STATUS,string(UBTEVENT_GET_SPEAKER_STATUS)},
    {UBTMSG_UBTREADAUTOUPDATESTATE,string(UBTEVENT_UBTREADAUTOUPDATESTATE)},
    {UBTMSG_UBTSETAUTOUPDATESTATE,string(UBTEVENT_UBTSETAUTOUPDATESTATE)},
    {UBTMSG_UBTREADAUTOUPDATEPROGRESS,string(UBTEVENT_UBTREADAUTOUPDATEPROGRESS)},
    {UBTMSG_UBTINSTALLING_UPDATE,string(UBTEVENT_UBTINSTALLING_UPDATE)},
    {UBTMSG_UBTINSTALLED_UPDATESUEECESS,string(UBTEVENT_UBTINSTALLED_UPDATESUEECESS)},
    {UBTMSG_NETWORKSTATE_CHANGED,string(UBTEVENT_NETWORKSTATE_CHANGED)}
};

unordered_map<string, UBTMSG> UBTMsgMapping::s_str2int_msg =
{
    {string(UBTEVENT_MSC_WAKEUP),UBTMSG_MSC_WAKEUP},
    {string(UBTEVENT_MSC_RECOGCMD_START),UBTMSG_MSC_RECOGCMD_START},
    {string(UBTEVENT_MSC_RECOGCMD_RESTART),UBTMSG_MSC_RECOGCMD_RESTART},
    {string(UBTEVENT_MSC_RECOGCMD_PARSING),UBTMSG_MSC_RECOGCMD_PARSING},
    {string(UBTEVENT_MSC_RECOGCMD_END),UBTMSG_MSC_RECOGCMD_END},
    {string(UBTEVENT_MSC_RECOGCMD_OFFLINERESULT),UBTMSG_MSC_RECOGCMD_OFFLINERESULT},
    {string(UBTEVENT_MSC_RECOGCMD_ONLINERESULT),UBTMSG_MSC_RECOGCMD_ONLINERESULT},
    {string(UBTEVENT_MSC_RECOGCMD_RESULT_DETAILS),UBTMSG_MSC_RECOGCMD_RESULT_DETAILS},
    {string(UBTEVENT_MSC_RECOGCMD_NORESULT),UBTMSG_MSC_RECOGCMD_NORESULT},
    {string(UBTEVENT_MSC_RECOGCMD_ERROR),UBTMSG_MSC_RECOGCMD_ERROR},
    {string(UBTEVENT_MSC_SEMANTIC_RESULT),UBTMSG_MSC_SEMANTIC_RESULT},
    {string(UBTEVENT_MSC_VAD_TIMEOUT),UBTMSG_MSC_VAD_TIMEOUT},
    {string(UBTEVENT_MSC_EXPECT_SPEECH_START),UBTMSG_MSC_EXPECT_SPEECH_START},
    {string(UBTEVENT_MSC_TTS_RECVDATA),UBTMSG_MSC_TTS_RECVDATA},
    {string(UBTEVENT_MSC_TTS_END),UBTMSG_MSC_TTS_END},
    {string(UBTEVENT_DINGDANG_MSC_TTS_FACE_EVENT),UBTMSG_DINGDANG_MSC_TTS_FACE_EVENT},
    {string(UBTEVENT_DINGDANG_MSC_TTS_FACE_END_EVENT),UBTMSG_DINGDANG_MSC_TTS_FACE_END_EVENT},
    {string(UBTEVENT_DINGDANG_MSC_WINDOW_EVENT),UBTMSG_DINGDANG_MSC_WINDOW_EVENT},
    {string(UBTEVENT_DINGDANG_MSC_PLAYMODE_EVENT),UBTMSG_DINGDANG_MSC_PLAYMODE_EVENT},
    {string(UBTEVENT_DINGDANG_MSC_SHUTDOWN),UBTMSG_DINGDANG_MSC_SHUTDOWN},
    {string(UBTEVENT_DINGDANG_MSC_SHOW_QRCODE),UBTMSG_DINGDANG_MSC_SHOW_QRCODE},
    {string(UBTEVENT_DINGDANG_MSC_MUTE),UBTMSG_DINGDANG_MSC_MUTE},
    {string(UBTEVENT_UBTAUDIO_ERROR),UBTMSG_UBTAUDIO_ERROR},
    {string(UBTEVENT_UBTAUDIO_PLAYER_NOTHING),UBTMSG_UBTAUDIO_PLAYER_NOTHING},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYSTART),UBTMSG_UBTAUDIO_URI_PLAYSTART},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYSTOP),UBTMSG_UBTAUDIO_URI_PLAYSTOP},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYPAUSE),UBTMSG_UBTAUDIO_URI_PLAYPAUSE},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYFINISH),UBTMSG_UBTAUDIO_URI_PLAYFINISH},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYRESUME),UBTMSG_UBTAUDIO_URI_PLAYRESUME},
    {string(UBTEVENT_UBTAUDIO_URI_PLAYPROGRESS),UBTMSG_UBTAUDIO_URI_PLAYPROGRESS},
    {string(UBTEVENT_UBTAUDIO_URI_DROP),UBTMSG_UBTAUDIO_URI_DROP},
    {string(UBTEVENT_UBTAUDIO_URI_FAILED),UBTMSG_UBTAUDIO_URI_FAILED},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYSTART),UBTMSG_UBTAUDIO_PROMPT_PLAYSTART},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYSTOP),UBTMSG_UBTAUDIO_PROMPT_PLAYSTOP},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYPAUSE),UBTMSG_UBTAUDIO_PROMPT_PLAYPAUSE},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYFINISH),UBTMSG_UBTAUDIO_PROMPT_PLAYFINISH},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYRESUME),UBTMSG_UBTAUDIO_PROMPT_PLAYRESUME},
    {string(UBTEVENT_UBTAUDIO_PROMPT_PLAYPROGRESS),UBTMSG_UBTAUDIO_PROMPT_PLAYPROGRESS},
    {string(UBTEVENT_UBTAUDIO_PROMPT_DROP),UBTMSG_UBTAUDIO_PROMPT_DROP},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYSTART),UBTMSG_UBTAUDIO_TTS_PLAYSTART},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYSTOP),UBTMSG_UBTAUDIO_TTS_PLAYSTOP},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYPAUSE),UBTMSG_UBTAUDIO_TTS_PLAYPAUSE},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYFINISH),UBTMSG_UBTAUDIO_TTS_PLAYFINISH},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYRESUME),UBTMSG_UBTAUDIO_TTS_PLAYRESUME},
    {string(UBTEVENT_UBTAUDIO_TTS_PLAYPROGRESS),UBTMSG_UBTAUDIO_TTS_PLAYPROGRESS},
    {string(UBTEVENT_UBTAUDIO_TTS_DROP),UBTMSG_UBTAUDIO_TTS_DROP},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYSTART),UBTMSG_UBTAUDIO_BT_PLAYSTART},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYSTOP),UBTMSG_UBTAUDIO_BT_PLAYSTOP},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYPAUSE),UBTMSG_UBTAUDIO_BT_PLAYPAUSE},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYFINISH),UBTMSG_UBTAUDIO_BT_PLAYFINISH},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYRESUME),UBTMSG_UBTAUDIO_BT_PLAYRESUME},
    {string(UBTEVENT_UBTAUDIO_BT_PLAYPROGRESS),UBTMSG_UBTAUDIO_BT_PLAYPROGRESS},
    {string(UBTEVENT_UBTAUDIO_BT_DROP),UBTMSG_UBTAUDIO_BT_DROP},
    {string(UBTEVENT_UBTAUDIO_RECORD_RECVDATA),UBTMSG_UBTAUDIO_RECORD_RECVDATA},
    {string(UBTEVENT_UBTAUDIO_EXPERSSION_DIR),UBTMSG_UBTAUDIO_EXPERSSION_DIR},
    {string(UBTEVENT_UBTAUDIO_RECOGNISE_TIMEOUT),UBTMSG_UBTAUDIO_RECOGNISE_TIMEOUT},
    {string(UBTEVENT_UBTAUDIO_CLOSED_BT_DIR),UBTMSG_UBTAUDIO_CLOSED_BT_DIR},
    {string(UBTEVENT_UBTAUDIO_OPENNED_BT_DIR),UBTMSG_UBTAUDIO_OPENNED_BT_DIR},
    {string(UBTEVENT_UBTAUDIO_SHOW_BATTERY_DIR),UBTMSG_UBTAUDIO_SHOW_BATTERY_DIR},
    {string(UBTEVENT_UBTAUDIO_NET_CONFIG_DIR),UBTMSG_UBTAUDIO_NET_CONFIG_DIR},
    {string(UBTEVENT_UBTAUDIO_WAKE_UP_DIR),UBTMSG_UBTAUDIO_WAKE_UP_DIR},
    {string(UBTEVENT_UBTAUDIO_ALERT),UBTMSG_UBTAUDIO_ALERT},
    {string(UBTEVENT_UBTAUDIO_COIN),UBTMSG_UBTAUDIO_COIN},
    {string(UBTEVENT_ROBOT_FALLED_DOWN),UBTMSG_ROBOT_FALLED_DOWN},
    {string(UBTEVENT_ROBOT_FALLED_DOWN_SOFT),UBTMSG_ROBOT_FALLED_DOWN_SOFT},
    {string(UBTEVENT_ROBOT_TILT_EVENT),UBTMSG_ROBOT_TILT_EVENT},
    {string(UBTEVENT_ALERT_ALARM_TIMEOUT_START),UBTMSG_ALERT_ALARM_TIMEOUT_START},
    {string(UBTEVENT_ALERT_ALARM_TIMEOUT_END),UBTMSG_ALERT_ALARM_TIMEOUT_END},
    {string(UBTEVENT_ALERT_ALARM_REAL_START),UBTMSG_ALERT_ALARM_REAL_START},
    //{string(UBTEVENT_ALERT_ALARM_INTERRUPT_STOP_FLAG),UBTMSG_ALERT_ALARM_INTERRUPT_STOP_FLAG},
    //{string(UBTEVENT_ALERT_ALARM_NORMAL_FINISH_FLAG),UBTMSG_ALERT_ALARM_NORMAL_FINISH_FLAG},
    {string(UBTEVENT_BATTERY_LOWPOWER),UBTMSG_BATTERY_LOWPOWER},
    {string(UBTEVENT_BATTERY_NORMALPOWER),UBTMSG_BATTERY_NORMALPOWER},
    {string(UBTEVENT_BATTERY_CHARGINE),UBTMSG_BATTERY_CHARGINE},
    {string(UBTEVENT_BATTERY_FULLCHARGED),UBTMSG_BATTERY_FULLCHARGED},
    {string(UBTEVENT_BATTERY_DISCHARGINE),UBTMSG_BATTERY_DISCHARGINE},
    {string(UBTEVENT_BATTERY_VALUE_CHANGE),UBTMSG_BATTERY_VALUE_CHANGE},
    {string(UBTEVENT_BATTERY_STAT_CHANGE),UBTMSG_BATTERY_STAT_CHANGE},
    {string(UBTEVENT_BATTERY_STANDBY_MODE),UBTMSG_BATTERY_STANDBY_MODE},
    {string(UBTEVENT_BATTERY_NORMAL_MODE),UBTMSG_BATTERY_NORMAL_MODE},
    {string(UBTEVENT_BLUETOOTH_LINEOFF),UBTMSG_BLUETOOTH_LINEOFF},
    {string(UBTEVENT_BLUETOOTH_LINEON),UBTMSG_BLUETOOTH_LINEON},
    {string(UBTEVENT_BLUETOOTH_RECEIVEDATA),UBTMSG_BLUETOOTH_RECEIVEDATA},
    {string(UBTEVENT_BLUETOOTH_DEVICE_OPEN),UBTMSG_BLUETOOTH_DEVICE_OPEN},
    {string(UBTEVENT_BLUETOOTH_DEVICE_CLOSE),UBTMSG_BLUETOOTH_DEVICE_CLOSE},
    {string(UBTEVENT_INITIAL_BOOT_SHOWQR_ENTER),UBTMSG_INITIAL_BOOT_SHOWQR_ENTER},
    {string(UBTEVENT_INITIAL_BOOT_SHOWQR_LEAVE),UBTMSG_INITIAL_BOOT_SHOWQR_LEAVE},
    {string(UBTEVENT_INITIAL_BOOT_ENTER_NETWORKCONFIG),UBTMSG_INITIAL_BOOT_ENTER_NETWORKCONFIG},
    {string(UBTEVENT_INITIAL_BOOT_LEAVE_NETWORKCONFIG),UBTMSG_INITIAL_BOOT_LEAVE_NETWORKCONFIG},
    {string(UBTEVENT_INITIAL_BOOT_INTRADUCTION_ENTER),UBTMSG_INITIAL_BOOT_INTRADUCTION_ENTER},
    {string(UBTEVENT_INITIAL_BOOT_RE_ENTER),UBTMSG_INITIAL_BOOT_RE_ENTER},
    {string(UBTEVENT_INITIAL_BOOT_ENTER),UBTMSG_INITIAL_BOOT_ENTER},
    {string(UBTEVENT_INITIAL_BOOT_LEAVE),UBTMSG_INITIAL_BOOT_LEAVE},
    {string(UBTEVENT_ALERT_REMINDER_TIMEOUT_START),UBTMSG_ALERT_REMINDER_TIMEOUT_START},
    {string(UBTEVENT_ALERT_REMINDER_TIMEOUT_END),UBTMSG_ALERT_REMINDER_TIMEOUT_END},
    {string(UBTEVENT_ALERT_REMINDER_REAL_START),UBTMSG_ALERT_REMINDER_REAL_START},
    {string(UBTEVENT_ALERT_REMINDER_TIMEOUT_INTERRUPT),UBTMSG_ALERT_REMINDER_TIMEOUT_INTERRUPT},
    {string(UBTEVENT_SYSTEMKEY_POWERKEY_LONGPRESS),UBTMSG_SYSTEMKEY_POWERKEY_LONGPRESS},
    {string(UBTEVENT_SYSTEMKEY_POWER_ONECLICK_EVENT),UBTMSG_SYSTEMKEY_POWER_ONECLICK_EVENT},
    {string(UBTEVENT_SYSTEMKEY_INSERTCOIN),UBTMSG_SYSTEMKEY_INSERTCOIN},
    {string(UBTEVENT_SYSTEMKEY_VOLUMEUP_PRESS),UBTMSG_SYSTEMKEY_VOLUMEUP_PRESS},
    {string(UBTEVENT_SYSTEMKEY_VOLUMEUP_RELEASE),UBTMSG_SYSTEMKEY_VOLUMEUP_RELEASE},
    {string(UBTEVENT_SYSTEMKEY_VOLUMEDOWN_PRESS),UBTMSG_SYSTEMKEY_VOLUMEDOWN_PRESS},
    {string(UBTEVENT_SYSTEMKEY_VOLUMEDOWN_RELEASE),UBTMSG_SYSTEMKEY_VOLUMEDOWN_RELEASE},
    {string(UBTEVENT_SYSTEMKEY_VOLUME_BOTH_PRESS),UBTMSG_SYSTEMKEY_VOLUME_BOTH_PRESS},
    {string(UBTEVENT_SYSTEMKEY_NET_CONFIG),UBTMSG_SYSTEMKEY_NET_CONFIG},
    {string(UBTEVENT_SYSTEMKEY_EXIT_NET_CONFIG),UBTMSG_SYSTEMKEY_EXIT_NET_CONFIG},
    {string(UBTEVENT_FACTORY_RESET_EVENT),UBTMSG_FACTORY_RESET_EVENT},
    {string(UBTEVENT_SYSTEMKEY_TOUCHED),UBTMSG_SYSTEMKEY_TOUCHED},
    /*
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_A),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_A},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_A),UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_A},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B1),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B1},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B1),UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B1},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B2),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B2},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B2),UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B2},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2),UBTMSG_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2},
    {string(UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3),UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3},*/
    {string(UBTEVENT_SYSTEMKEY_TOUCHED_HEAD),UBTMSG_SYSTEMKEY_TOUCHED_HEAD},
    {string(UBTEVENT_SYSTEM_CLOCKALARM),UBTMSG_SYSTEM_CLOCKALARM},
    {string(UBTEVENT_SYSTEMKEY_EVENT_PRESS),UBTMSG_SYSTEMKEY_EVENT_PRESS},
    {string(UBTEVENT_SYSTEMKEY_EVENT_DOUBLE_PRESS),UBTMSG_SYSTEMKEY_EVENT_DOUBLE_PRESS},
    {string(UBTEVENT_SYSTEMKEY_EVENT_RELEASE),UBTMSG_SYSTEMKEY_EVENT_RELEASE},
    {string(UBTEVENT_SYSVOLUME_SETTING),UBTMSG_SYSVOLUME_SETTING},
    {string(UBTEVENT_SYSTEM_STATUS_CHANGE),UBTMSG_SYSTEM_STATUS_CHANGE},
    {string(UBTEVENT_GET_SPEAKER_STATUS),UBTMSG_GET_SPEAKER_STATUS},
    {string(UBTEVENT_UBTREADAUTOUPDATESTATE),UBTMSG_UBTREADAUTOUPDATESTATE},
    {string(UBTEVENT_UBTSETAUTOUPDATESTATE),UBTMSG_UBTSETAUTOUPDATESTATE},
    {string(UBTEVENT_UBTREADAUTOUPDATEPROGRESS),UBTMSG_UBTREADAUTOUPDATEPROGRESS},
    {string(UBTEVENT_UBTINSTALLING_UPDATE),UBTMSG_UBTINSTALLING_UPDATE},
    {string(UBTEVENT_UBTINSTALLED_UPDATESUEECESS),UBTMSG_UBTINSTALLED_UPDATESUEECESS},
    {string(UBTEVENT_NETWORKSTATE_CHANGED),UBTMSG_NETWORKSTATE_CHANGED}
};

UBTMSG UBTMsgMapping::msg_str2int(const string& msg)
{
    auto v = s_str2int_msg.find(msg);
    if (v != s_str2int_msg.end())
        return v->second;
    return UBTMSG_NONE;
}

string UBTMsgMapping::msg_int2str(UBTMSG msg)
{
    auto v = s_int2str_msg.find(msg);
    if (v != s_int2str_msg.end())
        return v->second;
    return "";
}

/*
int UBTMsgMapping::StringToInt(const string& msg)
{
    if (msg == UBTEVENT_MSC_TTS_RECVDATA)
    return UBTMSG_MSC_TTS_RECVDATA;
    else if (msg == UBTEVENT_MSC_TTS_END)
    return UBTMSG_MSC_TTS_END;
    else if (msg == UBTEVENT_MSC_WAKEUP)
    return UBTMSG_MSC_WAKEUP;
    else if (msg == UBTEVENT_MSC_RECOGCMD_START)
    return UBTMSG_MSC_RECOGCMD_START;
    else if (msg == UBTEVENT_MSC_RECOGCMD_RESTART)
    return UBTMSG_MSC_RECOGCMD_RESTART;
    else if (msg == UBTEVENT_MSC_EXPECT_SPEECH_START)
    return UBTMSG_MSC_EXPECT_SPEECH_START;
    else if (msg == UBTEVENT_MSC_RECOGCMD_PARSING)
    return UBTMSG_MSC_RECOGCMD_PARSING;
    else if (msg == UBTEVENT_MSC_RECOGCMD_END)
    return UBTMSG_MSC_RECOGCMD_END;
    else if (msg == UBTEVENT_MSC_RECOGCMD_OFFLINERESULT)
    return UBTMSG_MSC_RECOGCMD_OFFLINERESULT;
    else if (msg == UBTEVENT_MSC_RECOGCMD_ONLINERESULT)
    return UBTMSG_MSC_RECOGCMD_ONLINERESULT;
    else if (msg == UBTEVENT_MSC_RECOGCMD_RESULT_DETAILS)
    return UBTMSG_MSC_RECOGCMD_RESULT_DETAILS;
    else if (msg == UBTEVENT_MSC_RECOGCMD_NORESULT)
    return UBTMSG_MSC_RECOGCMD_NORESULT;
    else if (msg == UBTEVENT_MSC_RECOGCMD_ERROR)
    return UBTMSG_MSC_RECOGCMD_ERROR;
    else if (msg == UBTEVENT_MSC_VAD_TIMEOUT)
    return UBTMSG_MSC_VAD_TIMEOUT;
    else if (msg == UBTEVENT_DINGDANG_MSC_TTS_FACE_EVENT)
    return UBTMSG_DINGDANG_MSC_TTS_FACE_EVENT;
    else if (msg == UBTEVENT_DINGDANG_MSC_TTS_FACE_END_EVENT)
    return UBTMSG_DINGDANG_MSC_TTS_FACE_END_EVENT;
    else if (msg == UBTEVENT_DINGDANG_MSC_WINDOW_EVENT)
    return UBTMSG_DINGDANG_MSC_WINDOW_EVENT;
    else if (msg == UBTEVENT_DINGDANG_MSC_PLAYMODE_EVENT)
    return UBTMSG_DINGDANG_MSC_PLAYMODE_EVENT;
    else if (msg == UBTEVENT_DINGDANG_MSC_SHUTDOWN)
    return UBTMSG_DINGDANG_MSC_SHUTDOWN;
    else if (msg == UBTEVENT_DINGDANG_MSC_SHOW_QRCODE)
    return UBTMSG_DINGDANG_MSC_SHOW_QRCODE;
    else if (msg == UBTEVENT_DINGDANG_MSC_MUTE)
    return UBTMSG_DINGDANG_MSC_MUTE;
    else if (msg == UBTEVENT_UBTAUDIO_ERROR)
    return UBTMSG_UBTAUDIO_ERROR;
    else if (msg == UBTEVENT_UBTAUDIO_PLAYER_NOTHING)
    return UBTMSG_UBTAUDIO_PLAYER_NOTHING;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYSTART)
    return UBTMSG_UBTAUDIO_URI_PLAYSTART;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYSTOP)
    return UBTMSG_UBTAUDIO_URI_PLAYSTOP;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYPAUSE)
    return UBTMSG_UBTAUDIO_URI_PLAYPAUSE;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYFINISH)
    return UBTMSG_UBTAUDIO_URI_PLAYFINISH;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYRESUME)
    return UBTMSG_UBTAUDIO_URI_PLAYRESUME;
    else if (msg == UBTEVENT_UBTAUDIO_URI_PLAYPROGRESS)
    return UBTMSG_UBTAUDIO_URI_PLAYPROGRESS;
    else if (msg == UBTEVENT_UBTAUDIO_URI_DROP)
    return UBTMSG_UBTAUDIO_URI_DROP;
    else if (msg == UBTEVENT_UBTAUDIO_URI_FAILED)
    return UBTMSG_UBTAUDIO_URI_FAILED;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYSTART)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYSTART;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYSTOP)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYSTOP;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYPAUSE)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYPAUSE;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYFINISH)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYFINISH;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYRESUME)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYRESUME;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_PLAYPROGRESS)
    return UBTMSG_UBTAUDIO_PROMPT_PLAYPROGRESS;
    else if (msg == UBTEVENT_UBTAUDIO_PROMPT_DROP)
    return UBTMSG_UBTAUDIO_PROMPT_DROP;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYSTART)
    return UBTMSG_UBTAUDIO_TTS_PLAYSTART;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYSTOP)
    return UBTMSG_UBTAUDIO_TTS_PLAYSTOP;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYPAUSE)
    return UBTMSG_UBTAUDIO_TTS_PLAYPAUSE;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYFINISH)
    return UBTMSG_UBTAUDIO_TTS_PLAYFINISH;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYRESUME)
    return UBTMSG_UBTAUDIO_TTS_PLAYRESUME;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_PLAYPROGRESS)
    return UBTMSG_UBTAUDIO_TTS_PLAYPROGRESS;
    else if (msg == UBTEVENT_UBTAUDIO_TTS_DROP)
    return UBTMSG_UBTAUDIO_TTS_DROP;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYSTART)
    return UBTMSG_UBTAUDIO_BT_PLAYSTART;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYSTOP)
    return UBTMSG_UBTAUDIO_BT_PLAYSTOP;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYPAUSE)
    return UBTMSG_UBTAUDIO_BT_PLAYPAUSE;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYFINISH)
    return UBTMSG_UBTAUDIO_BT_PLAYFINISH;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYRESUME)
    return UBTMSG_UBTAUDIO_BT_PLAYRESUME;
    else if (msg == UBTEVENT_UBTAUDIO_BT_PLAYPROGRESS)
    return UBTMSG_UBTAUDIO_BT_PLAYPROGRESS;
    else if (msg == UBTEVENT_UBTAUDIO_BT_DROP)
    return UBTMSG_UBTAUDIO_BT_DROP;
    else if (msg == UBTEVENT_UBTAUDIO_RECORD_RECVDATA)
    return UBTMSG_UBTAUDIO_RECORD_RECVDATA;
    else if (msg == UBTEVENT_UBTAUDIO_EXPERSSION_DIR)
    return UBTMSG_UBTAUDIO_EXPERSSION_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_RECOGNISE_TIMEOUT)
    return UBTMSG_UBTAUDIO_RECOGNISE_TIMEOUT;
    else if (msg == UBTEVENT_UBTAUDIO_CLOSED_BT_DIR)
    return UBTMSG_UBTAUDIO_CLOSED_BT_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_OPENNED_BT_DIR)
    return UBTMSG_UBTAUDIO_OPENNED_BT_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_SHOW_BATTERY_DIR)
    return UBTMSG_UBTAUDIO_SHOW_BATTERY_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_NET_CONFIG_DIR)
    return UBTMSG_UBTAUDIO_NET_CONFIG_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_WAKE_UP_DIR)
    return UBTMSG_UBTAUDIO_WAKE_UP_DIR;
    else if (msg == UBTEVENT_UBTAUDIO_ALERT)
    return UBTMSG_UBTAUDIO_ALERT;
    else if (msg == UBTEVENT_UBTAUDIO_COIN)
    return UBTMSG_UBTAUDIO_COIN;
    else if (msg == UBTEVENT_ROBOT_FALLED_DOWN)
    return UBTMSG_ROBOT_FALLED_DOWN;
    else if (msg == UBTEVENT_ROBOT_FALLED_DOWN_SOFT)
    return UBTMSG_ROBOT_FALLED_DOWN_SOFT;
    else if (msg == UBTEVENT_ROBOT_TILT_EVENT)
    return UBTMSG_ROBOT_TILT_EVENT;
    else if (msg == UBTEVENT_ALERT_ALARM_TIMEOUT_START)
    return UBTMSG_ALERT_ALARM_TIMEOUT_START;
    else if (msg == UBTEVENT_ALERT_ALARM_TIMEOUT_END)
    return UBTMSG_ALERT_ALARM_TIMEOUT_END;
    else if (msg == UBTEVENT_ALERT_ALARM_REAL_START)
    return UBTMSG_ALERT_ALARM_REAL_START;
    else if (msg == UBTEVENT_ALERT_ALARM_INTERRUPT_STOP_FLAG)
    return UBTMSG_ALERT_ALARM_INTERRUPT_STOP_FLAG;
    else if (msg == UBTEVENT_ALERT_ALARM_NORMAL_FINISH_FLAG)
    return UBTMSG_ALERT_ALARM_NORMAL_FINISH_FLAG;
    else if (msg == UBTEVENT_BATTERY_LOWPOWER)
    return UBTMSG_BATTERY_LOWPOWER;
    else if (msg == UBTEVENT_BATTERY_NORMALPOWER)
    return UBTMSG_BATTERY_NORMALPOWER;
    else if (msg == UBTEVENT_BATTERY_CHARGINE)
    return UBTMSG_BATTERY_CHARGINE;
    else if (msg == UBTEVENT_BATTERY_FULLCHARGED)
    return UBTMSG_BATTERY_FULLCHARGED;
    else if (msg == UBTEVENT_BATTERY_DISCHARGINE)
    return UBTMSG_BATTERY_DISCHARGINE;
    else if (msg == UBTEVENT_BATTERY_VALUE_CHANGE)
    return UBTMSG_BATTERY_VALUE_CHANGE;
    else if (msg == UBTEVENT_BATTERY_STAT_CHANGE)
    return UBTMSG_BATTERY_STAT_CHANGE;
    else if (msg == UBTEVENT_BATTERY_STANDBY_MODE)
    return UBTMSG_BATTERY_STANDBY_MODE;
    else if (msg == UBTEVENT_BATTERY_NORMAL_MODE)
    return UBTMSG_BATTERY_NORMAL_MODE;
    else if (msg == UBTEVENT_BLUETOOTH_LINEOFF)
    return UBTMSG_BLUETOOTH_LINEOFF;
    else if (msg == UBTEVENT_BLUETOOTH_LINEON)
    return UBTMSG_BLUETOOTH_LINEON;
    else if (msg == UBTEVENT_BLUETOOTH_RECEIVEDATA)
    return UBTMSG_BLUETOOTH_RECEIVEDATA;
    else if (msg == UBTEVENT_BLUETOOTH_DEVICE_OPEN)
    return UBTMSG_BLUETOOTH_DEVICE_OPEN;
    else if (msg == UBTEVENT_BLUETOOTH_DEVICE_CLOSE)
    return UBTMSG_BLUETOOTH_DEVICE_CLOSE;
    else if (msg == UBTEVENT_INITIAL_BOOT_SHOWQR_ENTER)
    return UBTMSG_INITIAL_BOOT_SHOWQR_ENTER;
    else if (msg == UBTEVENT_INITIAL_BOOT_SHOWQR_LEAVE)
    return UBTMSG_INITIAL_BOOT_SHOWQR_LEAVE;
    else if (msg == UBTEVENT_INITIAL_BOOT_ENTER_NETWORKCONFIG)
    return UBTMSG_INITIAL_BOOT_ENTER_NETWORKCONFIG;
    else if (msg == UBTEVENT_INITIAL_BOOT_LEAVE_NETWORKCONFIG)
    return UBTMSG_INITIAL_BOOT_LEAVE_NETWORKCONFIG;
    else if (msg == UBTEVENT_INITIAL_BOOT_INTRADUCTION_ENTER)
    return UBTMSG_INITIAL_BOOT_INTRADUCTION_ENTER;
    else if (msg == UBTEVENT_INITIAL_BOOT_RE_ENTER)
    return UBTMSG_INITIAL_BOOT_RE_ENTER;
    else if (msg == UBTEVENT_INITIAL_BOOT_ENTER)
    return UBTMSG_INITIAL_BOOT_ENTER;
    else if (msg == UBTEVENT_INITIAL_BOOT_LEAVE)
    return UBTMSG_INITIAL_BOOT_LEAVE;
    else if (msg == UBTEVENT_ALERT_REMINDER_TIMEOUT_START)
    return UBTMSG_ALERT_REMINDER_TIMEOUT_START;
    else if (msg == UBTEVENT_ALERT_REMINDER_TIMEOUT_END)
    return UBTMSG_ALERT_REMINDER_TIMEOUT_END;
    else if (msg == UBTEVENT_ALERT_REMINDER_REAL_START)
    return UBTMSG_ALERT_REMINDER_REAL_START;
    else if (msg == UBTEVENT_ALERT_REMINDER_TIMEOUT_INTERRUPT)
    return UBTMSG_ALERT_REMINDER_TIMEOUT_INTERRUPT;
    else if (msg == UBTEVENT_SYSTEMKEY_POWERKEY_LONGPRESS)
    return UBTMSG_SYSTEMKEY_POWERKEY_LONGPRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_POWER_ONECLICK_EVENT)
    return UBTMSG_SYSTEMKEY_POWER_ONECLICK_EVENT;
    else if (msg == UBTEVENT_SYSTEMKEY_INSERTCOIN)
    return UBTMSG_SYSTEMKEY_INSERTCOIN;
    else if (msg == UBTEVENT_SYSTEMKEY_VOLUMEUP_PRESS)
    return UBTMSG_SYSTEMKEY_VOLUMEUP_PRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_VOLUMEUP_RELEASE)
    return UBTMSG_SYSTEMKEY_VOLUMEUP_RELEASE;
    else if (msg == UBTEVENT_SYSTEMKEY_VOLUMEDOWN_PRESS)
    return UBTMSG_SYSTEMKEY_VOLUMEDOWN_PRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_VOLUMEDOWN_RELEASE)
    return UBTMSG_SYSTEMKEY_VOLUMEDOWN_RELEASE;
    else if (msg == UBTEVENT_SYSTEMKEY_VOLUME_BOTH_PRESS)
    return UBTMSG_SYSTEMKEY_VOLUME_BOTH_PRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_NET_CONFIG)
    return UBTMSG_SYSTEMKEY_NET_CONFIG;
    else if (msg == UBTEVENT_SYSTEMKEY_EXIT_NET_CONFIG)
    return UBTMSG_SYSTEMKEY_EXIT_NET_CONFIG;
    else if (msg == UBTEVENT_FACTORY_RESET_EVENT)
    return UBTMSG_FACTORY_RESET_EVENT;
    else if (msg == UBTEVENT_SYSTEMKEY_TOUCHED)
    return UBTMSG_SYSTEMKEY_TOUCHED;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_A)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_A;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_A)
    return UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_A;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B1)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B1;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B1)
    return UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B1;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_B2)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_B2;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_SCRATCH_B2)
    return UBTMSG_SYSTEMKEY_SUBTYPE_SCRATCH_B2;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2)
    return UBTMSG_SYSTEMKEY_SUBTYPE_MIXED_TOUCH_B1B2;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH__B1B2_AT_SAME_TIME;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_2;
    else if (msg == UBTEVENT_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3)
    return UBTMSG_SYSTEMKEY_SUBTYPE_TOUCH_STAGE_3;
    else if (msg == UBTEVENT_SYSTEMKEY_TOUCHED_HEAD)
    return UBTMSG_SYSTEMKEY_TOUCHED_HEAD;
    else if (msg == UBTEVENT_SYSTEM_CLOCKALARM)
    return UBTMSG_SYSTEM_CLOCKALARM;
    else if (msg == UBTEVENT_SYSTEMKEY_EVENT_PRESS)
    return UBTMSG_SYSTEMKEY_EVENT_PRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_EVENT_DOUBLE_PRESS)
    return UBTMSG_SYSTEMKEY_EVENT_DOUBLE_PRESS;
    else if (msg == UBTEVENT_SYSTEMKEY_EVENT_RELEASE)
    return UBTMSG_SYSTEMKEY_EVENT_RELEASE;
    else if (msg == UBTEVENT_SYSVOLUME_SETTING)
    return UBTMSG_SYSVOLUME_SETTING;
    else if (msg == UBTEVENT_SYSTEM_STATUS_CHANGE)
    return UBTMSG_SYSTEM_STATUS_CHANGE;
    else if (msg == UBTEVENT_GET_SPEAKER_STATUS)
    return UBTMSG_GET_SPEAKER_STATUS;
    else if (msg == UBTEVENT_UBTREADAUTOUPDATESTATE)
    return UBTMSG_UBTREADAUTOUPDATESTATE;
    else if (msg == UBTEVENT_UBTSETAUTOUPDATESTATE)
    return UBTMSG_UBTSETAUTOUPDATESTATE;
    else if (msg == UBTEVENT_UBTREADAUTOUPDATEPROGRESS)
    return UBTMSG_UBTREADAUTOUPDATEPROGRESS;
    else if (msg == UBTEVENT_UBTINSTALLING_UPDATE)
    return UBTMSG_UBTINSTALLING_UPDATE;
    else if (msg == UBTEVENT_UBTINSTALLED_UPDATESUEECESS)
    return UBTMSG_UBTINSTALLED_UPDATESUEECESS;
    else if (msg == UBTEVENT_NETWORKSTATE_CHANGED)
    return UBTMSG_NETWORKSTATE_CHANGED;
}
*/

