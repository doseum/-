#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[101][10];
	for (int a = 0; a < 101; a++)fill(dp[a], dp[a] + 10, 0);
	for(int i=1;i<10;i++)dp[1][i] = 1;

	for (int j = 2; j <= n; j++) {
		dp[j][0] = dp[j - 1][1]%1000000000;
		dp[j][9] = dp[j - 1][8] % 1000000000;
		for (int k = 1; k < 9; k++) {
			dp[j][k] = (dp[j - 1][k + 1] + dp[j - 1][k - 1]) % 1000000000;
		}
	}

	int ans = 0;
	for (int it : dp[n])ans = (ans+ it) % 1000000000;
	cout << ans;
	return 0;
}