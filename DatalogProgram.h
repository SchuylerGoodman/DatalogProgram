#ifndef DATALOG_PROGRAM_H_
#define DATALOG_PROGRAM_H_

#include "SchemesList.h"

class DatalogProgram
{
  public:
    DatalogProgram();
    ~DatalogProgram();

    void setSchemesList(SchemesList* schemeslist);

    SchemesList* getSchemesList();

    std::string toString();
  private:
    SchemesList* slist;
//    FactsList* flist;
 //   RulesList* rlist;
  //  QueriesList* qlist;

};

#endif
