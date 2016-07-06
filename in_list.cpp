#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Node{
	public:
		Node(void);
		~Node(void);
		Node *l, *r, *prev; 
		int key;
};
 
	Node::Node(void){}
	Node::~Node(void){}
 
 

void Add(int x, Node *&MyTree){ 
	if (MyTree == NULL){
		MyTree = new Node; 
		MyTree->key = x; 
		MyTree->l = MyTree->r = MyTree->prev = NULL; 
	}
 
	if (x<MyTree->key){
		if (MyTree->l != NULL) Add(x, MyTree->l);
		else{
			MyTree->l = new Node; 
			MyTree->l->l = MyTree->l->r = NULL; 
			MyTree->l->key = x;
			MyTree->l->prev = MyTree;
		}
	}
 
	if (x>MyTree->key)
	{
		if (MyTree->r != NULL) Add(x, MyTree->r);
		else{ 
			MyTree->r = new Node;  
			MyTree->r->l = MyTree->r->r = NULL; 
			MyTree->r->key = x; 
			MyTree->r->prev = MyTree;
		}
	}
 
}
 
/*ОБХОД В ПРЯМОМ ПОРЯДКЕ*/
void Show(Node *&tree){
	if (NULL == tree){ cout << endl; return; } 
	cout << tree->key << '\t'; 
	Show(tree->l);
	Show(tree->r);    
}
/*СИММЕТРИЧНЫЙ ОБХОД*/
void Show1(Node *&tree){
	if (NULL == tree){ cout << endl; return; } 
	Show1(tree->l); 
	cout << tree->key << '\t'; 
	Show1(tree->r);  
}
/*ОБРАТНЫЙ ОБХОД*/
void Show2(Node *&tree){
	if (NULL == tree){ cout << endl; return; }
	Show2(tree->l);
	Show2(tree->r);  
	cout << tree->key << '\t'; 
}
/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(Node *t, int u) {
	if (t == NULL) {
		cout << endl;
		return;
	} 
	else { 
		print(t->l, ++u);
		for (int i = 0; i<u; ++i)
			cout << "|_";
		cout << t->key << endl; 
		u--;
	}
	print(t->r, ++u); 
}
 
Node * Search1(Node* Pointer, int x) {
		if (Pointer->key == x)
			{return Pointer;
			cout<<"found"<<endl;}
		else if (Pointer->key > x)
			return Search1(Pointer->l, x);
		else if (Pointer->key < x)
			return Search1(Pointer->r, x);
		else return Pointer;
	}
	
Node* Search(Node* MyTree, int x) {
	Node* Pointer=MyTree;
	return Search1(MyTree, x);
 
}

Node* SearchMin(Node* MyTree) {
  Node* Pointer=MyTree;
  for(;Pointer->l;Pointer=Pointer->l);
  	return Pointer;
}
 
Node* SearchMax (Node* MyTree) {
  if (MyTree->r == NULL)
     return MyTree;
  return SearchMax(MyTree->r);
  }
 
Node* SearchNext(Node* MyTree, int x) {
	Node* item = Search(MyTree, x);
	if (item->r)
		return SearchMin(item->r);
	else
		return item;
}
 
void Delete(int x, Node* MyTree) {
	Node* Pointer = MyTree;
	Node* Item = Search(MyTree, x);
	if (Item) {
		if (Item->r == NULL && Item->l == NULL) {
			if (Item == MyTree)
				MyTree = NULL;
			else {
				(Item->prev->l == Item ? Item->prev->l = NULL : Item->prev->r = NULL);
			}
		}
		if (Item->l && !(Item->r)) {
			(Item->prev->l == Item ? Item->prev->l = Item->l : Item->prev->r = Item->l); delete Item;
		}
		if (Item->r && !(Item->l)) {
			(Item->prev->r == Item ? Item->prev->r = Item->r : Item->prev->l = Item->r); delete Item;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
		}
		if (Item->l && Item->r) {
			Pointer = SearchNext(MyTree, Item->key);
			int x1 = Pointer->key;
			if (Pointer->r) {
				Pointer->prev->l = Pointer->r;
			}
			else
				Pointer->prev->l = NULL;
			Item->key = x1;
		}
	}
}
 
int main() {
	Node *Tree = NULL;
	Add(41, Tree);
	Add(71, Tree);
	Add(25, Tree);
	Add(24, Tree);
	Add(60, Tree);
	Add(68, Tree);
	Add(26, Tree);
	Add(4, Tree);
	Add(77, Tree);
	Add(12, Tree);
	Add(52, Tree);
	Add(62, Tree);
	Add(21, Tree);
	Add(31, Tree);
	Add(30, Tree);
	Show(Tree);
	cout<<"----------------------------"<<endl;
	cout<<Search(Tree,68)->key<<endl;
	cout<<Search(Tree,12)->key<<endl;
	cout<<Search(Tree,30)->key<<endl;
	cout<<"----------------------------"<<endl;
	cout << SearchMin(Tree)->key << endl;
	cout<<"----------------------------"<<endl;
	Delete(41, Tree);
	Delete(25, Tree);
	Delete(60, Tree);
	Show(Tree);
 
	return 0;
 
}