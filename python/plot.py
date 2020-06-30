import serial as sr
import matplotlib.pyplot as plt
import numpy as np

s = sr.Serial("COM6", 9600)
plt.close("all")
plt.figure()
plt.ion()
plt.show()

data = np.array([])

i = 0
while True:
    a = s.readline().decode()
    b = float(a)
    data = np.append(data, b)
    print(b)
    plt.cla()
    plt.plot(data)
    plt.pause(0.01)
    i = i+1

s.close()
