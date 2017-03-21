#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include "heap.h"

using namespace std;

void dictionary::read_words()
{
	ifstream dict_file;
	string word;
	dict_file.open("sorted_dict.txt");
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
	for (unsigned int i = 0; i < dict.word_list.size(); i++)
	{
		ostr << dict.word_list.at(i) << endl;
	}
	return ostr;
}

void dictionary::sort_words()
{
	int min;
	for (unsigned int i = 0; i < word_list.size(); i++)
	{
		min = i;
		for (unsigned int j = i+1; j < word_list.size(); j++)
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
	int high = word_list.size();
    int low = 0;
    int curr;
    while(high >= low){
        curr = (high + low)/2;

        if(word_list.at(curr) > key){ //iterates the current element
            high = curr - 1;
        }
        else if(word_list.at(curr) < key){
            low = curr + 1;
        }
        else{
            return curr;
        }
    }
    return -1;
}

void dictionary::dictHeapSort() {
    heap<string> h(word_list.size() + 1);

    h.initializeMaxHeap(word_list);

    word_list = h.heapSort();
}
