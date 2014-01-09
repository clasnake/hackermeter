#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_sublime(string s1, string s2)
{
	stack<char> str_stk;
	for (int i = s1.size() - 1; i >= 0; i--) {
		str_stk.push(s1[i]);
	}
	for (int i = 0; i != s2.size(); i++) {
		char top = str_stk.top();
		if (s2[i] == top) {
			str_stk.pop();
		}
		if (str_stk.empty()) {
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
