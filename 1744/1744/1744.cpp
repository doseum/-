#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> seq;
	while (n > 0) {
		int tmp;
		cin >> tmp;
		seq.push_back(tmp);
		n--;
	}

	sort(seq.begin(), seq.end(), greater<int>());
	for (int i = 0; i < seq.size()-1; i++) {
		if (seq[i] > 0) {//양수
			if (seq[i] * seq[i + 1] > seq[i] + seq[i + 1]) {
				seq[i + 1] *= seq[i];
				seq.erase(seq.begin() + i);
			}
		}
		else if (seq[i] < 0) {//음수
			if ((seq.size() - 1 - i) % 2 == 1) {
				seq[i + 1] *= seq[i];
				seq.erase(seq.begin() + i);
			}
		}
		else {//0
			if ((seq.size()-1 - i) %2==1 ) {
				seq[i + 1] *= seq[i];
				seq.erase(seq.begin() + i);
			}
		}
	}

	int ans = 0;
	for (int el : seq)ans += el;
	cout << ans;
}