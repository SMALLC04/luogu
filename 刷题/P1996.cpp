 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;


int main() {
	queue<int> circle;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		circle.push(i);
	}
	int num;
	cin >> num;
	while (!circle.empty()) {
		int j = 1;
		while (j != num) {
			int temp = circle.front();
			circle.pop();
			circle.push(temp);
			j++;
		}
		cout << circle.front() << ' ';
		circle.pop();
	}

	return 0;
}
