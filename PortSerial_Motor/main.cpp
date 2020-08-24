#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setStyleSheet("background-image:url(:quadro.png)");
    w.setWindowTitle("Painel Central");
    w.show();
    return a.exec();
}
