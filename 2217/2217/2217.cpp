#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> rope;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		rope.push_back(tmp);
	}

	sort(rope.begin(), rope.end());

	int ans = 0;
	for (int idx = 0; idx < rope.size(); idx++) {
		if (ans < (rope.size() - idx) * rope[idx])ans = (rope.size() - idx) * rope[idx];
	}

	cout << ans;
}