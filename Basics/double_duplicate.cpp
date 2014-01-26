#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		bool *flag = new bool[x];
		memset(flag, false, sizeof(bool) * x);
		int y = x + 2;
		while (y--) {
			int a;
			cin >> a;
			if (flag[a] == false) {
				flag[a] = true;
			}
			else {
				flag[a] = false;
			}
		}
		for (int i = 0; i < x; i++) {
			if (flag[i] == false) {
				cout << i << endl;
			}
		}
		delete[] flag;
	}
	return 0;
}


