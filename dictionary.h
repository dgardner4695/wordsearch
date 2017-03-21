#include <ostream>
#include <vector>
#include "heap.h"
using namespace std;
class dictionary
{
public:
	void read_words();
	friend ostream& operator<< (ostream& ostr, const dictionary& dict);
	void sort_words();
	int binary_search(string key);
    void dictHeapSort();
private:
	vector<string> word_list;
};
