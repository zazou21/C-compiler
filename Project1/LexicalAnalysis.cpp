#include "LexicalAnalysis.h"
#include <fstream>

void LexicalAnalysis::addToTable(LexicalAnalysis::Token& token) {
    symbolTable.insert(std::make_pair(token.name, token));
}

std::string LexicalAnalysis::getTokens(std::string input) {

    std::string reg;
    for (auto const& x : patterns)
        reg += "(" + x.second + ")|";

    reg.pop_back();

    std::regex re(reg);

    std::sregex_iterator iter(input.begin(), input.end(), re);
    std::sregex_iterator end;


    for (auto it = iter; it != end; ++it)
    {

        for (auto pattern : patterns)
            if (std::regex_match(it->str(), std::regex(pattern.second))) {
                if (pattern.first == "WHITE SPACE")
                    break;
                std::cout << it->str() << "\t" << pattern.first << std::endl;
                break;
            }

    }

    return "";
}

/* if (!std::isspace(input[position + length])) {


     length++;
 }
 else {
     std::string substr = input.substr(position, length);
     for (const auto& pair : patterns) {
         const std::string& type = pair.first;
         const std::regex& pattern = pair.second;
         a
         if (std::regex_search(substr, match, pattern)) {
             std::cout << "<" << type << "> " << match.str() << std::endl;



             break;
         }

     }
     position = position + length + 1;
     length = 0;



*/

void read_file(std::string filepath, std::string& buffer) {
    std::ifstream file(filepath);
    std::string line;
    while (getline(file, line)) {
        buffer.push_back('\n');
        buffer += line;
    }
}

int main() {

    std::string text;
    read_file("input.txt", text);

    
    LexicalAnalysis lexicalAnalyzer;


    lexicalAnalyzer.getTokens(text);
}


// std::string text = "thread local{( int int value =5; \n float hexaNumber=0x30; \n char result=\"ddd\" \n int binaryNumber=0b0001 $$ \n long zazou false true $ inline nullptr refaat static assert(){}//momomo\n/*aok*/'c'";
