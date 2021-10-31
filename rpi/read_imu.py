from mpu_lib import *
from math_utils import *
import os, sys, serial, time

mpu = MPU9250()

X_BIAS = 1.0198036 - 1.0
Y_BIAS = 1.0061316 - 1.0
Z_BIAS = 1.0335 - 1.0
accel = {'x': 0.0, 'y': 0.0, 'z': 0.0}

dev = [x[2] for x in os.walk('/dev')]
for file in dev[0]:
	if 'USB' in file:
		port = file
		break;
print(port)
ser = serial.Serial('/dev/' + port, 115200, timeout=1)

while True:
	accel['x'] = mpu.readAccel()['x'] - X_BIAS
	accel['y'] = mpu.readAccel()['y'] - X_BIAS
	accel['z'] = mpu.readAccel()['z'] - X_BIAS
	angles = angles_from_xyz(accel)
	print('{}{}\0\n'.format(str(int(round(angles[0]))).zfill(3), str(int(round(angles[1]))).zfill(3)))
	ser.write('{}{}\0'.format(str(int(round(angles[0]))).zfill(3), str(int(round(angles[1]))).zfill(3)))
	time.sleep(.010)
