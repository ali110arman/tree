#include <iostream>
using namespace std;

class TreeNode {
public:
	TreeNode(int, int, int, bool);
	int Value;
	int CerenetDegree();
	int ChildCount;
	bool IsEmpty;
	bool IsLeaf();
};

TreeNode::TreeNode(int Ivalue = int(), int Ichildren = 0, int Iindex = 0, bool Iempty = true) {	//dorost kardan derkhat
	Value = Ivalue;
	ChildCount = Ichildren;
	IsEmpty = Iempty;
}

int TreeNode::CerenetDegree() {//tedad darege felly
	return ChildCount;
}

bool TreeNode::IsLeaf() {	//check kardan barg boodan
	return (ChildCount == 0);
}

class SimpleTreeArray {
private:
	TreeNode* tree;
	int MaxDegree;
	int MaxSize;
	int Height;
public:
	SimpleTreeArray(int, int);
	~SimpleTreeArray();
	int TreeSize(int);
	int TreeHeight(int);
	int Value(int);
	int ParentValue(int);
	int Level(int);
	bool IsEmpty();
	bool IsFull();
	bool IsLeaf(int);
	void NewRoot(int);
	void AddNew(int, int);
	void Child(int);
	void Delete(int);
	void Show();
};

SimpleTreeArray::SimpleTreeArray(int IMAXDEG, int IHEIGHT) {	//dorost kardan array jadid
	MaxDegree = IMAXDEG;
	Height = IHEIGHT;
	MaxSize = ((IMAXDEG * (1 - pow(IMAXDEG, IHEIGHT))) / (1 - IMAXDEG)) + 1; //peida kardan maxsize
	tree = new TreeNode[MaxSize];  //dorost kardan array ba siza maxsize
}

SimpleTreeArray::~SimpleTreeArray() {	//mokhareb
	delete[] tree;
}

bool SimpleTreeArray::IsEmpty() {	//aya araryr khaly ast
	return tree[0].IsEmpty;	//agar khane aval khaly bood
}

bool SimpleTreeArray::IsFull() {	//aya araryr por ast
	return TreeSize(0) == MaxSize ; //agar akharin khane ba max size yeki bod
}

int SimpleTreeArray::TreeSize(int ParentIndex = 0) {	//size derakhat ba shomaresh node ha
	int s = 0;
	if (!IsEmpty() || ParentIndex <= MaxSize)
		for (int i = 0; i < MaxSize; i++)
			if (tree[i].IsEmpty == false)
				s += 1;
	return s;
}

int SimpleTreeArray::Level(int ParentIndex = 0) { // this will return the TreeHeight of a subtree if Index specifies else the TreeHeight of tree
	int max = 0;
	if (ParentIndex >= MaxSize || tree[ParentIndex].IsEmpty)
		return 0;
	else {
		for (int i = 1; i <= tree[ParentIndex].ChildCount; i++) {
			int cheight = Level(ParentIndex * MaxDegree + i);
			max = cheight > max ? cheight : max;
		}
		return 1 + max;
	}
}

int SimpleTreeArray::TreeHeight(int parent_node = 0) { //ertefa derakht
	return Level(parent_node) - 1;
}

bool SimpleTreeArray::IsLeaf(int node_index) {
	if (!tree[node_index].IsEmpty)
		return tree[node_index].IsLeaf();
}

void SimpleTreeArray::NewRoot(int Value) {//ezafe kardan node jadid	be enteha
	if (tree[0].IsEmpty) {
		tree[0].Value = Value;
		tree[0].IsEmpty = false;
	}
}

void SimpleTreeArray::AddNew(int Value, int ParentIndex) {//ezafe kardan node jadid dar makan delkhah
	if (!tree[ParentIndex].IsEmpty && tree[ParentIndex].ChildCount != MaxDegree) {
		int Index = ParentIndex * MaxDegree + tree[ParentIndex].ChildCount + 1;
		tree[Index] = Value;
		tree[Index].IsEmpty = false;
		tree[ParentIndex].ChildCount += 1;
	}
}

int SimpleTreeArray::Value(int node_index) {//megdar yek node dar index
	if (!tree[node_index].IsEmpty)
		return tree[node_index].Value;
}

int SimpleTreeArray::ParentValue(int node_index) {//megdar valed yek node
	if (!tree[node_index].IsEmpty)
		return tree[(node_index - 1) / MaxDegree].Value;
}

void SimpleTreeArray::Child(int node_index) { //chap farzandan node
	if (!tree[node_index].IsEmpty)
		if (tree[node_index].CerenetDegree() != 0)
			for (int i = 1; i <= tree[node_index].CerenetDegree(); i++)
				cout << tree[node_index * MaxDegree + i].Value << ", ";
			cout << endl;
}

void SimpleTreeArray::Delete(int node_index) {	//hazf az array tree
	if (node_index > 0 || node_index < MaxSize)
		for (int i = 1; i <= tree[node_index].ChildCount; i++) {
			int Index = MaxDegree * node_index + i;
			Delete(Index);
		}
		tree[node_index].IsEmpty = true;

}

void SimpleTreeArray::Show() {//chap magadir
	if (!IsEmpty()) 
		for (int i = 0; i < MaxSize; i++)
			if (tree[i].IsEmpty) 
				cout << "-";
			else
				cout << tree[i].Value << " ";
		cout << endl;
}

void main() {

	SimpleTreeArray tree(4, 2);
	tree.NewRoot(8);
	tree.AddNew(12, 0);
	tree.AddNew(11, 0);
	tree.AddNew(24, 2);
	tree.AddNew(18, 2);
	tree.Show();
	cout <<"size: "<< tree.TreeSize() <<endl;
	cout <<"ertefa: "<< tree.TreeHeight() << endl;
	tree.Delete(2);
	cout << "size: " << tree.TreeSize() << endl;
	cout << "ertefa: " << tree.TreeHeight() << endl;
	tree.Show();
	cout << tree.IsFull();
}