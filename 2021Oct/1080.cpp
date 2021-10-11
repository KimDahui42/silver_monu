#include <iostream>
#include <cstdio>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#define endl '\n'
using namespace std;
int main() {//모두 0으로 만들기->1만나면 전부 뒤집음
	int n, m, cnt = 0, tmp;
	bool flag = true;
	cin >> n >> m;
	vector<vector<bool>>map(n, vector<bool>(m));
	vector<vector<bool>>cmp(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp);
			map[i][j] = (tmp == 1) ? true : false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp);
			cmp[i][j] = (tmp == 1) ? true : false;
		}
	}
	//외곽에서부터 처리
	for (int i = n - 1; i >= 2; i--) {
		for (int j = m - 1; j >= 2; j--) {
			if (map[i][j]!=cmp[i][j]) {
				cnt++;
				for (int k = i-2; k <= i; k++) {
					for (int l = j-2; l <= j; l++) {
						map[k][l] = !map[k][l];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != cmp[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
