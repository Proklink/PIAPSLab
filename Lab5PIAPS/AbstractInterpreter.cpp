#include "AbstractInterpreter.h"
#include "carriagesreturn.h"
#include "hyphens.h"
#include "spaces.h"
#include "tabs.h"
#include "quotation.h"
#include "punctuationspaces.h"
#include "foreignchars.h"


AbstractInterpreter::AbstractInterpreter()
{
    spaces = (AbstractInterpreter *)new Spaces(1);
    hyphens = (AbstractInterpreter *)new Hyphens(1);
    tabs = (AbstractInterpreter *)new Tabs(1);
    carriagesReturn = (AbstractInterpreter *)new CarriagesReturn(1);
    quotation = (AbstractInterpreter *)new Quotation(1);
    pSpaces = (AbstractInterpreter *)new PunctuationSpaces(1);
    fChars = (AbstractInterpreter *)new ForeignChars(1);
}

AbstractInterpreter::AbstractInterpreter(int)
{

}

void AbstractInterpreter::interpret(QString *context) {
    spaces->interpret(context);
    hyphens->interpret(context);
    carriagesReturn->interpret(context);
    tabs->interpret(context);
    quotation->interpret(context);
    pSpaces->interpret(context);
    fChars->interpret(context);
}


