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
    void addToTable(Token& token);

private:
    std::map < std::string, Token> symbolTable;
    std::vector<std::pair<std::string, std::string>> patterns = {
        {"COMMENT", std::string("/\\*([^*]|(\\*+[^*/]))*\\*+/|//.*$")},
        
        {"KEYWORD", std::string("(static assert|thread local|sizeof|typedef|volatile|unsigned|continue|register|else|default|switch|extern|static|struct|double|signed|char|float|short|return|while|do|break|case|for|enum|const|if|goto|int|long|auto|bool|extern|false|true|inline|nullptr|restrict|typeof|typeof_unqual|union|void)")},

        {"BASE16",std::string("(\\ + | -)?0(x|X)[0-9a-fA-F]+")},
        {"BINARY",std::string("(\\+|-)?0(b|B)[0-1]+")},
        {"BASE8", std::string("(\\+|-)?0[0-7]*")},
        {"FLOATING NUMBER",std::string("((\\+-)*\\+?|(-\\+)*-?)(0|[1-9][0-9]*) ((e|E)(\\+|-)?[0-9]+)?")},
        {"BASE10 INTEGER", std::string("((\\+-)*\\+?|(-\\+)*-?)(0|[1-9][0-9]*)")},

        {"IDENTIFIER", std::string("[a-zA-Z_][a-zA-Z0-9_]*")},

        {"SEMICOLON",std::string(";")},
        {"BRACKETS",std::string("\\(|\\)|\\[|\\]")},
        {"OPERATOR", std::string("(\\+|-|\\*|/|%|=|==|!=|>|<|>=|<=|&&|\\|\\||!|\\?|:|&|\\||\\^|~|<<|>>|\\+=|-=|\\*=|/=|%=|<<=|>>=|&=|\\|=|\\^=|\\{|\\}|\\[|\\]|\\(|\\)|;|,|\\.|->)")},
        {"STRING_LITERAL", std::string("\"(\\\\.|[^\"])*\"")},
        {"CHARACTER_LITERAL", std::string("'(\\\\.|[^'])'")},
        {"WHITE SPACE",std::string("[ \\n\\t]+")},
        {"INVALID TOKEN",std::string(".")}
    };
};

#endif
