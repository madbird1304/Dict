#ifndef TERNARY_H
#define TERNARY_H
#include <string>
#include <iostream>
#include <algorithm>
//#include <s
#include <vector>
#include <utility>
//#include <cstdlib>
//class Dict;

//class Node;
//Node* nullptr = NULL;

struct Node{
	char c;
	Node *left, *middle, *right;
	int eos;

	Node(char _c) : c(_c), left(nullptr), right(nullptr), middle(nullptr), eos(0) {}

	virtual ~Node() { delete left; delete right; delete middle;  }
};

class Tree{
	Node *root_;	
	void insert_(Node**,const char*);
	int count_(Node*,const char*);
public:
	friend std::ostream &operator<< (std::ostream &out ,Tree t);

	Tree(Node *root = nullptr) : root_(root) {}

	int count(const char *str) { return count_(root_,str); }

	void insert(const char *str) { insert_(&root_,str); }	

	std::vector<std::pair<std::string,int>>  freqs();

	virtual ~Tree() { delete root_; }
};

#include "ternary.cpp"
#endif
