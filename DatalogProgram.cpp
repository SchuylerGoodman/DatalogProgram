#include "DatalogProgram.h"

DatalogProgram::DatalogProgram()
{
    slist = 0;
}

DatalogProgram::~DatalogProgram()
{
    delete[] slist;
    delete[] flist;
    delete[] dman;
//    delete rlist;
//    delete qlist;
}

void DatalogProgram::setSchemesList(SchemesList* schemeslist)
{
    slist = schemeslist;
    return;
}

SchemesList* DatalogProgram::getSchemesList()
{
    return slist;
}

void DatalogProgram::setFactsList(FactsList* factslist)
{
    flist = factslist;
    return;
}

FactsList* DatalogProgram::getFactsList()
{
    return flist;
}

void DatalogProgram::setDomain(Domain* domain)
{
    dman = domain;
}

Domain* DatalogProgram::getDomain()
{
    return dman;
}

std::string DatalogProgram::toString()
{
    string out;
    stringstream stoi; stoi << slist->getSize();
    stringstream ftoi; ftoi << flist->getSize();
    stringstream dtoi; dtoi << dman->getSize();
    out += "Schemes(" + stoi.str();
    out += "):";
    out += slist->toString();
    out += "\nFacts(" + ftoi.str();
    out += "):";
    out += flist->toString();
    /*
    out += "Rules(" + rlist->getSize() + "):";
    out += rlist->toString();
    out += "Queries(" + qlist->getSize() + ");";
    out += qlist->toString();
*/
    //need to do something with the domain when you get to it
    out += "\nDomain(" + dtoi.str();
    out += "):";
    out += dman->toString();
    out += "\n";
    return out;
}
