#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)return a.first>b.first;
	else return a.second > b.second;
}

int main() {
	int n,m;
	int ans = 0;
	m = -1;
	cin >> n;

	vector<pair<int, int>> c;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		c.push_back(make_pair(s, e));
	}

	sort(c.begin(), c.end(), cmp);

	while (!c.empty()) {
		if (m > c.back().first) {
			c.pop_back();
			continue;
		}
		
		ans++;
		m = c.back().second;
		c.pop_back();
	}

	cout << ans;
}