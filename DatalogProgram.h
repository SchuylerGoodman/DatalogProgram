#ifndef DATALOG_PROGRAM_H_
#define DATALOG_PROGRAM_H_

#include "SchemesList.h"
#include "FactsList.h"
//#include "RulesList.h"
//#include "QueriesList.h"
#include "Domain.h"
#include <iostream>
#include <sstream>

class DatalogProgram
{
  public:
    DatalogProgram();
    ~DatalogProgram();

    void setSchemesList(SchemesList* schemeslist);

    SchemesList* getSchemesList();
    
    void setFactsList(FactsList* factslist);

    FactsList* getFactsList();

    void setDomain(Domain* domain);

    Domain* getDomain();

    std::string toString();
  private:
    SchemesList* slist;
    FactsList* flist;
 //   RulesList* rlist;
  //  QueriesList* qlist;
    Domain* dman;

};

#endif
