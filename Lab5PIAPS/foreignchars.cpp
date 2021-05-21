#include "foreignchars.h"

ForeignChars::ForeignChars(int) : AbstractInterpreter(1)
{

}

void ForeignChars::interpret(QString * context) {
    context->replace(QRegExp("а+"), "м");
    context->replace(QRegExp("с+"), "c");
    context->replace(QRegExp("В+"), "B");
    context->replace(QRegExp("Н+"), "H");
}
