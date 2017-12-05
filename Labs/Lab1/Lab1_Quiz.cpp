#include <iostream>
using namespace std;

int sum(int a, int b);
void sum_third(int a, int b, int &c);
void output(int *nums);
void copy(const int *in_array, int *out_array);

int main()
{
	int a, b, c;
	const int in_array[] = {1, 23, 5, 7, 9, 10, -3, 5};
	int *out_array = NULL;
	a = 12;
	b = 15;
	c = 0;

	c = sum (a,b);
	cout << "The value in c is: " << c << endl;

	a = 5;
	b = 10;
	c = 0;
	sum_third(a, b, c);
	cout << "The new value in c is: " << c << endl;

	copy(in_array, out_array);
	/*
	while (*out_array)
	{
		cout << *out_array;
		out_array++;
	}
*/
	
}

int sum(int a, int b)
{
	return (a+b);
}

void sum_third (int a, int b, int &c)
{
	c = a+b;
}

void copy(const int *in_array, int *out_array)
{

	if(!in_array)
		return;
	while(*in_array > 0)
	{
		*out_array = *in_array;
		out_array++;
		in_array++;
	}
}
