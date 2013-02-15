#ifndef PREDICATE_H_
#define PREDICATE_H_

class Predicate
{

  public:
    
    Predicate();
    ~Predicate();

    void setID(Token* inputID);

    void setParameterList(ParameterList* inputParameterList);

    int getSize();
    
    std::string toString();

  private:

    Token* Id;

    ParameterList* parameterList;

};

#endif
