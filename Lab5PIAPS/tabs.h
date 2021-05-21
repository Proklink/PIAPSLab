#ifndef TABS_H
#define TABS_H

#include <AbstractInterpreter.h>

class Tabs : public AbstractInterpreter
{
public:
    Tabs(int);

    virtual void interpret(QString *context);
};

#endif // TABS_H
