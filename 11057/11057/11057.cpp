#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[1001][10];
	for (int idx = 0; idx <= n; idx++)fill(dp[idx], dp[idx] + 10, 0);
	for (int i = 0; i < 10; i++)dp[1][i] = 1;

	for (int a = 2; a <= n; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c <= b; c++) {
				dp[a][b] = (dp[a][b] + dp[a - 1][c]) % 10007;
			}
		}
	}
	long long ans = 0;
	for (int it : dp[n])ans += it;
	cout << ans % 10007;
}