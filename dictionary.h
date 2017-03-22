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
	int partition(vector<string> &A, int left, int right);
	void quick_sort(vector<string> &A, int left, int right);
	vector<string>& get_words();
private:
	vector<string> word_list;
};
