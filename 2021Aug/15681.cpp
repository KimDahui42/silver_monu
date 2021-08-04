#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>tree[100001];
int treeDP[100001] = { 0, };
bool visited[100001] = { false, };
int dp(int start) {
	bool isLeaf = true;
	int cnt = 0;
	for (int i = 0; i < tree[start].size(); i++) {
		int next = tree[start][i];
		if (!visited[next]) {
			visited[next] = true;
			cnt += dp(next);
			isLeaf = false;
		}
	}
	if (isLeaf)return 1;
	treeDP[start] = cnt;
	return treeDP[start] + 1;
}
int main() {
	int n, r, q;
	cin >> n >> r >> q;
	while (--n) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	visited[r] = true;
	dp(r);
	while (q--) {
		int node;
		scanf("%d",&node);
		printf("%d\n",treeDP[node]+1);
	}
	return 0;
}
