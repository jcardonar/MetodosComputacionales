#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	/*Definiendo las constantes*/
	int L = 1;
	float s = 0.006;
	float c = 300;
	
	/*Inicilizacion de los parametros y elementos necesarios*/
	float dx = 0.01;
	float dy = 0.01;
	float dt = sqrt((dx*dx*dy*dy)/(2*c*c));
	int nx = (int(L)/float(dx));
	int ny = (int(L)/float(dy));
	int nt = (float(s)/float(dt));
	float U_pa[nx][ny];
	float U_pr[nx][ny];
	float U_f[nx][ny];
	float cte = (c*c*dt*dt)/(dx*dx*dy*dy);
	
	/*Abriendo el archivo con las condiciones iniciales*/
	ifstream infile;
	infile.open("init.dat");
	
	/*Asignacion de las condiciones iniciales a la funcion del pasado e igualandola a la funcion del presente ya que la velocidad inicial 		es 0. Imprime la matriz inicial*/
	cout<<"i "<<"j "<<"U_pa"<<endl;
	for(int i = 0; i<nx; i++)
	{
		for(int j = 0; j<ny; j++)
		{	
				infile >> U_pa[i][j];
				cout<<i<<" "<<j<<" "<<U_pa[i][j]<<endl;
				U_pr[i][j] = U_pa[i][j];
		}	
	}
	/*Aplicando el metodo de diferencias finitas para el caso de las fronteras fijas. Se imprimen los valores del corte transversal en L/2 		para cada 1000 pasos de tiempo*/
	cout<<"t_f "<<"j "<<"U_f[50][k]"<<endl;
	for(int j =0; j<nt; j++)
	{
		for(int i = 1; i<nx - 1; i++)
		{
			for(int k = 1; k<ny - 1; k++)
			{
				float a = U_pr[i+1][k] - 2.0*U_pr[i][k] + U_pr[i-1][k];
				float b = U_pr[i][k+1] - 2.0*U_pr[i][k] + U_pr[i][k-1];
				U_f[i][k] = cte*(dy*dy*a + dx*dx*b) + 2.0*U_pr[i][k] - U_pa[i][k];
				
				U_pa[i][k] = U_pr[i][k];				
				U_pr[i][k] = U_f[i][k];
				
			}	
		}
		if(j%1000==0)
		{
			for(int k = 0; k<ny; k++)
			{
				cout<<j<<" "<<k<<" "<<U_f[50][k]<<endl;
			}
			
		}
	}
	/*Impresion de los datos de la membrana fija en t = 60 ms*/
	cout<<"i "<<"j "<<"U_f1"<<endl;
	for(int i = 0; i<nx; i++)
	{
		for(int j = 0; j<ny; j++)
		{	
			cout<<i<<" "<<j<<" "<<U_f[i][j]<<endl;
		}	
	}
	/*Se vuelven a inicializar los datos para aplicar las condiciones de frontera libres*/
	for(int i = 0; i<nx; i++)
	{
		for(int j = 0; j<ny; j++)
		{	
				infile >> U_pa[i][j];
				U_pr[i][j] = U_pa[i][j];
		}	
	}
	infile.close();
	/*Aplicando el metodo de diferencias finitas para el caso de las fronteras libres. Se imprimen los valores del corte transversal en L/2 	para cada 1000 pasos de tiempo*/
	cout<<"t_l "<<"j "<<"U_f[50][k]"<<endl;
	for(int j =0; j<nt; j++)
	{
		for(int i = 0; i<nx; i++)
		{
			for(int k = 0; k<ny; k++)
			{
				float a = U_pr[i+1][k] - 2.0*U_pr[i][k] + U_pr[i-1][k];
				float b = U_pr[i][k+1] - 2.0*U_pr[i][k] + U_pr[i][k-1];
				U_f[i][k] = cte*(dy*dy*a + dx*dx*b) + 2.0*U_pr[i][k] - U_pa[i][k];
				
				U_f[i][0] = U_f[i][1];
				U_f[i][ny -1 ] = U_f[i][ny];
				
				U_pa[i][k] = U_pr[i][k];				
				U_pr[i][k] = U_f[i][k];
			}
		}
		if(j%1000==0)
		{
			for(int k = 0; k<ny; k++)
			{
				cout<<j<<" "<<k<<" "<<U_f[50][k]<<endl;
			}
			
		}
	}
	
	/*Impresion de los datos de la membrana libre en t = 60 ms*/
	cout<<"i "<<"j "<<"U_f2"<<endl;
	for(int i = 0; i<nx; i++)
	{
		for(int j = 0; j<ny; j++)
		{	
			cout<<i<<" "<<j<<" "<<U_f[i][j]<<endl;
		}	
	}		
	return 0;
}
