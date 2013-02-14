#include "SchemesList.h"
#include <iostream>

SchemesList::SchemesList()
{
    listSize = 0;
}

SchemesList::~SchemesList()
{
    for(int i = 0; i < listSize; ++i)
    {
        delete[] schemes[i];
    }
}

void SchemesList::addScheme(Scheme* scheme)
{
    schemes.push_back(scheme);
    ++listSize;
    return;
}

int SchemesList::getSize()
{
    return listSize;
}

std::string SchemesList::toString()
{
    string out;
    for(int i = 0; i < listSize; ++i)
    {
        out += "  " + schemes[i]->toString() + "\n";
    }
    return out;
}
