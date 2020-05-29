// 1260¹ø DFS¿Í BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
	int number;
	int isvisit;
	vector<node*> dest;
	node() {
		isvisit = 0;
	}
	void dfs() {
		this->isvisit = 1;
		cout << this->number << ' ';
		for (int i = 0; i < this->dest.size(); i++) {
			if (!this->dest[i]->isvisit) {
				dest[i]->dfs();
			}
		}
	}
	void bfs() {
		queue<node*> q;
		this->isvisit = 1;
		q.push(this);
		while (!q.empty()) {
			node* temp = q.front();

			q.pop();
			cout << temp->number << ' ';

			for (int i = 0; i < temp->dest.size(); i++) {
				if (!temp->dest[i]->isvisit) {
					temp->dest[i]->isvisit = 1;
					q.push(temp->dest[i]);
				}
			}
		}
	}
};


void merge(vector<node*>* vec) {
	if (vec->size() <= 1) return;

	vector<node*>* part1 = NULL, *part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<node*>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<node*>(half + 1);
	else part2 = new vector<node*>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (int i = 0; i < size; i++) {
		if (j < part1->size() && k < part2->size()) {
			if (part1->at(j)->number < part2->at(k)->number) {
				vec->at(i) = part1->at(j);
				j++;
			}
			else {
				vec->at(i) = part2->at(k);
				k++;
			}
		}
		else if (j >= part1->size()) {
			vec->at(i) = part2->at(k);
			k++;
		}
		else if (k >= part2->size()) {
			vec->at(i) = part1->at(j);
			j++;
		}
	}

	delete part1;
	delete part2;
}

int main(void) {
	int nodes = 0, lines = 0, start = 0;
	int temp1, temp2;
	node* graph;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodes >> lines >> start;

	graph = new node[nodes + 1];
	for (int i = 1; i < nodes + 1; i++) {
		graph[i].number = i;
	}

	for (int i = 0; i < lines; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].dest.push_back(&graph[temp2]);
		graph[temp2].dest.push_back(&graph[temp1]);
	}

	for (int i = 1; i < nodes + 1; i++) {
		merge(&(graph[i].dest));
	}

	graph[start].dfs();
	
	for (int i = 1; i < nodes + 1; i++) {
		graph[i].isvisit = 0;
	}

	cout << '\n';
	graph[start].bfs();


	return 0;
}