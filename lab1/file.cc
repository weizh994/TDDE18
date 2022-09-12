#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// TODO: Complementary work: The average word should give two decimals
// TODO: Complementary work: Seperate the different parts of the
// code with an empty line.
// TODO: Complementary work: Use {} for if and end statements for 
// readability if you have it around some.

int main(){		
	ifstream read_file;
	read_file.open("text.txt" , ios::in);
	string word;
	int num = 0;
	double sum = 0.0;
	string shortest_word,longest_word;
	long shortest_word_length,longest_word_length;
	
	
	if(read_file >> word)//first word
	{
		shortest_word_length = word.size();
		longest_word_length = word.size();
		num++;
	}
	while(read_file >> word)
	{
		num++;
		sum+=word.size();
		if(word.size() < shortest)
		{
			shortest_word_length=word.size();
			shortest_word = word;
		}
		if(word.size() > longest_word_length)
		{
			longest_word_length=word.size();
			longest_word = word;
		}
	}
	read_file.close();
	
	
	if(num > 1)
	{
		cout << "There are " << num << " words in the file." << endl;
	}
	else
	{
		cout << "There is " << num << " word in the file." << endl;
	}
	
	if(num!=0)
	{
		cout << "The shortest word was \""
				 << shortest_word << "\" with "
				 << shortest_word_length << " character(s)." << endl;
		cout << "The longest word was \""
				 << longest_word << "\" with "
				 << longest_word_length << " character(s)." << endl;
		cout << "The average length was "<< fixed << setprecision(2)
				 << sum/num << " character(s)." << endl;
	}
	else cerr << "WARRING: The file is empty!" << endl;
	
	return 0;
}
