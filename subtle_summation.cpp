#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool zero_1(int *a, int n)
{
	long *b = new long[n];
	b[0] = a[0];
	if (a[0] == 0) {
		return true;
	}
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	sort(b, b + n);

	for (int i = 1; i < n; i++) {
		if (b[0] == 0) {
			return true;
		}
		if (b[i] == b[i - 1]) {
			return true;
		}
	}
	delete [] b;
	return false;
}

bool zero_2(int *a, int n)
{
	long *b = new long[n];
	b[0] = a[0];
	if (a[0] == 0) {
		return true;
	}
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	map<long, int> long_int_map;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			return true;
		}
		if (!long_int_map.count(b[i])) {
			long_int_map.insert(pair<long, int>(b[i], 1));
		}
		else {
			long_int_map[b[i]]++;
		}
	}
	for (map<long, int>::iterator iter = long_int_map.begin(); iter != long_int_map.end(); iter++) {
		if (iter->second >= 2) {
			return true;
		}
	}
	delete [] b;
	return false;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		int *a = new int[k];
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		if (zero_2(a, k)) {
			cout << "zero" << endl;
		}
		else {
			cout << "nonzero" << endl;
		}
		delete [] a;
	}
	return 0;
}