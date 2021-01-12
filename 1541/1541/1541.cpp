#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main() {
	
	char s[50];
	cin >> s;

	char* tmp;
	char* tok = strtok_s(s, "-",&tmp);

	while (tok != NULL) {
		char* stok = strtok_s(tok, "+", &tmp);
	}
	

}