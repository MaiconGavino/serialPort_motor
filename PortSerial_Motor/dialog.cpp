


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
    ui->falhaB->setIcon(*falha);
    estadoFalha = false;

    //adicionando a função Sentido;
    sentidoOff.addFile(":/sent.png");
    sentido->addFile(":/sent-off.png");
    ui->sent->setIcon(*sentido);
    ui->sentB->setIcon(*sentido);
    estadoSent = false;

    //adicionando a função start;
    startOff.addFile(":/start.png");
    start->addFile(":/start-off.png");
    ui->start->setIcon(*start);
    ui->startB->setIcon(*start);
    estadoStart = false;

    //adicionando a função stop;
    stopOff.addFile(":/stop.png");
    stop->addFile(":/stop-off.png");
    ui->stop->setIcon(*stop);
    estadoStop = false;

    //adicionando a função parar motor;
    pareOff.addFile(":/pare.png");
    pare->addFile(":/pareOff.png");
    ui->pare->setIcon(*pare);
    ui->pareB->setIcon(*pare);
    estadoPare = false;
    acaoStop = 0;
    acaoStopB = 0;
    contOn = 0;
    arduino = new QSerialPort(this);

    // Identificar a porta, o ID do fornecedor e o ID do produto
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
                arduino->open(QSerialPort::WriteOnly);
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


//Função sentido do motor
void Dialog::on_sent_clicked()
{
       if(!estadoSent)
        {
            ui->sent->setIcon(sentidoOff);
            estadoSent = true;
            startMotor = 1;
        }
        else
        {
            ui->sent->setIcon(*sentido);
            estadoSent = false;
            startMotor = 2;
        }
}


//Função Falha no sistema
void Dialog::on_falha_clicked()
{
//    if(!estadoFalha)
//    {
//        ui->falha->setIcon(falhaoff);
//        estadoFalha = true;
//        if(Falha_erro==1)
//        {
//            ui->falha->setIcon(*falha);
//        }
//    }
//    else
//    {
//        ui->falha->setIcon(*falha);
//        estadoFalha = false;
//    }
}


//Função Parar Sistema
void Dialog::on_stop_clicked()
{
    if(!estadoStop)
    {
        ui->stop->setIcon(stopOff);
        estadoStop = true;
        if(arduino->isWritable())
        {
            arduino->write("0\n");
            ui->start->setIcon(*start);
            ui->pare->setIcon(*pare);
            acaoStop = 1;
        }
    }
    else
    {
        ui->stop->setIcon(*stop);
        estadoStop = false;
        acaoStop = 0;
    }
}


//Função Ligar motor
void Dialog::on_start_clicked()
{
    if(acaoStop == 0){
    if(!estadoStart)
    {
        ui->start->setIcon(startOff);
        estadoStart = false;
        ui->pare->setIcon(pareOff);
        contOn = 0;
        if(arduino->isWritable())
        {
            if(startMotor==1)
            {
                arduino->write("1\n");
                ui->sent->setIcon(sentidoOff);
            }
            else
            {
                arduino->write("2\n");
                qDebug() << "envio";
            }
        }
        else
        {
              ui->falha->setIcon(falhaoff);
              ui->start->setIcon(*start);
              ui->pare -> setIcon(*pare);
              qDebug() << "erro na porta serial";
        }
    }
    else
    {
        ui->start->setIcon(*start);
        estadoStart = true;
    }
    }
}



// Função Parar Motor
void Dialog::on_pare_clicked()
{
    if(!estadoPare)
    {
        if(contOn == 0)
        {
            ui->pare->setIcon(*pare);
            ui->start->setIcon(*start);
            ui->falha->setIcon(*falha);
        }

        estadoPare = false;
        if(arduino->isWritable())
        {
            arduino->write("0\n");
        }


    }
    else
    {
        ui->pare->setIcon(pareOff);
        estadoPare = true;
    }
}

void Dialog::on_startB_clicked()
{
    if(acaoStopB == 0){
    if(!estadoStart)
    {
        ui->start->setIcon(startOff);
        estadoStart = false;
        ui->pare->setIcon(pareOff);
        contOn = 0;
        if(arduino->isWritable())
        {
            if(startMotor==3)
            {
                arduino->write("3\n");
                ui->sent->setIcon(sentidoOff);
            }
            else
            {
                arduino->write("3\n");
                qDebug() << "envio";
            }
        }
        else
        {
              ui->falha->setIcon(falhaoff);
              ui->start->setIcon(*start);
              ui->pare -> setIcon(*pare);
              qDebug() << "erro na porta serial";
        }
    }
    else
    {
        ui->start->setIcon(*start);
        estadoStart = true;
    }
    }
}
