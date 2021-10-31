from mpu_lib import *
import time
import sys

mpu = MPU9250()

average = 0
print("waiting. starting in 1")
time.sleep(1)
for _ in range(5000):
	average += (mpu.readAccel()['z'])/5000.0

print(average)
