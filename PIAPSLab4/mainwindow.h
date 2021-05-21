#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <rectangle.h>
#include <QRandomGenerator>
#include <QPaintEngine>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *mainScene;
    QGraphicsView *view;
    Rectangle *item;
    void mouseDoubleClickEvent(QMouseEvent *event);


};
#endif // MAINWINDOW_H
