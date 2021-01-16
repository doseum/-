#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dps[100000];
vector<int> seq;

int dp(int idx) {
	if (dps[idx] != -1001)return dps[idx];

	if (idx == seq.size() - 1) {
		if (seq[idx] < 0)return dps[idx] = 0;
		else return dps[idx] = seq[idx];
	}

	return dps[idx]=max(seq[idx] + dp(idx + 1),0);
}

int main() {
	int n;
	cin >> n;
	fill(dps, dps + n, -1001);

	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		seq.push_back(tmp);
	}

	dp(0);
	sort(dps, dps + n, greater<int>());
	if (dps[0] == 0) {
		sort(seq.begin(), seq.begin() + n);
		cout << seq[n-1];
	}
	else cout << dps[0];
}