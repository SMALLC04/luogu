 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main() {
	int a, b,sum=0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		int num = i;
		int num2 = i;
		while (num2 > 10) {
			while (num > 10) {
				num = num % 10;
			}
			if (num == 2)sum++;
			num2 = num2 / 10;
			num = num2;
		}
		if (num2 == 2)sum++;
	}

	cout << sum;
	return 0;
}