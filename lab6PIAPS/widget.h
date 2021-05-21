#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QHBoxLayout *labelLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QPushButton *calculate;
    QLabel *result;

};
#endif // WIDGET_H
