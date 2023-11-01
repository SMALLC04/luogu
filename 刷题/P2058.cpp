#include<iostream>
#include<queue>
#include<map>
using namespace std;
class human {
public:
	int time;
	int country;
public:
human(int t, int c) {
		time = t;
		country = c;
	}
};

int main() {
	int ans=0;
	int ans_all[100001];
	queue<human> ship;
	map<int, int> country;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time,p;
		cin >> time >> p;
		for (int j = 0; j < p; j++) {
			int c;
			cin >> c;
			country[c]++;
			if(country[c] == 1) ans++;
			ship.push(human(time, c));
		}
		while (ship.front().time + 86400 <= time) {
			country[ship.front().country]--;
			if(country[ship.front().country] == 0) ans--;
			ship.pop();
			if(ship.front().time + 86400 > time) break;
		}
		ans_all[i] = ans;
	}
	for (int i = 0; i < n; i++) {
		cout << ans_all[i] << endl;
	}
	
	return 0;
}