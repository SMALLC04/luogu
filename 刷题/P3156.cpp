 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> stu_list;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		stu_list.push_back(num);
	}

	for (int i = 0; i<m; i++) {
		int ask;
		cin >> ask;
		cout << stu_list[ask-1] << endl;
	}
	return 0;
}