#include <iostream>
using namespace std;

int main()
{
	/*Inicializacion de los elementos necesarios para encontrar la solucion*/
	float h = 0.01;
	float tmin = 0.0;
	float tmax = 60.0;
	int n = (float(tmax) - float(tmin))/float(h);
	
	float t[n];
	float y1x[n];
	float y1y[n];
	float y1z[n];
	float y2x[n];
	float y2y[n];
	
	/*Definiendo las constantes*/
	float q = 1.5;
	float m = 2.5;
	float Bz = 3.0;
	float vz = 2.0;
	float cte = (q*Bz)/m;
	
	/*Incializando las condiciones iniciales*/
	t[0] = 0.0;
	y1x[0] = 1.0;
	y1y[0] = 0.0;
	y1z[0] = 0.0;
	y2x[0] = 0.0;
	y2y[0] = 1.0;
	
	/*Primer paso*/
	t[1] = t[0] + h;
	y1x[1] = y1x[0] + 2*h*y2x[0];
	y1y[1] = y1y[0] + 2*h*y2y[0];
	y2x[1] = y2x[0] + 2*h*y2y[0]*cte;
	y2y[1] = y2y[0] - 2*h*y2x[0]*cte;
	
	/*Aplicando el metodo de Leap Frog*/
	for(int i = 2; i<=n; i++)
	{
		float y1xp = y2x[i-1];
		float y1yp = y2y[i-1];
		float y2xp = y2y[i-1]*cte;
		float y2yp = -y2x[i-1]*cte;
	
		t[i] = t[i-1] + h;
		y1x[i] = y1x[i-2]+ 2*h*y1xp;
		y1y[i] = y1y[i-2]+ 2*h*y1yp;

		y2x[i] = y2x[i-2]+ 2*h*y2xp;
		y2y[i] = y2y[i-2]+ 2*h*y2yp;	
	}

	/*Encontrando el movimiento en z con la ecuacion z(t) = vz*t*/
	for(int i = 1; i<=n; i++)
	{
		y1z[i] = vz*t[i];
	}
	
	/*Imprimiendo los valores encontrados*/
	cout<<"t"<<endl;
	for(int i = 0; i<=n; i++)
	{
		cout<<t[i]<<endl;
	}
	cout<<"y1x"<<endl;
	for(int i = 0; i<=n; i++)
	{
		cout<<y1x[i]<<endl;
	}
	cout<<"y1y"<<endl;
	for(int i = 0; i<=n; i++)
	{
		cout<<y1y[i]<<endl;
	}
	cout<<"y1z"<<endl;
	for(int i = 0; i<=n; i++)
	{
		cout<<y1z[i]<<endl;
	}
	return 0;
}

