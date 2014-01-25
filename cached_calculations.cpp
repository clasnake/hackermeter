#include <iostream>
using namespace std;

long long solve(int n)
{
    long long *res = new long long[n + 1];
    switch (n) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 6;
    }
    res[1] = 1;
    res[2] = 2;
    res[3] = 3;
    res[4] = 6;
    for (int i = 5; i <= n; i++) {
        res[i] = res[i - 1] + res[i - 2] + res[i - 4];
    }
    long long x = res[n];
    delete [] res;
    return x;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
