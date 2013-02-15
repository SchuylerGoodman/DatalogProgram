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
    Domain* domain = new Domain();
    dtothepizzle->setDomain(domain);
// Start of Schemes Parsing
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
            // Start of Facts Parsing
            else if(TokenTypeToString(getTokenType()) == "FACTS")
            {
                ++(*count);
                if(TokenTypeToString(getTokenType()) == "COLON")
                {
                    ++(*count);
                    dtothepizzle->setFactsList(parseTHIS->parseFactsList(count, dtothepizzle->getDomain()));
                    if(parseTHIS->hazFailed())
                    {
                        this->failure = true;
                        this->fail = parseTHIS->getFailToken();
                        return dtothepizzle;
                    }
                }
                else
                {
                    this->failure = true;
                    this->fail = (*tokens)[(*count)];
                    return dtothepizzle;
                }
                // Start of Rules Parsing
                /*if(TokenTypeToString(getTokenType()) == "RULES")
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

hemesList* Parser::parseSchemesList(int* newCount)
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
                else
                {
                    this->failure = true;
                    this->fail = (*tokens)[(*count)];
                    return itothelizzle;
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

FactsList* Parser::parseFactsList(int* newCount, Domain* dman)
{
    count = newCount;
    Parser* PraARse = new Parser(tokens, count);
    FactsList* ftothelizzle = new FactsList();
    Domain* domain = dman;

    while(TokenTypeToString(getTokenType()) == "ID")
    {
        Fact* fact = PraARse->parseFact(count, domain);
        if(PraARse->hazFailed())
        {
            this->failure = true;
            this->fail = PraARse->getFailToken();
            return ftothelizzle;
        }
        ftothelizzle->addFact(fact);
        ++(*count);
    }
    return ftothelizzle;
}

Fact* Parser::parseFact(int* newCount, Domain* dman)
{
    count = newCount;
    Parser* farse = new Parser(tokens, count);
    Fact* fact = new Fact();
    Domain* domain = dman;

    fact->setID((*tokens)[(*count)]);
    ++(*count);
    if(TokenTypeToString(getTokenType()) == "LEFT_PAREN")
    {
        ++(*count);
        fact->setConstantList(farse->parseConstantList(count, domain));
        if(farse->hazFailed())
        {
            this->failure = true;
            this->fail = farse->getFailToken();
            return fact;
        }
    }
    else
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
        return fact;
    }
    return fact;
}

ConstantList* Parser::parseConstantList(int* newCount, Domain* dman)
{
    count = newCount;
    ConstantList* ctothelizzle = new ConstantList();
    Domain* domain = dman;

    if(TokenTypeToString(getTokenType()) == "STRING")
    {
        ctothelizzle->setString((*tokens)[(*count)]);
        dman->addString((*tokens)[(*count)]->getTokensValue());
        ++(*count);
        while(getTokenType() != RIGHT_PAREN)
        {
            if(getTokenType() == COMMA)
            {
                ++(*count);
                if(getTokenType() == STRING)
                {
                    ctothelizzle->addString((*tokens)[(*count)]);
                    dman->addString((*tokens)[(*count)]->getTokensValue());
                    ++(*count);
                }
                else
                {
                    this->failure = true;
                    this->fail = (*tokens)[(*count)];
                    return ctothelizzle;
                }
            }
            else
            {
                this->failure = true;
                this->fail = (*tokens)[(*count)];
                return ctothelizzle;
            }
        }
        ++(*count);
        if(getTokenType() != PERIOD)
        {
            this->failure = true;
            this->fail = (*tokens)[(*count)];
        }
    }
    else
    {
        this->failure = true;
        this->fail = (*tokens)[(*count)];
    }
    return ctothelizzle;
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
