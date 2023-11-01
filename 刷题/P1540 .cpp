#include<iostream>
#include<queue>
#include<map>
using namespace std;
int miss = 0;
void newFrequent(map<int, int> &Frenquence,int M=-1) {
	for (auto it = Frenquence.begin(); it != Frenquence.end(); it++) {
		Frenquence[it->first]++;
	}
	//使用过的字母频率清零
	if (M != -1) {
		Frenquence[M] = 1;
	}
		
}

int main() {
		int N, M;
		int size=0;
		cin >> M >> N;
		map<int,int> Frenquence;
		Frenquence[-1] = 100000000;
		auto compare = [&Frenquence](int a, int b) {return Frenquence[a]<Frenquence[b]; };
		priority_queue<int,vector<int>,decltype(compare)> pq(compare);
		
		
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			if (!Frenquence[temp]) {
				size++;
				miss++;
				newFrequent(Frenquence);
				Frenquence[temp] = 1;
				auto pair = Frenquence.find(temp);
				pq.push(pair->first);
			}
			else {
				newFrequent(Frenquence, temp);
				pq.push(-1);
				pq.pop();
			}
			if (size == M) {
				auto it_erase= Frenquence.find(pq.top());
				Frenquence.erase(it_erase);
				pq.pop();
				size--;
			}
		}
		cout<< miss;

	return 0;
}