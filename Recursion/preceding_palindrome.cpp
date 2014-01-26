#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

int reverse(int x)
{
	int r = 0;
	while (x > 0) {
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}

bool is_palindrome(int x)
{
	if (reverse(x) == x) {
		return true;
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		while (!is_palindrome(--x));
		cout << x << endl;
	}
	return 0;
}