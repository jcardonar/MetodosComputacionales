#include <iostream>
using namespace std;

int main()
{
	int nx = 80;
	int nt = 30;
	float c = 1.0;
	
	float dx = 2.0/nx;
	float dt = dx/(2.0*c);
	
	float x[nx];
	float t[nt];
	float U_p[nx];
	float U_f[nx];
	U_f[0] = 1;
	float cte = dt/dx;
	
	for(int i = 0; i<nx; i++)
	{
		x[i] = i*dx;
	}
	
	for(int i = 0; i<nt; i++)
	{
		t[i] = i*dt;
	}	
	for(int i = 0; i < nx; i++)
	{
		if(x[i] <= 0.75 || x[i] >= 1.25)
		{
			U_p[i] = 1.0;
		}
		else
		{
			U_p[i] = 2.0;
		}
	}
	for(int j=0; j<nt; j++)
	{	
		for(int i =1; i<nx; i++)
		{
			float a = U_p[i] - U_p[i-1];
			U_f[j+1] = U_p[i] + cte*a;
		
		}
		cout<<U_f[j]<<endl;
	}
	return 0;
}

