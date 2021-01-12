#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	bool mark[10];
	int val[26];
	fill(val, val + 26, 0);
	fill(mark, mark + 10, false);

	int n;
	cin >> n;
	vector<string> num;

	while (n > 0) {
		string tmp;
		cin >> tmp;
		num.push_back(tmp);
		n--;
	}

	//입력받은 num을 자릿수 별로 분해해서 table을 만든다
	vector<vector<char>> table;
	while (!num.empty()) {
		vector<char> tmp;
		for (int i = 0; i < num.size(); i++) {
			if (!num[i].empty()) {
				tmp.push_back(num[i].back());
				num[i].pop_back();
				if (num[i].empty()) {
					num.erase(num.begin() + i);
					i--;
				}
			}
		}
		table.push_back(tmp);
	}

	for (int idx = 0; idx <table.size(); idx++) {
		for (int sidx = 0; sidx < table[idx].size(); sidx++) {
			val[table[idx][sidx] - 65] += pow(10, idx);
		}
		
	}

	sort(val, val + 26,greater<int>());
	long long f = 0;
	for (int vi = 0; vi < 10; vi++) {
		f += val[vi] * (9 - vi);
	}

	cout << f;
	return 0;
}