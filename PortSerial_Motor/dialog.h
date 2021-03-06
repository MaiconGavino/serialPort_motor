#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QDialog>
#include <QIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QIcon falhaoff;
    QIcon *falha = new QIcon();
    bool estadoFalha;
    QIcon sentidoOff;
    QIcon *sentido = new QIcon();
    bool estadoSent;
    QIcon startOff;
    QIcon *start = new QIcon();
    bool estadoStart;
    QIcon stopOff;
    QIcon *stop = new QIcon();
    bool estadoStop;
    int startMotor;
    QIcon pareOff;
    QIcon *pare = new QIcon();
    bool estadoPare;
    int Falha_erro;
    int contOFF;
    int contOn;
    int acaoStop;
    int acaoStopB;

private slots:
    void on_sent_clicked();
    void readSerial();

    void on_stop_clicked();

    void on_start_clicked();

    void on_pare_clicked();

    void on_startB_clicked();

    void on_sentB_clicked();

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
};
#endif // DIALOG_H
