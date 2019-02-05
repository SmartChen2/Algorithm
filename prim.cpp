#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int SIZE = 1000;
const int INF = 10000000;

int map[SIZE][SIZE];
bool vis[SIZE];

int N, M;
int ans = 0;

void prim(int s) {
	priority_queue<P, vector<P>, greater<P> > pq;

	pq.push(P(0, s));
	fill(vis, vis + N, 0);
	
	while (!pq.empty()) {
		P p = pq.top();
		pq.pop();
		int id = p.second, cost = p.first;
		if (vis[id]) continue;
		vis[id] = 1;

		ans += cost;
		for (int i = 0; i < N; i++) {
			if (map[id][i] >= INF) continue;
			if (vis[i]) continue;
			pq.push(P(map[id][i], i));
		}
	}
	
}

int main() {
	cin >> N >> M;
	
	fill(map[0], map[0] + SIZE * SIZE, INF);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		if (a == b) continue;
		map[a][b] = map[b][a] = min(map[a][b], c);
	}
	
	prim(0);
	for (int i = 0; i < N; i++)
		if (!vis[i]) ans = -1;
	
	printf("%d\n", ans);
	
	return 0;
}
