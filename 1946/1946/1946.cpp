#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	int t;
	vector<int> ans;
	cin >> t;

	while (t > 0) {
		int n;
		cin >> n;
		vector<pair<int, int>> s;
		vector<bool> mark;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			s.push_back(make_pair(a, b));
			mark.push_back(true);
		}

		int pass = 0;
		sort(s.begin(), s.end(), cmp);

		while (!s.empty()) {
			int cut = s.back().second;
			s.pop_back();
			pass++;

			for (int idx = 0; idx < s.size(); idx++) {
				if (s[idx].second > cut) {
					s.erase(s.begin() + idx);
					idx--;
				}
			}
		}
		ans.push_back(pass);
		t--;
	}

	for (int f : ans)cout << f << endl;
}