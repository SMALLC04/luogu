#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>

using namespace std;

stack<int>num;
int Num;
char c;
int Num2;
char str[100];
char  ccty[21];
int flag = 0, i;
int numa, numb;
int makenum() {
	int ret = 0;
	for (int i = 0; i <= strlen(ccty) - 1; i++) {
		if (ccty[i] == '*')break;
		ret = ret * 10 + ccty[i] - '0';
		ccty[i] = '*';
	}
	return ret;
}

int main() {
	cin >> str;
	char cha;
	cha = str[0];
	int k = 0;
	while (cha != '@') {
		if (flag == 0)i = 0;
		if (cha >= '0' && cha <= '9') {
			flag = 1;
			ccty[i] = cha;
			i++;
		}
		else if (cha == '.') {
			flag = 0;
			Num = makenum();
			num.push(Num);
		}
		else {
			numa = num.top();
			num.pop();
			numb = num.top();
			num.pop();
			if (cha == '+')num.push(numa + numb);
			if (cha == '*')num.push(numa * numb);
			if (cha == '-')num.push(numb - numa);
			if (cha == '/')num.push(numb / numa);

		}
		k++;
		cha = str[k];

	}
	cout << num.top();


	return 0;
}