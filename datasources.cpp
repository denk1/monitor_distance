#include <iostream>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <functional>
#include <chrono>
#include <QDebug>
#include <QJsonDocument>
#include "datasources.h"
#include "obstaclespace.h"


QJsonObject get_object_json_from_str(QString &inStr)
{
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(inStr.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << Qt::endl;
        }
    } else
    {
        qDebug() << "Invalid JSON...\n" << inStr << Qt::endl;
    }

    return obj;
}


void on_message(websocketpp::connection_hdl, client::message_ptr msg) {
    qDebug() << QString::fromStdString(msg->get_payload()) << Qt::endl;
    QString qStrMsg = QString::fromStdString(msg->get_payload());
    ObstacleSpace::getInstance().setObstacles(get_object_json_from_str(qStrMsg));
}


DataSources::DataSources() : runner(std::bind(&DataSources::do_session, this))
{
    qDebug() << "DataSources ctor" << Qt::endl;
}


DataSources::~DataSources()
{
    runner.detach();
}

void DataSources::do_session()
{
    client c;

    std::string uri = "ws://localhost:8765";

    try {
        // Set logging to be pretty verbose (everything except message payloads)
        c.set_access_channels(websocketpp::log::alevel::all);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload |
                                websocketpp::log::alevel::control |
                                websocketpp::log::alevel::frame_header |
                                websocketpp::log::alevel::connect |
                                websocketpp::log::alevel::disconnect );
        c.set_error_channels(websocketpp::log::elevel::all);

        // Initialize ASIO
        c.init_asio();

        // Register our message handler
        c.set_message_handler(&on_message);

        websocketpp::lib::error_code ec;
        client::connection_ptr con = c.get_connection(uri, ec);
        if (ec) {
            throw;
        }

        // Note that connect here only requests a connection. No network messages are
        // exchanged until the event loop starts running in the next line.
        c.connect(con);

        // Start the ASIO io_service run loop
        // this will cause a single connection to be made to the server. c.run()
        // will exit when this connection is closed.
        c.run();
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    }
}

