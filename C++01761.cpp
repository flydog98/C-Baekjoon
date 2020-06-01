// 1761번 정점들의 거리

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
		//입력 단계에서는 부모 자식 관계를 알 수 없음
		Line* tempLine = new Line(nodeList[node1], nodeList[node2], weight);
		nodeList[node1]->childs.push_back(tempLine);
		nodeList[node2]->childs.push_back(tempLine);
	}

	q.push(nodeList[1]);

	while (!q.empty()) {
		now = q.front();
		q.pop();
		// 이번 노드의 부모 자식 관계 성립 완료
		for (int i = 0; i < now->childs.size(); i++) {
			now->childs.at(i)->setParent(now);
		}

		//childs 목록을 돌면서 각각의 toChild마다 bfs를 진행
		for (int i = 0; i < now->childs.size(); i++) {
			//자식의 위치 정보 업데이트
			now->childs.at(i)->toChild->location = now->location;
			now->childs.at(i)->toChild->location.push_back(char(i + '0'));
			//자식 부모 관계를 명확히 하기 위해 값을 수정
			now->childs.at(i)->setParent(now);
			q.push(now->childs.at(i)->toChild);
		}
	}
	//tree 작업 완료

	cin >> tc;
	for(; tc > 0; tc--) {
		count = 0, temp = 0;
		dist1 = 0, dist2 = 0;
		root = nodeList[1];
		cin >> node1 >> node2;

		string1 = nodeList[node1]->location;
		string2 = nodeList[node2]->location;
		
		//location이 어디까지 같은지 체크
		for (int i = 0; i < min(string1.size(), string2.size()); i++) {
			if (string1[i] == string2[i]) count++;
			else break;
		}

		//두 노드를 포함하는 최소 크기의 트리의 노드 구하기
		for (int i = 0; i < count; i++) {
			//temp == i번째의 로케이션 이름(자식 노드의 순서)
			temp = string1[i] - '0';
			//해당하는 번째의 자식 노드로 root를 이동
			root = root->childs.at(temp)->toChild;
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