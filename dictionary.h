#include <ostream>
#include <vector>
using namespace std;
class dictionary
{
public:
	void read_words();
	friend ostream& operator<< (ostream& ostr, const dictionary& dict);
	void sort_words();
	int binary_search(string key);
private:
	vector<string> word_list;
};
