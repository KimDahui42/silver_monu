#include <iostream>
using namespace std;
int main() {
	int dp[1001][1001] = { 0, };
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k && j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k]<<'\n';
	return 0;
}

//dp[n][k]=dp[n-1][k-1]+dp[n-1][k]
