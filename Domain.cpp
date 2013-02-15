#include "Domain.h"

Domain::Domain()
{
    listSize = 0;
}

Domain::~Domain()
{

}

void Domain::addString(std::string inString)
{
    for(int i = 0; i < listSize; ++i)
    {
        if(strings[i] == inString)
        {
            return;
        }
    }
    strings.push_back(inString);
    ++listSize;
    return;
}

int Domain::getSize()
{
    return strings.size();
}

std::string Domain::toString()
{
    std::string out;
    for(int i = 0; i < listSize; ++i)
    {
        out += "\n  " + strings[i];
    }
    return out;
}
