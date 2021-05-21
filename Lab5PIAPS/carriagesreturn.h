#ifndef CARRIAGESRETURN_H
#define CARRIAGESRETURN_H

#include <AbstractInterpreter.h>

class CarriagesReturn : public AbstractInterpreter
{
public:
    CarriagesReturn(int);

    virtual void interpret(QString *context);
};

#endif // CARRIAGESRETURN_H
