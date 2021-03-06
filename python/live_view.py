from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

"""
at first run the data_rw_gen.py and then run the live_view.py
it stores sensor reading in CSV file so that it can be used later or farther process for mapping values to GCS
or 
You can only run plot.py to view the output of the sensor
"""

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()

"""
Take data from the csv file and plot them
"""


def animate(i):
    data = pd.read_csv('data.csv')
    x = data['x_value']
    y1 = data['total_1']
    y2 = data['total_2']

    plt.cla()
    plt.ylim(0, 1000)
    plt.plot(x, y1, label='Ch1')
    plt.pause(0.01)
    # plt.plot(x, y2, label='Ch2')

    plt.legend(loc='upper left')
    plt.tight_layout()


ani = FuncAnimation(plt.gcf(), animate, interval=1000)

plt.tight_layout()
plt.show()
