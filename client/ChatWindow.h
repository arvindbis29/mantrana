#pragma once

#include <QMainWindow>
#include "ChatConnection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChatWindow(ChatConnection *connection, QWidget *parent = nullptr);
    ~ChatWindow() override;

    void insertMessage(const QString &message) const;
    private slots:

    void on_send_clicked();
    void on_message_returnPressed();
    void on_message_textChanged(const QString &text);


private:
    
    void onChatMessage(const QJsonObject &data);
    void onErrorMessage(const QJsonObject &data);
    ChatConnection *connection;

    Ui::ChatWindow *ui;
};

