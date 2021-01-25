#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> w;
int dp[10000];


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		w.push_back(tmp);
	}
	
	dp[0] = w[0];
	dp[1] = w[1] + w[0];
	dp[2] = max(max(w[2] + w[0], w[2] + w[1]),dp[1]);

	for (int idx = 3; idx < n; idx++)dp[idx] = max(max(w[idx] + dp[idx - 2], w[idx] + w[idx - 1] + dp[idx - 3]),dp[idx-1]);

	sort(dp, dp + n);
	cout << dp[n - 1];
}