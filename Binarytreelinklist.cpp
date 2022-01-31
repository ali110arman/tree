#include <iostream>
using namespace std;
class node{
public:
	char data;
	 node* RightChild;
	 node* LeftChild;
};

class BinaryTree{
public:
	node* NewNode(char);
	void Preorder(node*);
	void Postorder(node*);
	void Inorder(node*);
	int IsLeaf(node*);
	int GetHeight(node*);
};

node* BinaryTree::NewNode(char data) {	//ezafe kardan node jadid
	node* p;
	p = (node*)malloc(sizeof(node));
	p->data = data;
	p->LeftChild = NULL;
	p->RightChild = NULL;
	return(p);
}

void BinaryTree::Preorder(node* root){
	if (root != NULL){
		cout<<" "<< root->data;
		Preorder(root->LeftChild);
		Preorder(root->RightChild);
	}
}

void BinaryTree::Postorder(node* root){
	if (root != NULL){
		Postorder(root->LeftChild);
		Postorder(root->RightChild);
		cout<<" "<< root->data;
	}
}

void BinaryTree::Inorder(node* root){
	if (root != NULL) {
		Inorder(root->LeftChild);
		cout<<" "<< root->data;
		Inorder(root->RightChild);
	}
}

int BinaryTree::IsLeaf(node* a){	//tashkis barg boodan
	if (a->RightChild == NULL && a->LeftChild == NULL)
		return 1;
	else
		return 0;
}

int BinaryTree::GetHeight( node* a){	//ertefa
	if (a == NULL || IsLeaf(a)) 
		return 0;
	if (GetHeight(a->LeftChild) > GetHeight(a->RightChild))
		return GetHeight(a->LeftChild) + 1;
	else
		return GetHeight(a->RightChild) + 1;
}

void main(){
	BinaryTree tree;
	node* root;
	root = tree.NewNode('1'); 
	root->LeftChild = tree.NewNode('2'); 
	root->RightChild = tree.NewNode('3');
	root->LeftChild->LeftChild = tree.NewNode('4');
	root->LeftChild->RightChild = tree.NewNode('5');
	tree.Preorder(root);
	cout << endl;
	tree.Postorder(root);
	cout << endl;
	tree.Inorder(root);
	cout << endl;
	cout << tree.GetHeight(root);
}