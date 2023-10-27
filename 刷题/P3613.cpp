 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	map<long long, int>box;
	vector<int> answer;
	for(int i = 0; i < q; i++) {
		int oper;
		cin >> oper;
		if (oper == 1) {
			int i, j, object;
			cin >> i >> j >> object;
			box[i * 100000 + j] = object;
		}
		else if (oper == 2) {
			int i1, j1;
			cin >> i1 >> j1;
			answer.push_back(box[i1 * 100000 + j1]);
		}
	}

	
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}