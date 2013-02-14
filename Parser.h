#ifndef PARSER_H_
#define PARSER_H_

#include "DatalogProgram.h"
#include "Lex.h"
#include <iostream>

class Parser
{
  public:

    Parser();

    Parser(vector<Token*>* inputTokens, int* inputCount);

    ~Parser();

    DatalogProgram* parseDatalogProgram();

    Token* getFailToken();

    bool hazFailed();

  private:

    TokenType getTokenType();

    SchemesList* parseSchemesList(int* newCount);

    Scheme* parseScheme(int* newCount);

    IdentifierList* parseIdentifierList(int* newCount);

//    FactsList* parseFactsList();

    //etc
    
//+++++++++++++++++++Data Members+++++++++++++++++++
    bool failure;
    
    Token* fail;

    vector<Token*>* tokens;

    int* count;

};

#endif
