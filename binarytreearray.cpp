#include <iostream>
#define complete_node  16
using namespace std;
string tree[complete_node] = { "\0", "ffff", "112", "12", "asd", "gf", "1" };
// magadir gahat test vared shode niazy be varad kardan dar kod nadarad
class binarytreearay
{
public:
	void SetLeftChild(string, int);
	int GetLeftChild(int);
	void SetRight(string, int);
	int GetRightChild(int);
	void PrintLeftChild(int);
	void PrintRightChild(int);
	void Preorder(int);
	void Inorder(int);
	void Postorder(int);
};

void binarytreearay::SetLeftChild(string key, int parent) {
	if (tree[parent] == "\0")
		cout << "nemitavan dar" << (parent * 2) + 1 << "garar dad valed nadarad";
	else
		tree[(parent * 2) + 1] = key;
	return;
}

void binarytreearay::SetRight(string key, int parent) {
	if (tree[parent] == "\0")
		cout << "nemitavan dar" << (parent * 2) + 2 << "garar dad valed nadarad";
	else
		tree[(parent * 2) + 2] = key;
	return;
}

int binarytreearay::GetRightChild(int index) {
	if (tree[index] != "\0" && ((2 * index) + 1) <= complete_node)
		return (2 * index) + 1;
	return -1;
}

int binarytreearay::GetLeftChild(int index) {
	if (tree[index] != "\0" && (2 * index) <= complete_node)
		return 2 * index;
	return -1;
}

void binarytreearay::PrintLeftChild(int index) {
	if (tree[index] != "\0" && (2 * index) <= complete_node)
		cout << 2 * index << "=" << tree[2 * index];
	return;
}

void binarytreearay::PrintRightChild(int index) {
	if (tree[index] != "\0" && ((2 * index) + 1) <= complete_node)
		cout << (2 * index) + 1 << "=" << tree[2 * index];
	return;
}

void binarytreearay::Preorder(int index) {
	if (index > 0 && tree[index] != "\0") {
		cout << " " << tree[index];
		Preorder(GetLeftChild(index));
		Preorder(GetRightChild(index));
	}
}

void binarytreearay::Postorder(int index) {
	if (index > 0 && tree[index] != "\0") {
		Postorder(GetLeftChild(index));
		Postorder(GetRightChild(index));
		cout << " " << tree[index];
	}
}

void binarytreearay::Inorder(int index) {
	if (index > 0 && tree[index] != "\0") {
		Inorder(GetLeftChild(index));
		cout << " " << tree[index];
		Inorder(GetRightChild(index));
	}
}

void main() {
	binarytreearay test;
	cout << "\nInorder:\n";
	test.Inorder(1);
	test.SetLeftChild("gf", 1);
	cout << "\nInorder:\n";
	test.Inorder(1);
	cout << endl;
	test.PrintLeftChild(1);
}