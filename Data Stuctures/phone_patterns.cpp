#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

char convert(char x)
{
	if (x >= 'A' && x <= 'P') {
		return ((x - 'A') / 3 + 2) + '0';
	}
	if (x >= 'R' && x <= 'Y') {
		return ((x - 'A' - 1) / 3 + 2) + '0';
	}
	else {
		return x;
	}
}

string mapper(string s)
{
	string res = "";
	for (string::size_type i = 0; i != s.size(); i++) {
		if (s[i] != '-') {
			res.push_back(convert(s[i]));
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		list<string> str_list;
		int k;
		cin >> k;
		while (k--) {
			string s;
			cin >> s;
			str_list.push_back(mapper(s));
		}
		map<string, int> str_int_map;
		for (list<string>::iterator iter = str_list.begin(); iter != str_list.end(); iter++) {
			str_int_map[*iter]++;
		}
		for (map<string, int>::iterator iter = str_int_map.begin(); iter != str_int_map.end(); iter++) {
			if (iter->second >= 2) {
				string res = iter->first;
				cout << res.substr(0, 3) + "-" + res.substr(3,4) + " " << iter->second << endl ;
			}
		}
		
	}
	return 0;
}