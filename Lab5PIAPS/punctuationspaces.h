#ifndef PUNCTUATIONSPACES_H
#define PUNCTUATIONSPACES_H
#include <AbstractInterpreter.h>

class PunctuationSpaces : public AbstractInterpreter
{
public:
    PunctuationSpaces(int);

    virtual void interpret(QString *context);
};

#endif // PUNCTUATIONSPACES_H
