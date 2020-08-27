#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QIcon>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //adicionando a função falha;
    falhaoff.addFile(":/falha.png");
    falha->addFile(":/falha-off.png");
    ui->falha->setIcon(*falha);
    estadoFalha = false;

    //adicionando a função Sentido;
    sentidoOff.addFile(":/sent.png");
    sentido->addFile(":/sent-off.png");
    ui->sent->setIcon(*sentido);
    estadoSent = false;

    //adicionando a função start;
    startOff.addFile(":/start.png");
    start->addFile(":/start-off.png");
    ui->start->setIcon(*start);
    estadoStart = false;

    //adicionando a função stop;
    stopOff.addFile(":/stop.png");
    stop->addFile(":/stop-off.png");
    ui->stop->setIcon(*stop);
    estadoStop = false;

    arduino = new QSerialPort(this);

    /* Identificar a porta, o ID do fornecedor e o ID do produto
        qDebug() << "Porta Numero:" <<
                    QSerialPortInfo::availablePorts().length();
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
            qDebug() <<"Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
            if(serialPortInfo.hasVendorIdentifier())
            {
                qDebug() <<"Vendor ID: " << serialPortInfo.vendorIdentifier();
            }
            qDebug() << "Has product ID: " << serialPortInfo.hasProductIdentifier();
            if(serialPortInfo.hasProductIdentifier())
            {
                qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
            }
        }
    */

        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
            {
                if(serialPortInfo.vendorIdentifier()==arduino_uno_vendor_id)
                {
                    if(serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    {
                        arduino_port_name = serialPortInfo.portName();
                        arduino_is_available = true;
                    }
                }
            }
            if(arduino_is_available)
            {
                //abri e configurar o serial
                arduino->setPortName(arduino_port_name);
                arduino->open(QSerialPort::ReadOnly);
                arduino->setBaudRate(QSerialPort::Baud9600);
                arduino->setDataBits(QSerialPort::Data8);
                arduino->setParity(QSerialPort::NoParity);
                arduino->setStopBits(QSerialPort::OneStop);
                arduino->setFlowControl(QSerialPort::NoFlowControl);
                QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
            }
            else
            {
                //informar error
                QMessageBox::warning(this, "Port Error", "Arduino não conectado a porta");

            }
        }
}

Dialog::~Dialog()
{
    if(arduino->isOpen())
    {
        arduino->close();
    }
    delete ui;
}

void Dialog::readSerial()
{
    QString sent = arduino->readAll();
    qDebug() << sent;
}


void Dialog::on_sent_clicked()
{
    if(!estadoSent)
    {
        ui->sent->setIcon(sentidoOff);
        estadoSent = true;
    }
    else
    {
        ui->sent->setIcon(*sentido);
        estadoSent = false;
    }
}

void Dialog::on_falha_clicked()
{
    if(!estadoFalha)
    {
        ui->falha->setIcon(falhaoff);
        estadoFalha = true;
    }
    else
    {
        ui->falha->setIcon(*falha);
        estadoFalha = false;
    }
}

void Dialog::on_stop_clicked()
{
    if(!estadoStop)
    {
        ui->stop->setIcon(stopOff);
        estadoStop = true;
    }
    else
    {
        ui->stop->setIcon(*stop);
        estadoStop = false;
    }
}

void Dialog::on_start_clicked()
{
    if(!estadoStart)
    {
        ui->start->setIcon(startOff);
        estadoStart = true;
    }
    else
    {
        ui->start->setIcon(*start);
        estadoStart = false;
    }
}
