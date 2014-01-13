#include <iostream>
#include <algorithm>
using namespace std;

bool zero(int *a, int n)
{
	int *b = new int[n];
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
		if (zero(a, k)) {
			cout << "zero" << endl;
		}
		else {
			cout << "nonzero" << endl;
		}
	}
	return 0;
}