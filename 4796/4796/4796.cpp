#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> a;

	while(true) {
		int l, p, v;
		int ans = 0;

		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)break;

		if (v % p <= l)ans += (v / p) * l + (v % p);
		else ans += (v / p) * l + l;

		a.push_back(ans);
	} 
	
	int idx = 1;
	for (int f : a) {
		cout << "Case " << idx << ": " << f << endl;
		idx++;
	}
	return 0;
}