#ifndef QUOTATION_H
#define QUOTATION_H

#include <AbstractInterpreter.h>

class Quotation : public AbstractInterpreter
{
public:
    Quotation(int);

    virtual void interpret(QString *context);
};

#endif // QUOTATION_H
