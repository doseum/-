#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	int ans = 0;
	vector<int> bill;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp <= k) {
			bill.push_back(tmp);
		}
		else;
	}

	while (k > 0) {
		if (k >= bill.back()) {
			k -= bill.back();
			ans++;
		}
		else bill.pop_back();
	}

	cout << ans;
}