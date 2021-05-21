#ifndef HYPHENS_H
#define HYPHENS_H

#include <AbstractInterpreter.h>

class Hyphens : public AbstractInterpreter
{
public:
    Hyphens(int);

    virtual void interpret(QString *context);
};

#endif // HYPHENS_H
