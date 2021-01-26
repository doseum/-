#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
int dp[1000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	dp[0] = 1;
	for (int j = 1; j < n; j++) {
		int m = 0;
		for (int k = j - 1; k > -1; k--) {
			if (arr[j] > arr[k]) m = max(m, dp[k]);
		}
		dp[j] = m + 1;
	}
	
	sort(dp, dp + n);
	cout << dp[n - 1];
}