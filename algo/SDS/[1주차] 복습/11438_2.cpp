#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int n_ = 1e5 + 5;
const int d_ = 17;

int n, m, d;
int dph[n_], act[n_][d_];
vector<int> gph[n_];

inline void dfs(int now, int cnt) {
	dph[now] = cnt++;
	for (int i = 1; i <= d; i++)
		act[now][i] = act[act[now][i - 1]][i - 1];
	vector<int>::iterator nxt;
	for (nxt=gph[now].begin(); nxt!=gph[now].end(); nxt++) if (!dph[*nxt])
		act[*nxt][0] = now, dfs(*nxt, cnt);
}

int main() {
	int i, a, b;
	scanf("%d", &n);
	for (d = 1; (1 << d) <= n; d++); d--;
	while (--n) {
		scanf("%d %d", &a, &b);
		gph[a].push_back(b);
		gph[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		if (dph[a] < dph[b]) swap(a, b);
		for (i = d; i >= 0; i--) if (dph[b] <= dph[act[a][i]])
			a = act[a][i];
		if (a == b) {
			printf("%d\n", a);
			continue;
		}
		for (i = d; i >= 0; i--) if (act[a][i] != act[b][i])
			a = act[a][i], b = act[b][i];
		printf("%d\n", act[a][0]);
	}
	
	

	return 0;
}
