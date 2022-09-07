#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){		
	ifstream read_file;
	read_file.open("text.txt",ios::in);
	string word;
	int num=0;
	float sum=0.0;
	string shortest_word,longest_word;
	int shortest{9999999},longest{0};
	while(read_file>>word){
		num++;
		sum+=word.size();
		if(static_cast<int>(word.size())<shortest){
			shortest=static_cast<int>(word.size());
			shortest_word=word;
		}
		if(static_cast<int>(word.size())>longest){
			longest=static_cast<int>(word.size());
			longest_word=word;
		}
	}
	read_file.close();
	if(num>1)cout<<"There are "<<num<<" words in the file."<<endl;
	else cout<<"There is "<<num<<" word in the file."<<endl;
	if(num!=0){
		cout<<"The shortest word was \""<<shortest_word<<"\" with "<<shortest<<" character(s)."<<endl;
		cout<<"The longest word was \""<<longest_word<<"\" with "<<longest<<" character(s)."<<endl;
		cout<<"The average length was "<<sum/num<<" character(s)."<<endl;
	}
	return 0;
}
