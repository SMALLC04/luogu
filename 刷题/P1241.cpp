#include<iostream>
#include<stack>
#include<map>
#include<queue>
using namespace std;

bool match(char left, char right) {
	if (left == '[' && right == ']')return true;
	if (left == '(' && right == ')')return true;
	return false;
}

int main() {
	stack<char> left;
	stack<char> left_pos;
	stack<int> unmatch;
	map<int, char> ic;
	string ans;

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (left.empty()) {
			if (str[i] == ']' || str[i] == ')') {
				unmatch.push(i);
				continue;
			}
		}
		if (str[i] == '(' || str[i] == '[') {
			left.push(str[i]);
			left_pos.push(i);
		}
		else if (str[i] == ']' || str[i] == ')') {
			if (match(left.top(), str[i])) {
				left.pop();
				left_pos.pop();
				continue;
			}
			else {
				unmatch.push(i);
			}
		}
	}

	while (!left_pos.empty()) {
		unmatch.push(left_pos.top());
		left_pos.pop();
	}

	stack<int> copy=unmatch;
	while (!copy.empty()) {
		ic[copy.top()] = str[copy.top()];
		copy.pop();
	}

	priority_queue<int,vector<int>,less<int> >qp;
	while (!unmatch.empty()) {
		qp.push(unmatch.top());
		unmatch.pop();
	}
	ans = str;
	while (!qp.empty()) {
		if(ic[qp.top()] =='['){
			if (qp.top() == ans.size() - 1) {
				ans += ']';
				qp.pop();
				continue;
			}
			ans.insert(qp.top() + 1, 1, ']');
			qp.pop();
			continue;
		}
		if (ic[qp.top()] == ']') {
			ans.insert(qp.top(), 1, '[');
			qp.pop();
			continue;
		}
		if (ic[qp.top()] == '(') {
			if (qp.top() == ans.size() - 1) {
				ans += ')';
				qp.pop();
				continue;
			}
			ans.insert(qp.top() + 1, 1, ')');
			qp.pop();
			continue;
		}
		if (ic[qp.top()] == ')') {
			ans.insert(qp.top(), 1, '(');
			qp.pop();
			continue;
		}
	}
	cout << ans;
	
	return 0;
}