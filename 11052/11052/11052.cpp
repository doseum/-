#include<iostream>

using namespace std;

int cp[1001];
int dps[1001];

int dp(int n) {
	if (dps[n] != 0)return dps[n];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		if(i>0)tmp = dp(n - i) + cp[i];
		if (i == 0)tmp = cp[n];

		if (ans < tmp)ans = tmp;
	}
	dps[n] = ans;
	return ans;
}

int main() {
	int n;
	cin >> n;

	for (int input = 1; input <= n; input++) {
		cin >> cp[input];
	}
	cout << dp(n);
}