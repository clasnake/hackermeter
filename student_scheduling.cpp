#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node
{
	int time;
	int due;
}task_node;

bool cmp(task_node a, task_node b)
{
	return a.due < b.due;
}

bool is_possible(task_node *a, int n)
{
	sort(a, a + n, cmp);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].time > a[i].due - sum) {
			return false;
		}
		sum += a[i].time;
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	while (N--) {
		int X;
		cin >> X;
		task_node *a = new task_node[X];
		for (int i = 0; i < X; i++) {
			cin >> a[i].time >> a[i].due;
		}
		if (is_possible(a, X))
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
		delete [] a;
	}
	return 0;
}