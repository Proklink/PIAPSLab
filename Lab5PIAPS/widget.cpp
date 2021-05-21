#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    layout(new QHBoxLayout),
    mainLayout(new QVBoxLayout(this)),
    interpret(new QPushButton("Interpret"))
{
    this->resize(640,640);          // Устанавливаем размеры окна приложения
    this->setFixedSize(640,640);
    textArea.setBaseSize(500, 500);


    layout->addWidget(interpret);

    mainLayout->addWidget(&textArea);
    mainLayout->addLayout(layout);

    connect(interpret, &QPushButton::clicked, this, &Widget::interpretClicked);
}

Widget::~Widget()
{
}


void Widget::interpretClicked() {
    //получить текст с области и запустить интерпертации

    QString context = textArea.toPlainText();

    AInterpreter.interpret(&context);

    textArea.setPlainText(context);
}

//Паттерн Intepreter определяет грамматическое представление для языка и интерпретатор для интерпретации грамматики. Музыканты являются примерами интерпретаторов. Тональность и продолжительность звуков могут быть описаны нотами. Такое представление является музыкальным языком. Музыканты, используя ноты, способны воспроизвести оригинальные частоту и длительность каждого представленного звука.
