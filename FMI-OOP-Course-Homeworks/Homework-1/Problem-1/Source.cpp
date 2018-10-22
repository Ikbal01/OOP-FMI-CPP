#include<iostream>
#include"Stack.h"

using namespace std;

int getLength(char * expression);
int pow(int n, int power);
double toNumber(Stack & stack);
bool isNumberOrDecPoint(char s);
bool isMathSym(char sym);
double calculate(char * mathExpression);
double mathOperation(double num1, double num2, char mathSym);
bool isDouble(double num);

int main()
{
	char mathExpressionnn[100];
	cin.get(mathExpressionnn, 100);
	double result = calculate(mathExpressionnn);
	if (result == 404)
	{
		system("pause");
		return 0;
	}
	cout << result << "\n";

	system("pause");
	return 0;
}

double calculate(char * mathExpression)
{
	Stack nums;
	for (int i = 0; i < getLength(mathExpression); i++)
	{
		Stack currNum;
		while (isNumberOrDecPoint(mathExpression[i]))
		{
			currNum.push(mathExpression[i]);
			i++;
		}
		if (!currNum.empty())
		{
			nums.push(toNumber(currNum));
		}
		if (mathExpression[i] != ' ' && !isNumberOrDecPoint(mathExpression[i]) && !isMathSym(mathExpression[i]))//Checks for incorrect data input.
		{
			cout << "Wrong mathematical expression! " << endl;
			return 404;
		}
		if (isMathSym(mathExpression[i]))//If is it math symbol calculates the current expression.
		{
			double helper = nums.pop();
			double newNum = mathOperation(nums.pop(), helper, mathExpression[i]);
			if (newNum == 404)
			{
				return 404;
			}
			nums.push(newNum);
		}
	}

	return nums.pop();
}
double mathOperation(double num1, double num2, char mathSym)// num1 ('+' or '-' or '*' or / or '%') num2 = result ; returns the result.
{
	if (mathSym == '+')
	{
		return num1 + num2;
	}
	else if (mathSym == '-')
	{
		return num1 - num2;
	}
	else if (mathSym == '*')
	{
		return num1 * num2;
	}
	else if (mathSym == '/')
	{
		return num1 / num2;
	}
	else if (mathSym == '%')
	{
		if (isDouble(num1) || isDouble(num2))
		{
			cout << "'%' can't work with real numbers!\n";
			return 404;//error code 404...
		}
		return (int)num1 % (int)num2;
	}
	else
	{
		return -1;
	}
}

int getLength(char * expression)// Gets the length of char array(pointer).
{
	int i = 0;//length of the expression
	while (expression[i] != '\0')
	{
		i++;
	}
	return i;
}

bool isNumberOrDecPoint(char s)// Checks whether the current character is a part of a double number.
{
	if ((s - '0' >= 0 && s - '0' <= 9) || s == '.' || s == ',')
	{
		return true;
	}
	return false;
}

double toNumber(Stack & stack)//Converts the characters from the stack to a number.
{
	double number = 0;
	int i = 0;
	while (!stack.empty())
	{
		if (stack.peek() == '.' || stack.peek() == ',')
		{
			number = number / (pow(10, i));
			stack.pop();
			i = 0;
		}

		number += (stack.pop() - '0') * pow(10, i);
		i++;
	}
	return number;
}

int pow(int n, int power)
{
	double num = 1;
	for (int i = 0; i < power; i++)
	{
		num *= n;
	}
	if (power < 0)
	{
		num = (1 / num);
	}
	return num;
}

bool isMathSym(char sym)//Checks whether the current character is mathematical operator.
{
	if (sym == '*' || sym == '/' || sym == '+' || sym == '-' || sym == '%')
	{
		return true;
	}
	return false;
}

bool isDouble(double num)
{
	if ((num - (int)num) == 0)
	{
		return false;
	}
	return true;
}