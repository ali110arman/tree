#include <iostream>
using namespace std;

class SimpleArrayNode {
public:
	SimpleArrayNode(string, SimpleArrayNode*);
	SimpleArrayNode* Next();
	void SetNextNode(SimpleArrayNode*);
	string Value();
private:
	string NodeValue;
	SimpleArrayNode* NextNode;
};

SimpleArrayNode::SimpleArrayNode(string Value, SimpleArrayNode* nValue)  {
	NodeValue = Value;
	NextNode = nValue;
}

string SimpleArrayNode::Value() {
	return NodeValue;
}

SimpleArrayNode* SimpleArrayNode::Next() {
	return NextNode;
}

void SimpleArrayNode::SetNextNode(SimpleArrayNode* newPtr) {
	NextNode = newPtr;
}


class SimpleTreeLinkList {
public:
	SimpleTreeLinkList(string, SimpleTreeLinkList*);
	SimpleTreeLinkList* Parent();
	int Degree();
	void ShowChild();
	void NewChild(string);
	bool IsRoot();
	bool IsLeaf();
	string Value();
	string DeleteChild(string);
private:
	SimpleTreeLinkList* ParentNode;
	SimpleArrayNode* first;
	SimpleArrayNode* rear;
	string NodeValue;
};

void SimpleTreeLinkList::ShowChild() {	//chap megdar farzand
	for (SimpleArrayNode* ptr = first; ptr != nullptr; ptr = ptr->Next())
		cout << ptr->Next()->Value() << endl;
}

SimpleTreeLinkList::SimpleTreeLinkList(string value, SimpleTreeLinkList* Parent) {	//dorost kardan tree jadad
	ParentNode = Parent;
	NodeValue = value;
}

string SimpleTreeLinkList::Value() {
	return NodeValue;
}

SimpleTreeLinkList* SimpleTreeLinkList::Parent() {	//peida kardan megdar valed
	return ParentNode;
} 

bool SimpleTreeLinkList::IsRoot() {	//aya rishe ast
	if (ParentNode == nullptr)
		return true;
	else
		return false;
}

bool SimpleTreeLinkList::IsLeaf() {	//aya barf ast
	if (Degree() == 0)
		return true;
	else
		return false;
}

void SimpleTreeLinkList::NewChild(string Value) {	//ezafe kardan farzand jadid
	SimpleTreeLinkList* newData = new SimpleTreeLinkList(Value, this);
	if (rear == nullptr) {	//agar derakhat khaly aval bood
		first = new SimpleArrayNode(Value, nullptr);
		rear = first;
	}
	else {
		SimpleArrayNode* tmp = new SimpleArrayNode(Value, nullptr);
		rear->SetNextNode(tmp);
		rear = tmp;
	}
}

string SimpleTreeLinkList::DeleteChild(string Value) {	//hazf kardan farzand
	bool existed = false;
	for (SimpleArrayNode* ptr = first; ptr != nullptr; ptr = ptr->Next()) {
		if (ptr->Next()->Value() == Value) {
			existed = true;
			break;
		}
	}
	if (existed = false)
		return nullptr;
	else {
		for (SimpleArrayNode* ptr = first; ptr != nullptr; ptr = ptr->Next()) {
			if (ptr->Next()->Next()->Value() == Value) {
				ptr->SetNextNode(ptr->Next()->Next());
				break;
			}
		}
		return Value;
	}
}

int SimpleTreeLinkList::Degree() {	//darage node
	int size = 0;
	for (SimpleArrayNode* ptr = first; ptr != nullptr; ptr = ptr->Next())
		size++;
	return size;
}


void main() {

}
