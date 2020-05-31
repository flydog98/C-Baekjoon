// 1991번 트리 순회

#include <iostream>

using namespace std;

class Node {
public:
	char name;
	Node* left;
	Node* right;
};

void preorder(Node* node) {
	cout << node->name;
	if (node->left != NULL) {
		preorder(node->left);
	}
	if (node->right != NULL) {
		preorder(node->right);
	}
	return;
}

void inorder(Node* node) {
	if (node->left != NULL) {
		inorder(node->left);
	}
	cout << node->name;
	if (node->right != NULL) {
		inorder(node->right);
	}
	return;
}

void postorder(Node* node) {
	if (node->left != NULL) {
		postorder(node->left);
	}
	if (node->right != NULL) {
		postorder(node->right);
	}
	cout << node->name;
	return;
}

int main(void) {
	int amount = 0;
	char name, left, right;
	Node* tree = new Node[26];

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> name >> left >> right;
		tree[name - 'A'].name = name;
		if (left != '.') tree[name - 'A'].left = &tree[left - 'A'];
		else tree[name - 'A'].left = NULL;
		if(right != '.') tree[name - 'A'].right = &tree[right - 'A'];
		else tree[name - 'A'].right = NULL;
	}

	preorder(&tree[0]);
	cout << '\n';
	inorder(&tree[0]);
	cout << '\n';
	postorder(&tree[0]);
	cout << '\n';

	return 0;
}