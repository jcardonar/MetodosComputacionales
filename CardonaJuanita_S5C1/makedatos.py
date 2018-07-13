import numpy as np
import matplotlib.pylab as plt

t = np.linspace( 0, 10, 1000)
y = np.cos(2 * np.pi * t)

for i in range(1000):
	print t[i],y[i]
