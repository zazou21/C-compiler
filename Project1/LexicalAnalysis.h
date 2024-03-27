#ifndef LEXICALANALYSIS_H
#define LEXICALANALYSIS_H

#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

class LexicalAnalysis {
public:
    class Token {
    public:

        std::string type;
        std::string name;
        int value;



    };
    std::string getTokens(std::string input);
    void addToTable(Token &token); 
   

    private:
        std::map < std::string,Token> symbolTable ;
    std::vector<std::pair<std::string, std::string>> patterns = {
        {"KEYWORD", std::string("(sizeof|typedef|volatile|unsigned|continue|register|else|default|switch|extern|static|struct|double|signed|char|float|short|return|while|do|break|case|for|enum|const|if|goto|int|long|auto)")},
        {"BASE16",std::string("(\\ + | -)?0(x|X)[0-9a-fA-F]+")},
        {"BASE8", std::string("(\\+|-)?0[0-7]*")},
        {"BASE10 Integer", std::string("((\\+-)*\\+?|(-\\+)*-?)(0|[1-9][0-9]*)")},
        {"BINARY",std::string("(\\+|-)?0(b|B)[0-1]+")},
        {"IDENTIFIER", std::string("[a-zA-Z_][a-zA-Z0-9_]*")},

        
        {"semicolon",std::string(";")},
        {"brackets",std::string("\\(|\\)|\\[|\\]")},
       
        {"OPERATOR", std::string("(\\+|-|\\*|/|%|=|==|!=|>|<|>=|<=|&&|\\|\\||!|\\?|:|&|\\||\\^|~|<<|>>|\\+=|-=|\\*=|/=|%=|<<=|>>=|&=|\\|=|\\^=|\\{|\\}|\\[|\\]|\\(|\\)|;|,|\\.|->)")},
        {"STRING_LITERAL", std::string("\"(\\\\.|[^\"])*\"")},
        {"CHARACTER_LITERAL", std::string("'(\\\\.|[^'])'")},
        
        
    };
};

#endif 
