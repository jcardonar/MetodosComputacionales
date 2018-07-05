#include <iostream>

using namespace std;

int multiplica(int num1, int num2);
int cuadrado(int num1);

int main()
{
	int a = 17;
	int b = 31;
	int e1; 
	int e2;
	
	e1 = multiplica(a, b);
	e2 = cuadrado(a);

	cout<<"La multiplicacion es "<<e1<<endl;
	cout<<"El numero al cuadrado es "<<e2<<endl;	
	
	return 0;
}

int multiplica(int num1, int num2)
{
	int c;
	c = num1*num2;
	return c;
}

int cuadrado(int num1)
{
	int e;
	e = num1*num1;
	return e;
}
