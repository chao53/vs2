#pragma once
#include <iostream>
#include "StackList.h"
#include <map>

using namespace std;

class Calculator {
private:
	StackList<char> stack1 = StackList<char>(50);
	StackList<double> stack2 = StackList<double>(50);
	map<char, int> isp;
	map<char, int> icp;
	map<char, int> numap;

	bool isNunmber(char c);
public:
	Calculator();
	~Calculator();
	string translate(string s);
	double calculate(string s);
	double run(string s);
};

bool Calculator::isNunmber(char c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
		return true;
	}
	else
	{
		return false;
	}
}

Calculator::Calculator() {

	isp['a'] = 1;
	isp['('] = 1;
	isp['^'] = 7;
	isp['*'] = 5;
	isp['/'] = 5;
	isp['%'] = 5;
	isp['+'] = 3;
	isp['-'] = 3;
	isp[')'] = 8;

	icp['a'] = 8;
	icp['('] = 8;
	icp['^'] = 6;
	icp['*'] = 4;
	icp['/'] = 4;
	icp['%'] = 4;
	icp['+'] = 2;
	icp['-'] = 2;
	icp[')'] = 1;

	numap['1'] = 1;
	numap['2'] = 2;
	numap['3'] = 3;
	numap['4'] = 4;
	numap['5'] = 5;
	numap['6'] = 6;
	numap['7'] = 7;
	numap['8'] = 8;
	numap['9'] = 9;
	numap['0'] = 0;
}

Calculator::~Calculator() {
	stack1.clear();
	stack2.clear();
}

string Calculator::translate(string middle) {
	middle += "#";
	if (middle[0] == '-') {
		int j = 1;
		middle.insert(0, "(0");
		for (j = 3;middle[j] != '#';j++) {
			if (icp[middle[j]] != 0) {
				break;
			}
		}
		middle.insert(j, ")");
	} 
	for (int j = 1;middle[j] != '#';j++) {
		if (middle[j] == '-' && icp[middle[j-1]] > 1) {
			middle.insert(j, "(0");
			for (j = j+3;;j++) {
				if (icp[middle[j]] != 0) {
					middle.insert(j, ")");
					break;
				}
				if (middle[j] == '#') {
					middle.insert(j, ")");
					break;
				}
			}
		}
	}
	int i = 0;
	string back = "";
	while (middle[i] != '#') {
		if (icp[middle[i]] == 0) {
			back += middle[i];
		}
		else {
			back += ' ';
			if(middle[i] == 'a')
			{
				stack1.push(middle[i]);
				i += 3;
			}
			else if (stack1.show() == '#')
			{
				stack1.push(middle[i]);
			}
			else if (middle[i] == ')') {
				while (true)
				{
					if (stack1.show() != '(' && stack1.show() != 'a') {
						char x = NULL;
						stack1.pop(x);
						back += x;
					}
					else if(stack1.show() == '(')
					{
						char x = NULL;
						stack1.pop(x);
						break;
					}
					else if(stack1.show() == 'a')
					{
						char x = NULL;
						stack1.pop(x);
						back += x;
						break;
					}
				}
			}
			else if (icp[middle[i]] >= isp[stack1.show()])
			{
				stack1.push(middle[i]);
			}
			else if (icp[middle[i]] < isp[stack1.show()]) {
				while (icp[middle[i]] < isp[stack1.show()])
				{
					char x = NULL;
					stack1.pop(x);
					back += x;
				}
				stack1.push(middle[i]);
			}
		}
		i++;
	}
	while (stack1.show() != '#') {
		char x = NULL;
		stack1.pop(x);
		if (x != '(' && x != ')') {
			back += x;
		}
	}
	return back;
}

double Calculator::calculate(string back) {

	double left;
	double right;

	int i = 0;

	back += '#';
	while (back[i] != '#')
	{
		if (isNunmber(back[i])) {
			int point = -1;
			double x = 0;
			while (isNunmber(back[i]) || back[i] == '.')
			{
				if (point >= 0) {
					point++;
				}
				if (back[i] == '.') {
					point = 0;
				}
				else {
					x = x * 10 + numap[back[i]];
				}
				i++;
			}
			for (int j = 0;j < point;j++) {
				x /= 10;
			}
			stack2.push(x);
		}
		else if (back[i] == ' ') {
			i++;
			//do nothing
		}
		else if (back[i] == '+') {
			stack2.pop(right);
			stack2.pop(left);
			left += right;
			stack2.push(left);
			i++;
		}
		else if (back[i] == '-') {
			stack2.pop(right);
			stack2.pop(left);
			left -= right;
			stack2.push(left);
			i++;
		}
		else if (back[i] == '*') {
			stack2.pop(right);
			stack2.pop(left);
			left *= right;
			stack2.push(left);
			i++;
		}
		else if (back[i] == '/') {
			stack2.pop(right);
			stack2.pop(left);
			left /= right;
			stack2.push(left);
			i++;
		}
		else if (back[i] == '%') {
			stack2.pop(right);
			stack2.pop(left);
			left = (int)left % (int)right;
			stack2.push(left);
			i++;
		}
		else if (back[i] == '^') {
			stack2.pop(right);
			stack2.pop(left);
			double keep = left;
			for (int j = 1;j < right;j++) {
				left *= keep;
			}
			stack2.push(left);
			i++;
		}
		else if(back[i] == 'a')
		{
			stack2.pop(left);
			if (left < 0) {
				left *= -1;
			}
			stack2.push(left);
			i++;
		}
	}
	double anser;
	stack2.pop(anser);
	return anser;
}

double Calculator::run(string s) {
	return calculate(translate(s));
}