#include "Parser.h"

Parser::Parser()
{
//todo
}

Parser::Parser(vector<Token*>* inputTokens, int* inputCount)
{
    failure = false;
    fail = 0;
    tokens = inputTokens;
    count = inputCount;
}

Parser::~Parser()
{
    delete[] fail;
}

DatalogProgram* Parser::parseDatalogProgram()
{
    Parser* parseTHIS = new Parser(tokens, count);
    DatalogProgram* dtothepizzle = new DatalogProgram();
    if(TokenTypeToString(getTokenType()) == "SCHEMES")
    {
        ++(*count);
        if(TokenTypeToString(getTokenType()) == "COLON")
        {
            ++(*count);
            dtothepizzle->setSchemesList(parseTHIS->parseSchemesList(count));
            if(parseTHIS->hazFailed())
            {
                this->failure = true;
                this->fail = parseTHIS->getFailToken();
                return dtothepizzle;
            }
         /*   else if(tokens[(*count)]->getTokenType() == FACTS)
            {
                //etc
            }*/
        }
        else
        {
            this->failure = true;
            this->fail = (*tokens)[(*count)];
            return dtothepizzle;
        }
    }
    else
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
        return dtothepizzle;
    }
    return dtothepizzle;
}

Token* Parser::getFailToken()
{
    return fail;
}

bool Parser::hazFailed()
{
    return failure;
}

TokenType Parser::getTokenType()
{
    Token* token = (*tokens)[(*count)];
    return token->getTokenType();
}

SchemesList* Parser::parseSchemesList(int* newCount)
{
    count = newCount;
    Parser* HYAAH = new Parser(tokens, count);
    SchemesList* stothelizzle = new SchemesList();
    
    while(TokenTypeToString(getTokenType()) == "ID")
    {
        Scheme* scheme = HYAAH->parseScheme(count);
        if(HYAAH->hazFailed())
        {
            this->failure = true;
            this->fail = HYAAH->getFailToken();
            return stothelizzle;
        }
        stothelizzle->addScheme(scheme);
        ++(*count);
    }
    if(TokenTypeToString(getTokenType()) != "FACTS")
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
    }
    return stothelizzle;
}

Scheme* Parser::parseScheme(int* newCount)
{
    count = newCount;
    Parser* pooYAH = new Parser(tokens, count);
    Scheme* scsingleheme = new Scheme();

    scsingleheme->setID((*tokens)[(*count)]);
    ++(*count);
    if(getTokenType() != LEFT_PAREN)
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
        return scsingleheme;
    }
    else
    {
        ++(*count);
        scsingleheme->setIDList(pooYAH->parseIdentifierList(count));
        if(pooYAH->hazFailed())
        {
            this->failure = true;
            this->fail = pooYAH->getFailToken();
            return scsingleheme;
        }
    }
    return scsingleheme;
}

IdentifierList* Parser::parseIdentifierList(int* newCount)
{
    count = newCount;
    IdentifierList* itothelizzle = new IdentifierList();

    if(TokenTypeToString(getTokenType()) == "ID")
    {
        itothelizzle->setID((*tokens)[(*count)]);
        ++(*count);
        while(getTokenType() != RIGHT_PAREN)
        {
            if(getTokenType() == COMMA)
            {
                ++(*count);
                if(getTokenType() == ID)
                {
                    itothelizzle->addID((*tokens)[(*count)]);
                    ++(*count);
                }
            }
            else
            {
                this->failure = true;
                this->fail = (*tokens)[(*count)];
                return itothelizzle;
            }
        }
    }
    else
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
    }
    return itothelizzle;
}

vector<Token*>* MrVectorCleaner(vector<Token*>* input)
{
    for(int i = 0; i < input->size(); ++i)
    {
        Token* token = (*input)[i];
        if(token->getTokenType() == COMMENT)
        {
            for(int j = i; j < (input->size() + 1); ++j)
            {
                (*input)[j] = (*input)[j + 1];
            }
            input->pop_back();
        }
    }
    return input;
}

int main(int argc, char* argv[])
{
    int* counter = new int(0);
    Lex lex(argv[1]);
    vector<Token*>* raw_vector = lex.tokens;
    Parser* parser = new Parser(MrVectorCleaner(raw_vector), counter);
    DatalogProgram* datalogProgram = parser->parseDatalogProgram();
    if(parser->hazFailed())
    {
        cout << "Failure!" << endl;
        cout << parser->getFailToken()->toString();
    }
    else
    {
        cout << "Success!" << endl;
        cout << datalogProgram->toString();
    }
    return 0;
}
