 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;
queue<int> mqueue;

void replace(int &Max, int max) {
	if (max > Max) Max = max;
}
int main() {
	int N,Max=1,m_max=1;
	cin >> N;
	int a;
	cin >> a;
	mqueue.push(a);
	for (int i = 0; i < N - 1; i++) {
		int n;
		cin >> n;
		if (n>mqueue.front()) {
			m_max++;
		}
		else {
			replace(Max, m_max);
			m_max = 1;
		}
		mqueue.pop();
		mqueue.push(n);
	}
	replace(Max, m_max);
	cout << Max;
	return 0;
}
