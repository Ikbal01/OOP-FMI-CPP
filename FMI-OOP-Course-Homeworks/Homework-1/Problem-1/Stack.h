#ifndef STACK_H
#define STACK_H

int const initialSize = 50;

class Stack
{
private:
	int size;
	double * members;
	int top;

	void grow();
public:
	Stack();
	~Stack();
	void push(double num);
	double pop();
	double peek() const;
	bool empty() const;

};
#endif // !STACK_H
