#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    labelLayout = new QHBoxLayout();
    buttonLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);
    calculate = new QPushButton("Calculate");
    result = new QLabel;

    setMinimumSize(800, 800);

    labelLayout->setGeometry(QRect(10, 10, 100, 100));

    labelLayout->addWidget(result);
    buttonLayout->addWidget(calculate);

    mainLayout->addLayout(labelLayout);
    mainLayout->addLayout(buttonLayout);

}

Widget::~Widget()
{
}

