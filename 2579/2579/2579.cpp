#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dps[300];
vector<int> s;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		s.push_back(tmp);
	}

	dps[0] = s[0];
	dps[1] = s[0] + s[1];
	dps[2] = max(s[2] + s[0], s[2]+s[1]);

	for (int idx = 3; idx < n; idx++)dps[idx] = max(s[idx] + s[idx - 1] + dps[idx - 3], s[idx] + dps[idx - 2]);

	cout << dps[n - 1];
}