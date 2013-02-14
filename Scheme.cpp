#include "Scheme.h"

Scheme::Scheme()
{
    Id = 0;
    IDList = 0;
}

Scheme::~Scheme()
{
    delete[] Id;
    delete[] IDList;
}

void Scheme::setID(Token* inputID)
{
    Id = inputID;
    return;
}

void Scheme::setIDList(IdentifierList* identifierlist)
{
    IDList = identifierlist;
    return;
}

std::string Scheme::toString()
{
    string out;
    out += Id->getTokensValue();
    out += "(" + IDList->toString() + ")";
    return out;
}
