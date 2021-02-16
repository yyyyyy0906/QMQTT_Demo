#ifndef MMQTT_H
#define MMQTT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MMQTT; }
QT_END_NAMESPACE

class MMQTT : public QWidget {
    Q_OBJECT
public:
    MMQTT(QWidget *parent = nullptr);
    ~MMQTT();

    void initMQTTItem(void);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
private slots:
    void on_pushButton_clicked();
private:
    Ui::MMQTT *ui;
};
#endif // MMQTT_H
