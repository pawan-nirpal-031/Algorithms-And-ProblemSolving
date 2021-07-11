#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::map;
using std::pair;
using std::reverse;

void countSymbols(const string& text, map<char, int>& cumCount, vector<int>& occTimes, int& DSymbolPos) {
	int Acount = 0;
	int Ccount = 0;
	int Gcount = 0;
	int Tcount = 0;
	int Dcount = 0;
	for (int i = 0; i < text.size(); i++) {
		char symbol = text[i];
		if (symbol == 'A') {
			occTimes.push_back(Acount);
			Acount++;
		} else if (symbol == 'C') {
			occTimes.push_back(Ccount);
			Ccount++;
		} else if (symbol == 'G') {
			occTimes.push_back(Gcount);
			Gcount++;
		} else if (symbol == 'T') {
			occTimes.push_back(Tcount);
			Tcount++;
		} else if (symbol == '$') {
			DSymbolPos = i;
			occTimes.push_back(Dcount);
			Dcount++;
		}
	}
	cumCount['$'] = 0;
	cumCount['A'] = Dcount;
	cumCount['C'] = cumCount['A'] + Acount;
	cumCount['G'] = cumCount['C'] + Ccount;
	cumCount['T'] = cumCount['G'] + Gcount;
}

string InverseBWT(const string& bwt) {
	string text = "";
	map<char, int> cumCount;
	vector<int> occTimes;
	int DSymbolPos = 0;
	countSymbols(bwt, cumCount, occTimes, DSymbolPos);

	int lastColIdx = DSymbolPos;

	for (int i = 0; i < bwt.size(); i++)
	{
		text += bwt[lastColIdx];
		lastColIdx = cumCount[bwt[lastColIdx]] + occTimes[lastColIdx];
	}
	reverse(text.begin(), text.end());
	return text;
}

int main() {
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}