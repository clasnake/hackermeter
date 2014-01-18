#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef map< string, vector<string> > Graph;

typedef struct 
{
	int finish_time;
	int visited;
}State;

void dfs(Graph &g, string v, map<string, State*> &state, int &dfs_time)
{
	state[v]->visited = 0;
	dfs_time++;
	vector<string> adjacent = g[v];
	for (vector<string>::iterator i = adjacent.begin(); i != adjacent.end(); i++) {
		if (state[*i]->visited == -1) {
			dfs(g, *i, state, dfs_time);
		}
	}
	state[v]->visited = 1;
	dfs_time++;
	state[v]->finish_time = dfs_time;
}

bool cmp(const pair<string, State*> &x, const pair<string, State*> &y)
{
	return x.second->finish_time > y.second->finish_time;
}

int main()
{
	int T;
	cin >> T;
	while(T--) {
		Graph graph;
		map<string, State*> state;
		int finish_time = 0;
		int N;
		cin >> N;
		while (N--) {
			string x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			state[x] = new State;
			state[x]->finish_time = 0;
			state[x]->visited = -1;
			if (graph[y].empty()) {
				graph[y].clear();
				state[y] = new State;
				state[y]->finish_time = 0;
				state[y]->visited = -1;
			}
		}
		for (Graph::iterator i = graph.begin(); i != graph.end(); i++) {
			if (state[i->first]->visited == -1) {
				dfs(graph, i->first, state, finish_time);
			}
		}
		typedef vector< pair<string, State*> > ResType;
		ResType res;
		for (map<string, State*>::iterator i = state.begin(); i != state.end(); i++) {
			res.push_back(pair<string, State*>(i->first, i->second));
		}
		sort(res.begin(), res.end(), cmp);
		for (ResType::iterator i = res.begin(); i != res.end(); i++) {
			cout << i->first << endl;
		}

	}
	return 0;
}