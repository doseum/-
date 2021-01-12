#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

int main() {
	bool mark[10];
	int val[26];
	fill(val, val + 26, -1);
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

	vector<vector<char>> table;
	while (!num.empty()) {
		vector<char> tmp;
		for (int i = 0; i < num.size(); i++) {
			if(!num[i].empty()){
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

	vector<int> answer;
	for (int idx = table.size() - 1; idx >= 0; idx--) {
		//높은 자릿수 부터 합산 시작
		int sum=0;
		for (int sidx = 0; sidx < table[idx].size(); sidx++) {
			//자릿수 알파벳에 숫자가 할당안되어있으면
			if (val[table[idx][sidx] - 65] == -1) {
				for (int midx = 9; midx > -1; midx--) {
					if (!mark[midx]) {
						val[table[idx][sidx] - 65] = midx;
						mark[midx] = true;
						break;
					}
				}
			}
			sum += val[table[idx][sidx] - 65];
		}
		answer.push_back(sum);
	}

	long long f = 0;
	for (int fi = 0; fi < answer.size(); fi++) {
		f += answer[fi] * pow(10, answer.size() - fi - 1);
	}

	cout << f;
	return 0;
}