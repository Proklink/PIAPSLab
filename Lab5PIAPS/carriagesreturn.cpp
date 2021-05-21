#include "carriagesreturn.h"

CarriagesReturn::CarriagesReturn(int) : AbstractInterpreter(1)
{

}

void CarriagesReturn::interpret(QString * context) {
    context->replace(QRegExp("\n+"), "\n");
}
