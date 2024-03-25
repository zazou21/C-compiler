#include "LexicalAnalysis.h"



std::string LexicalAnalysis::getTokens(std::string input) {
    int position = 0;
    std::smatch match;
    int length = 0;
    std::string reg;
    for (auto const& x : patterns)
        reg += "(" + x.second + ")|";


    reg.pop_back();

    //for (const auto& pair : patterns) {
    
        std::regex re(reg);
    
    

  //      const std::string& type = pair.first;
  //    const std::regex& pattern = pair.second; 
        std::sregex_iterator iter(input.begin(), input.end(), re);
        std::sregex_iterator end;

      
        for (auto it = iter; it != end; ++it)
        {
            

            for (auto pattern:patterns)
                if (std::regex_match(it->str(), std::regex(pattern.second))) {
                    std::cout << it->str() << "\t" << pattern.first << std::endl;
                    break;
                }

                    

          
        }

    //}


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

            if (std::regex_search(substr, match, pattern)) {
                std::cout << "<" << type << "> " << match.str() << std::endl;



                break;
            }

        }
        position = position + length + 1;
        length = 0;



*/


  


int main() {
   
    std::string text = " int korkor =5; \n float mou=030; \n float result=korkor + mou ";
    


   
    LexicalAnalysis lexicalAnalyzer;

   
    lexicalAnalyzer.getTokens(text);

}
