#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	char data = '\0';
	int freq = 0;
	bool slot = false;
	Node* right = NULL;
	Node* left = NULL;
	Node() {}
	Node(char x, int y) {
		data = x;
		freq = y;
	}
};
struct Var {
	char letter = '\0';
	string str = "";
};
Node* ExtractMin(vector<Node*> &C) {
	Node* min = new Node();
	min->freq = 2147483647;
	int x = 0;
	for (int i = 0; i < C.size(); i++) {
		if (min->freq > C[i]->freq && C[i]->slot == false) {
			min->freq = C[i]->freq;
			min->data = C[i]->data;
			x = i;
		}
	}
	if (C[x]->data != '\0') {
		C.erase(C.begin() + x);
		return min;
	} else if (C[x]->slot == false) {
		delete min;
		C[x]->slot = true;
		return C[x];
	} else
		return NULL;
}
void BST(Node* C, Node* root, Var* Q, string T, int i) {
	if (C == NULL)
		return;
	if (C->data != '\0' && Q[i].letter == C->data) {
		Q[i].str = T;
		i++;
		BST(root, root, Q, "", i);
	}
	else {
		BST(C->left, root, Q, T + "0", i);
		BST(C->right, root, Q, T + "1", i);
	}
}
void Snapshot(vector<Node*> C) {
	Var* Q = new Var[6];
	for (int i = 0; i < 6; i++)
		Q[i].letter = (char)(65 + i);
	BST(C[C.size() - 1], C[C.size() - 1], Q, "", 0);
	for (int i = 0; i < 6; i++)
		cout << Q[i].letter << ":" << Q[i].str << endl;
}
void Huffman(vector<Node*> C) {
	for (int i = 0; i < 6; i++) {
		Node* z = new Node();
		z->left = ExtractMin(C);
		if (z->left == NULL)
			goto done;
		z->right = ExtractMin(C);
		if (z->right == NULL)
			goto done;
		z->freq = z->right->freq + z->left->freq;
		C.push_back(z);
	}done:
	Snapshot(C);
}
int main(int argc, char **argv) {
	vector<Node*> Sequence;
	for (int i = 0; i < 6; i++) {
		int num;
		cin >> num;
		Node* temp = new Node((char)(65 + i), num);
		Sequence.push_back(temp);
	}
	Huffman(Sequence);
	return 0;
}