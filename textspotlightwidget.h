#ifndef TEXTSPOTLIGHTWIDGET_H
#define TEXTSPOTLIGHTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class TextSpotlightWidget; }
QT_END_NAMESPACE

class TextSpotlightWidget : public QWidget
{
    Q_OBJECT

public:
    TextSpotlightWidget(QWidget *parent = nullptr);
    ~TextSpotlightWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
//    Ui::TextSpotlightWidget *ui;
    QString text;
    QTimer timer;
    QRect textRect;
    int changeValue{0};
    bool runDirectionIsRight{true};
private:
    void onTimer();
};
#endif // TEXTSPOTLIGHTWIDGET_H
