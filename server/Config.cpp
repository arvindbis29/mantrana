#include "Config.h"

Config::Config(QString name, QObject *parent): filename(std::move(name)), QObject(parent)
{
    Config::load();

    const char* port = qgetenv("PORT").data();

    std::stringstream s(port);

    unsigned int port_quint16;
    s >> port_quint16;

    webSocketPort = static_cast<unsigned short>(port_quint16);
}

QJsonObject Config::toJson() const
{
    QJsonObject json;
    json["webSocketPort"] = Config::webSocketPort;
    json["ip"] = Config::ip;

    return json;
}

void Config::fromJson(const QJsonObject &json)
{
    Config::webSocketPort = json["webSocketPort"].toInt();
    Config::ip = json["ip"].toString();
}

void Config::load()
{
    QFile loadFile(filename);

    // If file cannot be opened - create it
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open config file. Generating new...");
        Config::save();
        return;
    }

    QByteArray configBinary = loadFile.readAll();
    auto loadDocument = QJsonDocument::fromJson(configBinary);
    Config::fromJson(loadDocument.object());
}

void Config::save() const
{
    QFile saveFile(filename);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't save config.");
        return;
    }

    // Saves default config
    QJsonDocument saveDocument(Config::toJson());
    saveFile.write(saveDocument.toJson());
}


