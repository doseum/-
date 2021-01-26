#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[91];
	fill(dp, dp + 91, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}