#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct BinaryTree
{

	int info;
	BinaryTree* Left;
	BinaryTree* Right;
};

void del(BinaryTree *&Node) {
	if (Node != 0) {
		del(Node->Left);
		del(Node->Right);
		delete Node;
		Node = NULL;
	}
}

//Функцiя виводу дерева в прямому порядку
void pre_order(BinaryTree *Node)
{
	if (!Node) return;
	cout << Node->info << " ";
	pre_order(Node->Left);
	pre_order(Node->Right);
}

//Функцiя виводу дерева в зворотньому порядку
void post_order(BinaryTree *Node)
{
	if (Node == NULL) return;
	post_order(Node->Left);
	post_order(Node->Right);
	cout << Node->info << " ";
}

//Функцiя виводу дерева в симетричному порядку
void in_order(BinaryTree *Node)
{
	if (Node == NULL) return;
	in_order(Node->Left);
	cout << Node->info << " ";
	in_order(Node->Right);
}

// Функцiя обходу бiнарного дерева в ширину
void levelOrderTree(BinaryTree *Node)
{
	if (Node == NULL) return;
	queue<BinaryTree *> q;
	q.push(Node);
	while (!q.empty())
	{
		BinaryTree* temp = q.front();
		q.pop();

		cout << temp->info << " ";

		

		if (temp->Left != NULL)
			q.push(temp->Left);
		if (temp->Right != NULL)
			q.push(temp->Right);
	}
}

//функція пошуку в ширину
void levelOrderSearch(BinaryTree *Node)
{
	if (Node == NULL) return;
	queue<BinaryTree *> q;
	q.push(Node);
	while (!q.empty())
	{
		BinaryTree* temp = q.front();
		q.pop();

		//можна ввести будь-яку потрібну умову для пошуку
		if (temp->info > 10 ) {
			cout << temp->info << " ";
			cout << endl;
		}

		if (temp->Left != NULL)
			q.push(temp->Left);
		if (temp->Right != NULL)
			q.push(temp->Right);
	}
}

void add(int info, BinaryTree *&otherNode) {
	if (NULL == otherNode)
	{
		otherNode = new BinaryTree;
		otherNode->info = info;
		otherNode->Left = otherNode->Right = NULL;
	}
	if (info < otherNode->info)
	{
		if (otherNode->Left != NULL) {
			add(info, otherNode->Left);
		}
		else
		{
			otherNode->Left = new BinaryTree;
			otherNode->Left->Left = otherNode->Left->Right = NULL;
			otherNode->Left->info = info;
	
		}
	}
	if (info > otherNode->info)
	{
		if (otherNode->Right != NULL) {
			add(info, otherNode->Right);
		}
		else {
			otherNode->Right = new BinaryTree;
			otherNode->Right->Left = otherNode->Right->Right = NULL;
			otherNode->Right->info = info;
		}
	}
}

////Видалення елемента у бiнарному деревi
//BinaryTree *Delete(BinaryTree *Node, int x)
//{
//	BinaryTree *P, *v;
//	if (!Node) cout << "Element not found!" << endl;
//	else if (x < Node->info) {
//		Node->Left = Delete(Node->Left, x);
//	}
//	else if (x > Node->info) {
//		Node->Right = Delete(Node->Right, x);
//	}
//	else {
//		P = Node;
//
//		if (!Node->Right) {
//			Node = Node->Right;
//		}
//		else if (!Node->Left) {
//			Node = Node->Left;
//		}
//
//		else
//		{
//			//є проблеми
//			v = Node->Left;
//			if (v->Right) {
//				while (v->Right->Right) {
//					v = v->Right;
//				}
//				Node->info = v->Right->info;
//				P = v->Right;
//				v->Right = v->Right->Left;
//			}
//			else {
//				Node->info = v->info;
//				P = v;
//				Node->Left = Node->Left->Left;
//			}
//		}
//	}
//	return Node;
//}



int main() {

	BinaryTree *Node = NULL;
	int amountOfElements;
	cout << "How many elements do you want to input? ";
	cin >> amountOfElements;

	int info;
	for (int i = 0; i < amountOfElements; i++) {

		cout << "Input an element: ";
		cin >> info;
		add(info, Node);
	}

	cout << "\nIDs: \n";
	levelOrderTree(Node);
	cout << endl;
	pre_order(Node);
	cout << endl;
	post_order(Node);
	cout << endl;
	in_order(Node);
	cout << "\nOutput according to search criteria: \n";
	levelOrderSearch(Node);
	/*cout << "How many elements do you want to remove from table: ";
	int numberOfElementsToDelete;
	cin >> numberOfElementsToDelete;
	while (numberOfElementsToDelete<0 || numberOfElementsToDelete>amountOfElements) {
		cout << "Enter the correct number: ";
		cin >> numberOfElementsToDelete;
	}
	for (int i = 0; i < numberOfElementsToDelete; i++) {
		cout << "\nWhich element do you want to delete? ";
		int choice;
		cin >> choice;
		Delete(Node, choice);
		levelOrderTree(Node);
	}

	cout << "\nNew list: \n";
	levelOrderTree(Node);*/
	del(Node);
	system("pause");
	return 0;
}
