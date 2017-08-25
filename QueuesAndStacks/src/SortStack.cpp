/*
 * SortStack.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: chivora
 */

#include<iostream>
#include<stdlib.h>
#include <stack>
#include <vector>

using namespace std;

class MyStack{
private:
	stack<int> stack1,stack2;

public:
	void push(int element)
	{
		// check if current top is greater or less than element

		/*
		 * If current top is greater than given element, then just push it
		 */
		if(stack1.empty()){
			stack1.push(element);
			return;
		}
		if(stack1.top() >= element)
		{
			stack1.push(element);
		}
		/*
		 * If current top is less than given element, then pop it and
		 * start pushing it in stack2, till the point this condition exist.
		 * Then push the element in stack1, start popping elements out of stack2
		 * and push into stack1
		 */
		else{
			while(!stack1.empty() && stack1.top() < element)
			{
				int value = stack1.top();
				stack1.pop();
				stack2.push(value);
			}
			stack1.push(element);
			while(!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
	}

	int pop()
	{
		int value = stack1.top();
		stack1.pop();
		return value;
	}

};

int main(){

	MyStack myStack;
	myStack.push(6);
	myStack.push(8);
	myStack.push(4);
	myStack.push(9);
	cout<<myStack.pop()<<endl;
	myStack.push(5);
	myStack.push(3);
	myStack.push(10);
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	return 0;

}


