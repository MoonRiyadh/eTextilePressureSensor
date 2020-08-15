import serial as sr
import matplotlib.pyplot as plt
import numpy as np
"""
at first run the data_rw_gen.py and then run the live_view.py
it stores sensor reading in CSV file so that it can be used later or farther process for mapping values to GCS
or 
You can only run plot.py to view the output of the sensor
"""
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
    print(data[-1], b)
    # print(b)
    plt.cla()
    plt.ylim(10, 1000)
    plt.plot(data)
    plt.pause(0.01)
    # i = i+1

s.close()
