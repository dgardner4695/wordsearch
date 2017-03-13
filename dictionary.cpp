#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"

using namespace std;
void dictionary::read_words()
{
	ifstream dict_file;
	string word;
	dict_file.open("dictionary.txt");
	if (dict_file.is_open())
		while (getline(dict_file, word))
		{
			word_list.push_back(word);
		}
	else
	{
		cout << "Error opening file for reading" << endl;
	}
}

ostream& operator<< (ostream& ostr, const dictionary& dict)
{
	for (int i = 0; i < dict.word_list.size(); i++)
	{
		cout << dict.word_list.at(i);
	}
}

void dictionary::sort_words()
{
	int min;
	for (int i = 0; i < word_list.size(); i++)
	{
		min = i;
		for (int j = i+1; j < word_list.size(); j++)
		{
			if (word_list.at(j) < word_list.at(min))
			{
				min = j;
			}
		}
		swap(word_list.at(i), word_list.at(min));
	}
}

int dictionary::binary_search(string key)
{
    int iterator = word_list.size()/2;
	int curr = iterator;
    while(word_list.at(curr) != key){
        iterator = iterator/2;
        if(iterator == 0){
            iterator++;
        }

        if(word_list.at(curr) > key){
            curr = curr - iterator;
        }
        else{
            curr = curr + iterator;
        }
    }
    return curr;
}
