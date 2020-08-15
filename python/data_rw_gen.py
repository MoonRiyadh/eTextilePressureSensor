import csv
import time
import serial as sr
"""
at first run the data_rw_gen.py and then run the live_view.py
it stores sensor reading in CSV file so that it can be used later or farther process for mapping values to GCS
or 
You can only run plot.py to view the output of the sensor
"""

s = sr.Serial("COM6", 9600)

x_value = 0
total_1 = 0
total_2 = 0

fieldnames = ["x_value", "total_1", "total_2"]

with open('data.csv', 'w') as csv_file:
    csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
    csv_writer.writeheader()
"""
Data read from the Sensor via Arduino and write them into the csv file
"""
while True:
    a = s.readline().decode()
    b_map = float(a)
    with open('data.csv', 'a') as csv_file:
        csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

        info = {
            "x_value": x_value,
            "total_1": total_1,
            "total_2": total_2
        }

        csv_writer.writerow(info)
        print(x_value, total_1, total_2)

        x_value += 1
        total_1 = b_map

    time.sleep(.001)
