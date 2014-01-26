#include <iostream>
#include <string>
using namespace std;

bool is_sublime(string s1, string s2)
{
	string::size_type p = 0;
	for (string::size_type i = 0; i < s2.size(); i++) {
		if (s2[i] == s1[p]) {
			p++;
		}
		if (p == s1.size()) {
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (is_sublime(s1, s2)) {
			cout << "sublime" << endl;
		}
		else {
			cout << "unsublime" << endl;
		}
	}
	return 0;
}
