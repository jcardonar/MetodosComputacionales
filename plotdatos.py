import numpy as np
import matplotlib.pylab as plt

#Grafica de datos.dat

datos=np.genfromtxt("datos.dat")

plt.figure()
plt.plot(datos[:,0],datos[:,1])
plt.savefig("plot.pdf")
