import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

#Importacion de los datos del ejercicio de ecuaciones diferenciales ordinarias
ODE = np.genfromtxt("datosODE.txt")
x = list()
y = list()
z = list()
t = list()

#Debido a que se encontraron 4 variables con la misma cantidad de datos, se encuentra un n para hacer la asignacion de datos mas facil
l = len(ODE)
n = int(l/4)

#Asignacion de datos
for i in range(1, n):
	t.append(ODE[i])

for i in range(n+1, 2*n):
	x.append(ODE[i])

for i in range(2*n+1, 3*n):
	y.append(ODE[i])

for i in range(3*n+1, 4*n):
	z.append(ODE[i])

#Grafica en 3D del movimiento de la particula con los datos encontrados
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot(x, y, z, linewidth=1)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title("Movimiento de una particula cargada en un campo magnetico uniforme")
plt.savefig("MovPart.png")

#Grafica de x vs y
plt.figure()
plt.plot(y, x)
plt.title("Movimiento en x vs y")
plt.xlabel("Movimiento en y")
plt.ylabel("Movimiento en x")
plt.savefig("MovXY.png")

#Grafica de x vs z
plt.figure()
plt.plot(z, x)
plt.title("Movimiento en x vs z")
plt.xlabel("Movimiento en z")
plt.ylabel("Movimiento en x")
plt.savefig("MovXZ.png")

#Grafica de y vs t
plt.figure()
plt.plot(t, y)
plt.title("y vs. t")
plt.ylabel("Movimiento en y")
plt.xlabel("Tiempo")
plt.savefig("YT.png")

#Importacion de los datos del ejercicio de ecuaciones diferenciales parciales y division en columnas.
PDE = np.genfromtxt("datosPDE.txt", delimiter = " ")
dat1x = PDE[:,0]
dat1y = PDE[:,1]
dat1r = PDE[:,2]

#Asignacion de los datos de la membrana en las condiciones iniciales. Debido a que los datos se dividen en grupos de distinto tamaño, todas las asignaciones deben hacerse a mano
init = np.zeros((100,100))

for i in range(1, 10001):
	x = int(dat1x[i])
	y = int(dat1y[i])
	r = dat1r[i]
	init[x,y] = r
x = np.arange(0, 1, 0.01)
y = np.arange(0, 1, 0.01)
x, y = np.meshgrid(x, y)

#Grafica en 3D de la membrana en t = 0
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(x, y, init)
ax.set_xlabel('L')
ax.set_ylabel('L')
ax.set_zlabel('Amplitud')
ax.set_title("Membrana del tambor inicial")
plt.tight_layout(pad=0.1)
plt.savefig("TambIn.png")

#Asignacion de los datos del corte transversal en el caso de la frontera fija
medio_f = list()
for i in range(10002, 12602):
	medio_f.append(dat1r[i])

#Grafica de las amplitudes de los cortes transversales de la membrana fija en funcion del tiempo
t_f = np.linspace(0, 25000, 2600)
plt.figure(figsize = (8,6))
plt.plot(t_f, medio_f)
plt.xlabel("Tiempo")
plt.ylabel("Amplitud")
plt.title("Corte transversal en la membrana con bordes fijos")
plt.savefig("CortFij.png")

#Asignacion de los valores de la membrana fija en t = 60 ms
fijo = np.zeros((100,100))		
for i in range(12603, 22603):
	x = int(dat1x[i])
	y = int(dat1y[i])
	r = dat1r[i]
	fijo[x,y] = r

#Grafica de la membrana en t = 60 ms con las condiciones de frontera fijas
x = np.arange(0, 1, 0.01)
y = np.arange(0, 1, 0.01)
x, y = np.meshgrid(x, y)
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(x, y, fijo)
ax.set_xlabel('L')
ax.set_ylabel('L')
ax.set_zlabel('Amplitud')
ax.set_title("Membrana del tambor a los 60 ms con extremos fijos")
plt.tight_layout(pad=0.1)
plt.savefig("TambFij.png")

#Asignacion de los datos del corte transversal en el caso de la frontera libre
medio_l = list()
for i in range(22604, 25204):
	medio_l.append(dat1r[i])

#Grafica de las amplitudes de los cortes transversales de la membrana libre en funcion del tiempo
t_l = np.linspace(0, 25000, 2600)
plt.figure(figsize = (8,6))
plt.plot(t_l, medio_l)
plt.xlabel("Tiempo")
plt.ylabel("Amplitud")
plt.title("Corte transversal en la membrana con bordes libres")
plt.savefig("CortLib.png")

#Asignacion de los valores de la membrana libre en t = 60 ms
libre = np.zeros((100,100))		
for i in range(25205, 35205):
	x = int(dat1x[i])
	y = int(dat1y[i])
	r = dat1r[i]
	libre[x,y] = r

#Grafica de la membrana en t = 60 ms con las condiciones de frontera libres
x = np.arange(0, 1, 0.01)
y = np.arange(0, 1, 0.01)
x, y = np.meshgrid(x, y)
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(x, y, libre)
ax.set_xlabel('L')
ax.set_ylabel('L')
ax.set_zlabel('Amplitud')
ax.set_title("Membrana del tambor a los 60 ms con extremos libres")
plt.tight_layout(pad=0.1)
plt.savefig("TambLib.png")


