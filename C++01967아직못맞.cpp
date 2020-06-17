// 1967�� Ʈ���� ����

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Node {
public:
	int number;
	int parentWeight;
	Node* parent;
	Node* bestChild;
	vector<Node*> childs;
	vector<int> childsWeight;
	int first;
	int second;

	Node(int i) {
		this->number = i;
		this->parent = NULL;
		this->bestChild = NULL;
		this->parentWeight = 0;
		this->first = -1;
		this->second = -1;
	}
};

int main(void) {
	int amount;
	int parent, child, weight;
	int thebest;
	Node** nodelist = NULL;
	stack<int> q;
	queue<int> qq;


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> amount;
	
	nodelist = new Node*[amount + 1];
	for (int i = 1; i < amount + 1; i++) {
		nodelist[i] = new Node(i);
	}

	for (int i = 0; i < amount - 1; i++) {
		cin >> parent >> child >> weight;
		nodelist[parent]->childs.push_back(nodelist[child]);
		nodelist[parent]->childsWeight.push_back(weight);
		nodelist[child]->parent = nodelist[parent];
		nodelist[child]->parentWeight = weight;
	}

	q.push(1);

	while (!q.empty()) {
		int now = q.top();
		Node* nownode = nodelist[now];
		int first = 0, second = 0, temp;

		if (nownode->first == -1) { // ù �湮
			for (int i = nownode->childs.size() - 1; i >= 0; i--) {
				q.push(nownode->childs[i]->number);
			}
		}
		else { // �� ��° �湮, �� �ڽ� ��尡 �� ������
			for (int i = 0; i < nownode->childs.size(); i++) {
				//for ���� ���鼭 ���� ū �� ��带 ����
				temp = nownode->childs[i]->first + nownode->childsWeight[i];
				if (temp > first) {
					nownode->bestChild = nownode->childs[i];
					second = first;
					first = temp;
				}
				else if (temp > second) second = temp;
			}


			q.pop(); // now�� ���ÿ��� ����
		}
		nownode->first = first;
		nownode->second = second;

	}

	qq.push(1);
	while (!qq.empty()) { // bfs�� ���鼭 ����� �θ�� ���� ��� �ڽ����� ���� ����� ��
		Node* nownode = nodelist[qq.front()];
		qq.pop();

		int toParent = 0;

		for (int i = 0; i < nownode->childs.size(); i++) {
			qq.push(nownode->childs[i]->number);
		}

		if (nownode->parent == NULL) {}
		else if (nownode->parent->bestChild != nownode) {
			//�θ��� bestChild�� �̹� ��尡 �ƴ� ���
			toParent = nownode->parent->first + nownode->parentWeight;
		}
		else {
			//bestChild�� �̹� ����� ���
			toParent = nownode->parent->second + nownode->parentWeight;
		}

		if (nownode->second > toParent) {
			thebest = max(thebest, nownode->first + nownode->second);
		}
		else {
			thebest = max(thebest, nownode->first + toParent);
		}

	}

	cout << thebest << '\n';


	return 0;
}