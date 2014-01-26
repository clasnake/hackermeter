#include <iostream>
#include <set>
using namespace std;

const int square[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

long square_sum(long x)
{
	long sum = 0;
	while (x / 10 != 0) {
		sum += square[(int)(x % 10)];
		x /= 10;
	}
	sum += square[(int)x];
	return sum;
}

bool is_happy(long x)
{
	set<long> long_set;
	while (x != 1) {
		if (long_set.count(x)) {
			return false;
		}
		long_set.insert(x);
		x = square_sum(x);
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		long x;
		cin >> x;
		if (is_happy(x)) {
			cout << "Y" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
	return 0;
}