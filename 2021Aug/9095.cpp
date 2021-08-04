#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t, n;
	vector<int>dp(12, 0);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	cin >> t;
	while (t--) {
		cin >> n;
		if (dp[n] != 0) {
			cout << dp[n] << '\n';
			continue;
		}
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
	return 0;
}
