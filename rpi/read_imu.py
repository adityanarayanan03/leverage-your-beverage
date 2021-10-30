from mpu_lib import *
import time
import sys

mpu = MPU9250()

while True:
	accel = mpu.readAccel()
	print(accel)
