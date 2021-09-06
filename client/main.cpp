#include "ChatWindow.h"
#include "AuthDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthDialog authWindow;
    authWindow.show();
    //ChatWindow w;
    //w.show();
    return a.exec();
}
