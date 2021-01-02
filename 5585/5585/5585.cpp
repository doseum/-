#include<iostream>

using namespace std;

int price;
int cnt[6];

int main() {
	cin >> price;
	int ans = 0;

	int change = 1000 - price;

	while (change > 0) {
		if (change >= 500) {
			change -= 500;
			cnt[0]++;
			continue;
		}
		else if (change >= 100) {
			change -= 100;
			cnt[1]++;
			continue;
		}
		else if (change >= 50) {
			change -= 50;
			cnt[2]++;
			continue;
		}
		else if (change >= 10) {
			change -= 10;
			cnt[3]++;
			continue;
		}
		else if (change >= 5) {
			change -= 5;
			cnt[4]++;
			continue;
		}
		else if (change >= 1) {
			change -= 1;
			cnt[5]++;
			continue;
		}
	}

	for (int c : cnt)ans += c;

	cout << ans;
}