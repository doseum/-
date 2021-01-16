#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> w;
int dps[10000];

int dp(int idx) {
	if (dps[idx] != -1)return dps[idx];

	if (idx == w.size() - 1) return dps[idx] = w[idx];

	if (idx < w.size() - 3)return dps[idx] = max((w[idx] + w[idx + 1] + dp(idx + 3)), w[idx] + dp(idx + 2));
	else if (idx == w.size() - 3)return dps[idx] = w[idx] + max(w[idx + 1], dp(idx + 2));
	else return dps[idx] = w[idx] + w[idx + 1];
}

int main() {
	int n;
	cin >> n;

	fill(dps, dps + n, -1);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		w.push_back(tmp);
	}
	
	for (int idx = 0; idx < n; idx++)dp(idx);
	sort(dps, dps + n, greater<int>());
	cout << dps[0];
}