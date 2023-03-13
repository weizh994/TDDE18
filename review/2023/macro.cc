#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

// Add your functions here
std::map<std::string,std::string> define_macros(std::ifstream& ifs){
	std::map<std::string,std::string> result{};
	for(std::string line;std::getline(ifs,line,'\n');)
	{
		std::istringstream input{line};
		std::string index{};
		std::string value{};
		std::getline(input,index,':');
		std::getline(input,value,'\n');
		result[index]=value;
	}
	return result;
}
std::string expand(std::string const &line, std::map<std::string,std::string> const &macros)
{	
	std::string result{};
	std::istringstream input{line};
	std::string word{};
	while(input>>word)
	{	
		auto it = macros.find(word);
		if(it==macros.end())
		{
			result.append(word);
			result+=' ';
		}
		else
		{	
			result+=expand(it->second,macros);
		}

	}
	return result;
}
/* Example:

$ ./a.out
I study at LiU
I study at Linköping University
The course FULL_COURSE taught me programming in C++
The course TDDE18 at Department of Computer and Information Science / Linköping University
taught me programming in C++
<ctrl+D>

 */

// You may NOT modify the main function
int main()
{   
    std::ifstream ifs { "MACROS.txt" };

    // auto will become the type of whatever define_macros defines as the return type
    // so it is up to you to decide what type type this variable should be.
    auto macros { define_macros(ifs) };

    std::string line;
    while (std::getline(std::cin, line))
    {        
        std::cout << expand(line, macros) << std::endl;
    }
    
}
