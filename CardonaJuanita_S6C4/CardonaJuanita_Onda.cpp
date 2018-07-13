#include <iostream>
#include <stdio.h>     
#include <math.h>     
using namespace std;

int main()
{
	int nx = 1;
	int ny = 1;
	int nt = 30;
	float c = 300.0;
	
	float dx = 0.01
	float dy = 0.01
	
	float dt = sqrt(dx*dx*c)/(2.0);
	
	float x[nx];
	float y[nx];
	float t[nt];
	float U_pr[nx][ny];
	float U_pa[nx][ny]
	float U_f[nx][ny];
	U_f[0] = 1;
	float cte = dt*dt/c;
	
	for(int i = 0; i<nx; i++)
	{
		x[i] = i*dx;
	}
	
	for(int i = 0; i<ny; i++)
	{
		y[i] = i*dy;
	}	
	
	for(int i = 0; i<nt; i++)
	{
		t[i] = i*dt;
	}	
	for(int i = 0; i < nx; i++)
	{
		for(int k = 0, k<ny, k++)
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
	}
	for(int j=0; j<nt; j++)
	{	
		for(int i =2; i<nx; i++)	
		{
		for(int k = 2; k<ny; k++)
			{
				float a = U_pr[i+1][k] - U_pr[i-1][k] - 2*U_pr[i][k];
				float b = U_pr[i][k+1] - U_pr[i][k-1] - 2*U_pr[i][k]
				U_f[i] = 2*U_pr[i][k] - U_pa[i][k] + cte*(a/dt + b/dy);
			}
		}
		
	}
	return 0;
}

