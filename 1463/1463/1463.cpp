#include<iostream>
#include<algorithm>

using namespace std;

int dps[10000000];

int dp(int n) {
	if (dps[n] != -1)return dps[n];

	if (n > 1) {
		if (n % 3 != 0 && n % 2 != 0)return dps[n] = dp(n - 1) + 1;
		else if (n % 3 == 0 && n % 2 != 0)return dps[n] = min(dp(n / 3), dp(n - 1)) + 1;
		else if (n % 3 != 0 && n % 2 == 0)return dps[n] = min(dp(n / 2), dp(n - 1)) + 1;
		else if (n % 3 == 0 && n % 2 == 0)return dps[n] = min(dp(n - 1), min(dp(n / 3), dp(n / 2))) + 1;
	}
}

int main() {
	int n;
	cin >> n;
	fill(dps, dps + 1000001, -1);
	dps[1] = 0;
	dps[2] = 1;
	dps[3] = 1;
	cout << dp(n);
}