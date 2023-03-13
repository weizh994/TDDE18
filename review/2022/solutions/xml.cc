#include <fstream>
#include <string>
#include <stack>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

int main(int argc, char** argv)
{
    std::ifstream ifs {argv[1]};

    if (!ifs)
    {
        std::cout << "File '" << argv[1] << "' does not exist";
        return 1;
    }
    
    std::stack<std::string> stack{};
    
    std::string line{};
    while (std::getline(ifs, line))
    {
        if (line.front() == '<' && line.back() == '>')
        {
            bool closed{false};
            
            // remove < and >
            line = line.substr(1, line.size() - 2);
            
            if (line.front() == '/')
            {
                line.erase(0, 1);
                closed = true;
            }

            if (!std::all_of(line.begin(), line.end(), [](char c)
                             { return std::isalpha(c); }))
            {
                std::cout << "Invalid tag <" << line << ">" << std::endl;
                return 1;
            }

            if (closed)
            {
                if (stack.top() != line)
                {
                    std::cout << "Tag <" << stack.top() << "> not closed"
                              << std::endl;
                    return 1;
                }
                stack.pop();
            }
            else
            {
                stack.push(line);
            }
        }
    }
    if (!stack.empty())
    {
        std::cout << "There are unclosed tags" << std::endl;
        return 1;
    }
    std::cout << "Valid XML file!" << std::endl;
}
