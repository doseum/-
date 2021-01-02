#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> p;

int main() {
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}

	sort(p.begin(), p.end());

	for (int idx = 0; idx < p.size(); idx++) {
		ans += (p.size() - idx) * p[idx];
	}

	cout << ans;
}