import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("CircuitoRC.txt")

t = datos[:,0]
q = datos[:,1]

def lh(dat, teo):
	chi = np.sum((dat - teo)**2)
	chi = (1.0/10000.0)*chi
	return np.exp(-(1.0/2.0)*chi)

def modelo(R, C):
	Qmax = 10*C
	return Qmax*(1-np.exp(-t/(R*C)))

Rw = []
Cw = []
lw = []

Rw.append(10.0)
Cw.append(2.0)
n = 10000

for i in range(0, n):
	R_new = np.random.normal(Rw[i], 0.01)
	C_new = np.random.normal(Cw[i], 0.01)
	y_old = modelo(Rw[i], Cw[i])
	y_new = modelo(R_new, C_new)
	l_old = lh(q, y_old)
	l_new = lh(q, y_new)
	alpha = l_new/l_old
	beta = np.random.random()
	if(alpha >= 1.0):
		Rw.append(R_new)
		Cw.append(C_new)
		lw.append(l_new)
	else:
		if(alpha<=beta):	
			Rw.append(R_new)
			Cw.append(C_new)
			lw.append(l_new)
		else:
			Rw.append(Rw[i])
			Cw.append(Cw[i])
			lw.append(l_old)

def maximizar(arr):
	maxi = 0
	for i in range(0, len(arr) -1):
		if(arr[i] > arr[i+1]):
			maxi = i
	return maxi

lmax = maximizar(lw)
Cmax = Cw[lmax]
Rmax = Rw[lmax]
y = modelo(Rmax, Cmax)

print ("El mejor R es", Rmax, "y el mejor C es", Cmax)

plt.figure()
plt.scatter(t, q, label = "Datos experimentales")
plt.plot(t, y, 'r', label = "Metodo de estimacion bayesiana")
plt.title("Aplicacion del metodo de estimacion bayesiana")
plt.ylabel("Carga")
plt.xlabel("Tiempo")
plt.legend()
plt.savefig("CargaRC.pdf")

lw = np.array(lw)
lw = np.log(lw)

f, axarr = plt.subplots(2,2)
axarr[0,0].scatter(Rw[:-1], -lw)
axarr[0,0].set_title("R en funcion de la verosimilitud")
axarr[1,0].scatter(Cw[:-1], -lw)
axarr[1,0].set_title("C en funcion de la verosimilitud")
axarr[0,1].hist(Rw, 50, normed = True)
axarr[0,1].set_title("Histograma de R")
axarr[1,1].hist(Cw, 50, normed = True)
axarr[1,1].set_title("Histograma de C")
f.subplots_adjust(hspace=0.5)
plt.savefig("Graficas opcionales")
