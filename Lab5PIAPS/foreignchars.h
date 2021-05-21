#ifndef FOREIGNCHARS_H
#define FOREIGNCHARS_H

#include <AbstractInterpreter.h>

class ForeignChars : AbstractInterpreter
{
public:
    ForeignChars(int);

    virtual void interpret(QString *context);
};

#endif // FOREIGNCHARS_H
