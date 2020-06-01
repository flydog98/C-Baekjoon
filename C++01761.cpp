// 1761�� �������� �Ÿ�

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Node;
class Line;

class Node {
public:
	int number;
	Line* parent;
	vector<Line*> childs;
	string location;

	Node() {
		this->parent = NULL;
	}

	Node(int number) {
		this->parent = NULL;
		this->number = number;
	}
};

class Line {
public:
	Node* toParent;
	Node* toChild;
	int weight;

	Line() {
		this->toParent = NULL;
		this->toChild = NULL;
		this->weight = 0;
	}
	Line(Node* end1, Node* end2, int weight) {
		this->toParent = end1;
		this->toChild = end2;
		this->weight = weight;
	}

	void setParent(Node* parent) {
		if (parent == this->toChild) {
			// �ϴ� parent�� child�� �Է��صξ��� �͵��� ����� ����
			Node* temp = this->toParent;
			this->toParent = this->toChild;
			this->toChild = temp;
		}
		//�ڽ��� �θ� ����
		this->toChild->parent = this;

		vector<Line*>::iterator iter = this->toChild->childs.begin();
		for (int i = 0; i < this->toChild->childs.size(); i++) {
			//child�� childs �� ���ԵǾ� �ִ� child�� parent�� �����ؾ� ��
			if(this->toChild->childs.at(i) == this) {
				this->toChild->childs.erase(iter);
				break;
			}
			iter++;
		}
	}
};

int main(void) {
	int nodeAmount = 0;
	int node1, node2, weight;
	Node* now;
	Node** nodeList = NULL;
	queue<Node*> q;

	int count = 0, temp = 0, ans = 0, tc = 0;
	int dist1 = 0, dist2 = 0;
	Node* root;
	string string1, string2;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodeAmount;

	nodeList = new Node*[nodeAmount + 1];

	for (int i = 1; i < nodeAmount + 1; i++) {
		nodeList[i] = new Node(i);
	}

	for (int i = 0; i < nodeAmount - 1; i++) {
		cin >> node1 >> node2 >> weight;
		//�Է� �ܰ迡���� �θ� �ڽ� ���踦 �� �� ����
		Line* tempLine = new Line(nodeList[node1], nodeList[node2], weight);
		nodeList[node1]->childs.push_back(tempLine);
		nodeList[node2]->childs.push_back(tempLine);
	}

	q.push(nodeList[1]);

	while (!q.empty()) {
		now = q.front();
		q.pop();
		// �̹� ����� �θ� �ڽ� ���� ���� �Ϸ�
		for (int i = 0; i < now->childs.size(); i++) {
			now->childs.at(i)->setParent(now);
		}

		//childs ����� ���鼭 ������ toChild���� bfs�� ����
		for (int i = 0; i < now->childs.size(); i++) {
			//�ڽ��� ��ġ ���� ������Ʈ
			now->childs.at(i)->toChild->location = now->location;
			now->childs.at(i)->toChild->location.push_back(char(i + '0'));
			//�ڽ� �θ� ���踦 ��Ȯ�� �ϱ� ���� ���� ����
			now->childs.at(i)->setParent(now);
			q.push(now->childs.at(i)->toChild);
		}
	}
	//tree �۾� �Ϸ�

	cin >> tc;
	for(; tc > 0; tc--) {
		count = 0, temp = 0;
		dist1 = 0, dist2 = 0;
		root = nodeList[1];
		cin >> node1 >> node2;

		string1 = nodeList[node1]->location;
		string2 = nodeList[node2]->location;
		
		//location�� ������ ������ üũ
		for (int i = 0; i < min(string1.size(), string2.size()); i++) {
			if (string1[i] == string2[i]) count++;
			else break;
		}

		//�� ��带 �����ϴ� �ּ� ũ���� Ʈ���� ��� ���ϱ�
		for (int i = 0; i < count; i++) {
			//temp == i��°�� �����̼� �̸�(�ڽ� ����� ����)
			temp = string1[i] - '0';
			//�ش��ϴ� ��°�� �ڽ� ���� root�� �̵�
			root = root->childs.at(temp)->toChild;
		}

		//root�� ���� ������ weight�� ���ϸ� �θ�� �̵�
		now = nodeList[node1];
		while (!(now == root)) {
			dist1 += now->parent->weight;
			now = now->parent->toParent;
		}
		now = nodeList[node2];
		while (!(now == root)) {
			dist2 += now->parent->weight;
			now = now->parent->toParent;
		}
		ans = dist1 + dist2;
		cout << ans << '\n';
	}


	return 0;
}