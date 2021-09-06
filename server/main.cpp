#include <QCoreApplication>//non GUI applications
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QResource>

#include "Config.h"
#include "ChatWebSocketListener.h"

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);

    auto *config = new Config("config/server.json");

    auto *listener = new ChatWebSocketListener(config);
    listener->start();

    return QCoreApplication::exec();
}