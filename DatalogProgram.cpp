#include "DatalogProgram.h"
#include <iostream>
#include <sstream>

DatalogProgram::DatalogProgram()
{
    slist = 0;
}

DatalogProgram::~DatalogProgram()
{
    delete[] slist;
/*    delete flist;
    delete rlist;
    delete qlist;
*/}

void DatalogProgram::setSchemesList(SchemesList* schemeslist)
{
    slist = schemeslist;
    return;
}

SchemesList* DatalogProgram::getSchemesList()
{
    return slist;
}

std::string DatalogProgram::toString()
{
    string out;
    stringstream stoi; stoi << slist->getSize();
    out += "Schemes(" + stoi.str();
    out += "):\n";
    out += slist->toString();
/*    out += "Facts(" + flist->getSize() + "):";
    out += flist->toString();
    out += "Rules(" + rlist->getSize() + "):";
    out += rlist->toString();
    out += "Queries(" + qlist->getSize() + ");";
    out += qlist->toString();
*/
    //need to do something with the domain when you get to it
    return out;
}
