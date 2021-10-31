from mpu_lib import *
import time
import sys

mpu = MPU9250()

X_BIAS = 1.0198036 - 1.0
Y_BIAS = 1.0061316 - 1.0
Z_BIAS = 1.0335 - 1.0
accel = {'x': 0.0, 'y': 0.0, 'z': 0.0}
rotation = {'theta':90, 'psi':90}

while True:
	accel['x'] = mpu.readAccel()['x'] - X_BIAS
	accel['y'] = mpu.readAccel()['y'] - X_BIAS
	accel['z'] = mpu.readAccel()['z'] - X_BIAS
