#ifndef SPACES_H
#define SPACES_H

#include <AbstractInterpreter.h>


class Spaces : public AbstractInterpreter
{
public:
    Spaces(int);

    virtual void interpret(QString *context);
};

#endif // SPACES_H
