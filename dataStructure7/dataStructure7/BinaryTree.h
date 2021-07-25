//作者：陈炜潮
#pragma once
#include<iostream>
#include<queue>
#include <string.h>

using namespace std;

struct BNode
{
	string body = "";
	struct BNode* root = NULL;
	struct BNode* leftChild = NULL;
	struct BNode* rightChild = NULL;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	BNode* headRoot;
	void creat();
	int grow(string input, BNode* currentRoot);
	string firstRootOrder(BNode* currentRoot);
	string middleRootOrder(BNode* currentRoot);
	string levelRootOrder(BNode* currentRoot);
	int countLevel(BNode* currentRoot);
	string countEachLevel(BNode* currentRoot);
};

BinaryTree::BinaryTree() {

}
BinaryTree::~BinaryTree() {

}

void BinaryTree::creat() {
	BNode *headRoot = new BNode;
	this->headRoot = headRoot;
}

int BinaryTree::grow(string input, BNode* currentRoot = NULL) {//缺省参数
	BNode* current;
	if (currentRoot == NULL) {
		current = this->headRoot;
	}
	else
	{
		current = currentRoot;
	}
	int step = 1;

	BNode *newLeft = new BNode;
	newLeft->root = current;
	current->leftChild = newLeft;
	current = newLeft;
	int i = 1;
	for (;i < input.size();i++) {//从下标为1开始
		if (input[i] == '}') {
			break;
		}
		else if(input[i] == '{')
		{
			if (input[i + 1] == '}') {
				i += 1;
			}
			else
			{
				i += grow(input.substr(i), current);
			}
		}
		else if(input[i] == ',')
		{
			if (step == 1) {
				current = current->root;
			}
			else if(step == 2)
			{
				BNode *newRight = new BNode;
				newRight->root = current;
				current->rightChild = newRight;
				current = newRight;
			}
			step++;
		}
		else
		{
			current->body += input[i];
		}
	}
	return i;
}

string BinaryTree::firstRootOrder(BNode* currentRoot = NULL) {//缺省参数
	string output = "";
	BNode* current;
	if (currentRoot == NULL) {
		current = this->headRoot;
	}
	else
	{
		current = currentRoot;
	}
	
	if (current->body.empty() == false) {
		output += current->body;
		if (current->leftChild != NULL && current->leftChild->body.empty() == false) {//从左到右判断
			output += ',';
			output += firstRootOrder(current->leftChild);
		}
		if (current->rightChild != NULL && current->rightChild->body.empty() == false) {
			output += ',';
			output += firstRootOrder(current->rightChild);
		}
	}
	return output;
}

string BinaryTree::middleRootOrder(BNode* currentRoot = NULL) {//缺省参数
	string output = "{";
	BNode* current;
	if (currentRoot == NULL) {
		current = this->headRoot;
	}
	else
	{
		current = currentRoot;
	}

	if (current->leftChild != NULL && current->leftChild->body.empty() == false) {
		output += middleRootOrder(current->leftChild);
	}
	else
	{
		output += "{}";
	}
	output += ',';
	output += current->body;
	output += ',';
	if (current->rightChild != NULL && current->rightChild->body.empty() == false) {
		output += middleRootOrder(current->rightChild);
	}
	else
	{
		output += "{}";
	}
	output += '}';

	return output;
}

string BinaryTree::levelRootOrder(BNode* currentRoot = NULL) {//缺省参数
	string output = "";
	queue<BNode*> q;

	if (currentRoot == NULL) {
		q.push(this->headRoot);
	}
	else
	{
		q.push(currentRoot);
	}

	while (!q.empty()) {
		output += q.front()->body;
		if (q.front()->leftChild != NULL && q.front()->leftChild->body.empty() == false) {
			q.push(q.front()->leftChild);
		}
		if (q.front()->rightChild != NULL && q.front()->rightChild->body.empty() == false) {
			q.push(q.front()->rightChild);
		}
		q.pop();
		if (!q.empty()) {
			output += ',';
		}
	}
	return output;
}

int BinaryTree::countLevel(BNode* currentRoot = NULL) {//缺省参数
	int leftLevel = -1;
	int rightLevel = -1;
	BNode* current;
	if (currentRoot == NULL) {
		current = this->headRoot;
	}
	else
	{
		current = currentRoot;
	}

	if (current->leftChild != NULL && current->leftChild->body.empty() == false) {
		leftLevel = countLevel(current->leftChild);
	}
	if (current->rightChild != NULL && current->rightChild->body.empty() == false) {
		rightLevel = countLevel(current->rightChild);
	}
	return leftLevel > rightLevel ? leftLevel + 1 : rightLevel + 1;
}

string BinaryTree::countEachLevel(BNode* currentRoot = NULL) {//缺省参数
	string output = "";
	queue<BNode*> q;
	BNode mark;

	if (currentRoot == NULL) {
		q.push(this->headRoot);
	}
	else
	{
		q.push(currentRoot);
	} 
	q.push(&mark);
	int level = 48; //int加上48转化为字符
	output += level;
	output += ":";

	int count = 48;
	while (!q.empty()) {
		if (q.front() == &mark) {
			output += count;
			count = 48;
			q.pop();
			if (!q.empty()) {
				output += ',';
				level++;
				output += level;
				output += ":";
				q.push(&mark);
			}
		}
		else {
			count++;
			if (q.front()->leftChild != NULL && q.front()->leftChild->body.empty() == false) {
				q.push(q.front()->leftChild);
			}
			if (q.front()->rightChild != NULL && q.front()->rightChild->body.empty() == false) {
				q.push(q.front()->rightChild);
			}
			q.pop();
		}
	}
	return output;
}