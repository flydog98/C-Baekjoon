// 1761번 정점들의 거리 메모리 초과를 해결해야 한다
// 메모리 초과를 해결했더니 시간 초과를 해결해야 한다

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
	vector<Node*> ancestor;
	vector<Line*> childs;
	int depth;
	int weightToParent;

	Node() {}

	Node(int number) {
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

	void setTree(Node* parent) {
		if (parent == this->toChild) {
			// 일단 parent와 child로 입력해두었던 것들을 제대로 정리
			Node* temp = this->toParent;
			this->toParent = this->toChild;
			this->toChild = temp;
		}

		//자식의 부모를 설정
		this->toChild->parent = this;

		vector<Line*>::iterator iter = this->toChild->childs.begin();
		for (int i = 0; i < this->toChild->childs.size(); i++) {
			//child의 childs 중 포함되어 있는 child의 parent를 제거해야 함
			if (this->toChild->childs.at(i) == this) {
				this->toChild->childs.erase(iter);
				break;
			}
			iter++;
		}
	}

	void setAncestor(Node* parent) {
		Node* nowGrand = this->toChild;
		/*
		int tt = 2, cc = 0;
		while (1) {
			if (this->toChild->depth < tt * 2) {
				break;
			}
			tt *= 2;
			cc++;
		}
		int jj = 1;
		for (int i = 0; i < cc; i++) {
			if (jj == 1) {
				for (int j = 0; j < 2; j++) {
					nowGrand = nowGrand->parent->toParent;
				}
			}
			else {
				for (int j = 0; j < jj; j++) {
					nowGrand = nowGrand->parent->toParent;
				}
			}
			this->toChild->ancestor.push_back(nowGrand);
			jj *= 2;
		}
		*/

		int nowReading = 3;

		for (int i = 2; nowReading <= this->toChild->depth; i *= 2) {

			for (int j = 0; j < i; j++) {
				nowGrand = nowGrand->parent->toParent;
			}
			this->toChild->ancestor.push_back(nowGrand);
			nowReading += i * 2;
			
		}
		
		/*
		grandParent = this->toParent->parent->toParent;
		this->toChild->ancestor.push_back(grandParent);
		for (int i = 0; i < this->toChild->ancestor.size(); i++) {
			this->toChild->ancestor.push_back(grandParent->ancestor[i]);
		}
		*/


	}
};

Node* findingAncestor(Node* now, int count) {
	if (count == 0) return now;
	if (count == 1) return now->parent->toParent;

	int i = -1, temp = 1, nowReading = 2;
	for (; nowReading <= count; i++) {
		temp *= 2;
		nowReading += temp;
	}

	return findingAncestor(now->ancestor[i], count - temp);
}

Node* findingCommonAncestor(Node* temp1, Node* temp2) {
	if (temp1 == temp2) return temp1;
	if (temp1->parent->toParent == temp2->parent->toParent) return temp1->parent->toParent;
	int i = 0;
	for ( ; i < temp1->ancestor.size(); i++) {
		if (temp1->ancestor[i] == temp2->ancestor[i]) {
			break;
		}
	}
	if (i == 0) return temp1->ancestor[0];
	else return findingCommonAncestor(temp1->ancestor[i - 1], temp2->ancestor[i - 1]);
}

int main(void) {
	int nodeAmount = 0;
	int node1, node2, weight;
	Node* now;
	Node** nodeList = NULL;
	queue<Node*> q;

	int count = 0, temp = 0, ans = 0, tc = 0, flag = 0;
	int dist1 = 0, dist2 = 0;
	Node* root;
	Node* temp1, *temp2;
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
		//입력 단계에서는 부모 자식 관계를 알 수 없음
		Line* tempLine = new Line(nodeList[node1], nodeList[node2], weight);
		nodeList[node1]->childs.push_back(tempLine);
		nodeList[node2]->childs.push_back(tempLine);
	}

	nodeList[1]->depth = 1;
	q.push(nodeList[1]);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < now->childs.size(); i++) {
			//자식 부모 관계를 명확히 하기 위해 값을 수정
			now->childs.at(i)->setTree(now);
			now->childs.at(i)->toChild->depth = now->depth + 1;
			now->childs.at(i)->setAncestor(now);
			q.push(now->childs.at(i)->toChild);
		}
	}

	cin >> tc;
	for (; tc > 0; tc--) {
		count = 0, temp = 0;
		dist1 = 0, dist2 = 0;
		root = nodeList[1];
		flag = 0;
		cin >> node1 >> node2;

		//같은 depth가 될 때까지 한 쪽을 올린다.
		temp1 = nodeList[node1];
		temp2 = nodeList[node2];
		if (node1 == 1 || node2 == 1) { // 한 쪽이라도 1인 경우 1이 root이다
			root = nodeList[1];
		}
		else {
			count = temp1->depth - temp2->depth;
			if (count < 0) flag = 1; // temp2가 더 깊다
			count = abs(count);

			// depth가 더 깊은 쪽에서 depth가 같아질 때까지 이동
			if (flag) temp2 = findingAncestor(temp2, count);
			else temp1 = findingAncestor(temp1, count);
			

			if (temp1 == temp2) { // 올라와 보니 이미 같은 경우
				root = temp1;
			}
			else {
				root = findingCommonAncestor(temp1, temp2);
				/*
				while (!(temp1->parent->toParent == temp2->parent->toParent)) {
					// 부모가 같을 때까지 depth를 올리는 방향으로
					temp1 = temp1->parent->toParent;
					temp2 = temp2->parent->toParent;
				}
				root = temp1->parent->toParent;
				*/
			}
		}

		//root가 나올 때까지 weight을 더하며 부모로 이동
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