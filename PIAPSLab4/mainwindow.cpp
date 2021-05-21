#include "mainwindow.h"

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    
{
    this->resize(640,640);          // Устанавливаем размеры окна приложения
    this->setFixedSize(640,640);

    mainScene = new QGraphicsScene(this);
    mainScene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view = new QGraphicsView();
    view->resize(600,600);  // Устанавливаем размер graphicsView
    view->setScene(mainScene);  // Устанавливаем графическую сцену в graphicsView
    view->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    view->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    mainScene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены


    item = new Rectangle(view);        // Создаём графический элемента
    item->setPos(randomBetween(30, 470), randomBetween(30,470));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    mainScene->addItem(item);


    view->show();
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {

    this->setCursor(QCursor(Qt::ClosedHandCursor));
    this->update();

    Q_UNUSED(event);
}



MainWindow::~MainWindow()
{
  delete view;
  delete mainScene;
  //delete item;
}

