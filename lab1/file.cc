#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// TODO: Complementary work: You must print a warning and end the program if the file is empty. 
// CHECKED
// TODO: Complementary work: Declaring the shortest word as a int at first
// is not the best way to solve this, what if a word is longer? 
// Hint: Can you use the first word in the file?
// CHECKED
// TODO: Complementary work: Functions and blocks need to be 
// indented properly (be consistent). 
// CHECKED
// TODO: Complementary work: Float is not the best variable to use, rounding errors are more
// prone to happen.
// Double?

int main(){		
	ifstream read_file;
	read_file.open("text.txt" , ios::in);
	string word;
	int num = 0;
	double sum = 0.0;
	string shortest_word,longest_word;
	long shortest,longest;
	if(read_file >> word){//first word
		shortest = word.size();
		longest = word.size();
		num++;
	}
	while(read_file >> word){
		num++;
		sum+=word.size();
		if(word.size() < shortest){
			shortest=word.size();
			shortest_word = word;
		}
		if(word.size() > longest){
			longest=word.size();
			longest_word = word;
		}
	}
	read_file.close();
	if(num > 1)cout << "There are " << num << " words in the file." << endl;
	else cout << "There is " << num << " word in the file." << endl;
	if(num!=0){
		cout << "The shortest word was \""
				 << shortest_word << "\" with "
				 << shortest << " character(s)." << endl;
		cout << "The longest word was \""
				 << longest_word << "\" with "
				 << longest << " character(s)." << endl;
		cout << "The average length was "
				 << sum/num << " character(s)." << endl;
	}
	else cerr << "WARRING: The file is empty!" << endl;
	return 0;
}
