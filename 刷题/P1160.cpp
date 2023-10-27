 #define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using namespace std;


class node {
public:
	int data;
	node* front;
	node* last;
public:
	node() {
		data = 0;
		front = last = NULL;
	}
	node(int m_data) {
		data = m_data;
		front = last = NULL;
	}
};

map<int, node*> stu_index;
class DList {
private:
	node* head;
public:
	DList(int data) {
		head = new node();
		node* m_node = new node(data);
		stu_index[data] = m_node;
		head->last = head->front = m_node;
		m_node->front = m_node->last = head;
	}
	//node* find(int data) {
	//	node* cur = head->last;
	//	node* cur_back = head->front;
	//	while (1) {
	//		if (cur->data==0||cur_back==0) return NULL;
	//		if (data==cur->data)return cur;
	//		if (cur_back->data == data)return cur_back;
	//		cur = cur->last;
	//		cur_back = cur_back->front;
	//	}
	//	
	//}
	//将i号同学插入到k号同学的左边
	void insert_left(int i,int k) {
		node* newnode = new node(i);
		stu_index[i] = newnode;
		node* index = stu_index[k];
		newnode->front = index->front;
		newnode->last = index->front->last;
		index->front->last = newnode;
		index->front = newnode;
	}
	//将i号同学插入到k号同学的右边
	void insert_right(int i, int k) {
		node* newnode = new node(i);
		stu_index[i] = newnode;
		node* index = stu_index[k];
		newnode->front = index;
		newnode->last = index->last;
		index->last->front = newnode;
		index->last = newnode;
	}

	void remove(int x) {
		node* removenode = stu_index[x];
		if (removenode == NULL) return;
		removenode->front->last = removenode->last;
		removenode->last->front = removenode->front;
		delete removenode;
		stu_index.erase(x);
	}
	node* gethead() {
		return head;
	}
};

int main() {
	int N;
	cin >> N;
	DList stu_list(1);
	for (int i = 2; i <= N; i++) {
		int k, p;
		cin >> k >> p;
		if (p == 0) stu_list.insert_left(i, k);
		if (p == 1) stu_list.insert_right(i, k);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;
		stu_list.remove(m);
	}
	node* cur = stu_list.gethead()->last;
	while (cur->data != 0) {
		cout << cur->data << " ";
		cur = cur->last;
	}


	return 0;
}