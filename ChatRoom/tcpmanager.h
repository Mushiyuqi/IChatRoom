#pragma once
#include <QTcpSocket>
#include <QObject>
#include "global.h"

class SearchInfo;

class TcpManager:public QObject
{
    Q_OBJECT
public:
    ~TcpManager();
    TcpManager(const TcpManager&) = delete;
    TcpManager& operator=(const TcpManager&) = delete;

    static TcpManager& GetInstance();

private:
    TcpManager();

    void InitHandlers();
    void HandleMsg(ReqId id, int len, QByteArray data);
    QTcpSocket m_socket;
    QString m_host;
    uint16_t m_port;
    QByteArray m_buffer;
    bool m_b_recv_pending;
    quint16 m_message_id;
    quint16 m_message_len;
    QMap<ReqId, std::function<void(ReqId id, int len, QByteArray data)>> m_handlers;

public slots:
    void slot_tcp_connect(ServerInfo);
    void slot_tcp_disconnect();
    void slot_tcp_send_data(ReqId reqId, QString data);
signals:
    void sig_con_success(bool b_success);
    void sig_login_failed(int);
    void sig_switch_chatdlg();
    void sig_user_search(std::shared_ptr<SearchInfo>);
};

