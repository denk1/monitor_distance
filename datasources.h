#ifndef DATASOURCES_H
#define DATASOURCES_H
#include <thread>
#include <QJsonObject>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client;

QJsonObject get_object_json_from_str(QString& in);

class DataSources
{
public:
    DataSources();
    ~DataSources();
private:
    //main loop

    void do_session();

    friend void on_message(websocketpp::connection_hdl, client::message_ptr msg);

    QJsonObject currJsonObj;
    std::thread runner;
};

#endif // DATASOURCES_H
