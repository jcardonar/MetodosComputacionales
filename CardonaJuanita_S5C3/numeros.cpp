#include <iostream>
#include <cstdlib>
using namespace std;

int pares(int num1);

int main()
{
	int res;
	int i, numeroal;
	for(i=0;i<1000;i++)
	{
		numeroal = rand() % 100 + 1; 	 	 	
		res = pares(numeroal);
		cout<<res<<endl;
	}	
	return 0;
}

int pares(int num1)
{
	int contador = 0;
	for(int num1; num1<89; num1++)
	{
		if(num1%2 == 0 && contador < 25 && num1<89)
		{
		contador += 1;
		return num1;
		}
		else if(contador == 25)
		{
			break;
		}
		
	}
}
