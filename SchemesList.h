#ifndef SCHEMES_LIST_H_
#define SCHEMES_LIST_H_

#include "Scheme.h"

class SchemesList
{
  public:
    SchemesList();
    ~SchemesList();

    void addScheme(Scheme* scheme);

    int getSize();

    std::string toString();
  private:

    vector<Scheme*> schemes;
    int listSize;

};

#endif
