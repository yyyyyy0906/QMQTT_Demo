#include "MMQTT.h"
#include "ui_mmqtt.h"

#include <QHostAddress>
#include <QDebug>

#include <qmqttclient.h>

MMQTT::MMQTT(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MMQTT) {

    ui->setupUi(this);
    this->initMQTTItem();
}

MMQTT::~MMQTT() {
    delete ui;
}

void MMQTT::initMQTTItem() {

}

void MMQTT::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
}


void MMQTT::on_pushButton_clicked()
{
    QMqttClient* client = new(std::nothrow) QMqttClient(this);
    QHostAddress hostAddress("b7143366.cn.emqx.cloud");
    Q_UNUSED(hostAddress);
    quint16      hostPort = 12004;

    client->setHostname("b7143366.cn.emqx.cloud");
    client->setPort(hostPort);
    client->setClientId("mqtt_from_qt5.15.3");
    //服务器鉴权
    client->setUsername("mqtt_from_qt");
    client->setPassword("root");
    client->connectToHost();

    QObject::connect(client, &QMqttClient::connected, [&] {
        qDebug() << "连接成功！！！";
    });
}
