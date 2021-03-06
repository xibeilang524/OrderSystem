#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>

#define   BGN_RESD_MSG		     0x23	 //"#":起始符(0x23)
#define   END_RESD_MSG           0x2A  	 //"*":结束符(0x2A)

/*数据发送解析式的宏定义*/
#define PROTOCOL_BASIC_SIZE 	 0x05

#define PROTOCOL_FULL_CMD   	 0x00
#define PROTOCOL_ZERO_LEN        0x00
#define PROTOCOL_FULL_DATA       0x00
#define DATA_TO_ASCII            0x30   //发送数据时数字到ASCII码的基数0

/*默认数据类型宏定义*/
#define MSG_EMPTY_DATA           ""    //空数据
#define MSG_LEN                  5     //默认数据长度
#define MSG_EMPTY_MODEL          0x00  //默认设备名
#define MSG_EMPTY_MODEL_CMD      0x00  //默认设备命令


//消息帧头信息标志
//消息帧头信息标志
enum MessageHeadInfo{
    BEG_TABLE = 0,                      //开台
    ORDER_DISH,                         //点菜
    ORDER_OK,                           //点菜确认
    HURRY_MENU,                         //催菜
    ADD_MENU,                           //加菜
    RETURN_MENU,                        //退菜
    MENU_ACCOUNT ,                      //结账
    ACCOUNT_OK,                         //结账成功
    LACK_MENU,                          //缺菜
    FINISH_MENU,                        //完菜
    MIDIFY_MENU_INFO,                   //修改菜谱信息
    ADD_NEW_MENU_INFO,                  //添加新的菜谱
    DELETE_MENU_INFO,                   //删除菜谱信息
};

enum MessageType{
    TABLE_ID = 0x01,                    //台号
    MENU_NAME,                          //菜名
};

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = 0);

Q_SIGNALS:

public Q_SLOTS:

private:
    void initData();

public:
    void packSendData(quint8 flag, const QString &data);
    QByteArray sendData();

private:
    quint8 m_sendBegin;             //帧头
    quint8 m_protocolLen;           //信息长度
    quint8 m_flag;                  //信息标识(手持端和厨房端)
    QString m_data;                 //数据
    quint8 m_sendEnd;               //帧尾
};

#endif // PROTOCOL_H
