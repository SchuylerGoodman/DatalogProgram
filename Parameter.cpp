#include "Parameter.h"

Parameter::Parameter()
{
    token = 0;
    expression = 0;
}

Parameter::~Parameter()
{

}

void Parameter::setExpression(Expression* inputExpression)
{
    expression = inputExpression;
}

void Parameter::setToken(Token* inputToken)
{
    token = inputToken;
}

void setExParam(Parameter* inputParameter)
{
    if(expression->param1 == 0)
    {
        expression->param1 = inputParameter;
    }
    else
    {
        expression->param2 = inputParameter;
    }
    return;
}

bool setExToken(Token* inputToken)
{
    bool isRight = true;
    if(op->getTokenType == MULTIPLY || op->getTokenType == ADD)
    {
        operata = op;
    }
    else
    {
        isRight = false;
    }
    return isRight;
}

std::string Parameter::toString()
{
    std::string out;
    else if(token != 0)
    {
        out += token->getTokensValue();
    }
    else if(expression != 0)
    {
        out += expression->toString();
    }
    else
    {
        throw("In Parameter.cpp: No string, ID, or Expression input before string output");
    }
    return out;
}
