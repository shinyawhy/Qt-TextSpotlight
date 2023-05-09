#include "textspotlightwidget.h"
#include "ui_textspotlightwidget.h"

TextSpotlightWidget::TextSpotlightWidget(QWidget *parent)
    : QWidget(parent)

{
    //    ui->setupUi(this);
    text = "恐是天仙谪人世，只合人间十三岁。";
    auto font = this->font();
    font.setPixelSize(40);
    font.setBold(true);
    setFont(font);

    connect(&timer, &QTimer::timeout, this, &TextSpotlightWidget::onTimer);
    timer.start(40);
}

TextSpotlightWidget::~TextSpotlightWidget()
{
    //    delete ui;
}

void TextSpotlightWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(this->font());
    auto rect = this->rect();

    painter.save();
    painter.setPen(QColor("#4c8045"));
    painter.drawText(rect, Qt::AlignCenter | Qt::TextWordWrap, text);
    painter.restore();

    textRect = painter.boundingRect(rect, Qt::AlignCenter | Qt::TextWordWrap, text);
    auto pos = textRect.topLeft() + QPoint(changeValue, 0);

    QPainterPath path;
    path.addEllipse(QPointF(pos.x(), pos.y() + textRect.height() / 2), 50, 50);
    painter.setClipPath(path);

    auto tempRect = path.boundingRect();
    QLinearGradient linearGradient(tempRect.topRight(),tempRect.bottomLeft());
    linearGradient.setColorAt(0.0,Qt::magenta);
    linearGradient.setColorAt(0.2,Qt::darkYellow);
    linearGradient.setColorAt(0.4,Qt::green);
    linearGradient.setColorAt(0.6,Qt::red);
    linearGradient.setColorAt(0.8,Qt::darkRed);
    linearGradient.setColorAt(1.0,Qt::blue);
    painter.setBrush(Qt::transparent);
    painter.setPen(QPen(QBrush(linearGradient),3));

    painter.drawText(rect, Qt::AlignCenter | Qt::TextWordWrap, text);

}

void TextSpotlightWidget::onTimer()
{
    if(runDirectionIsRight)
    {
        changeValue += 15;
        if(changeValue >= textRect.width())
        {
            runDirectionIsRight = false;
        }
    }
    else
    {
        changeValue -= 15;
        if(changeValue <= 0)
        {
            runDirectionIsRight = true;
        }
    }
    update();
}

