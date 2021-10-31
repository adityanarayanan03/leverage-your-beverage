import math

def angles_from_xyz(accel_dict):
    x = accel_dict['x']
    y = accel_dict['y']
    z = accel_dict['z']
    norm = math.sqrt(x**2 + y**2 + z**2)
    x = x/norm
    y = y/norm
    z = z/norm

    if y>=0 and x>=0: #Q1
        theta = 90 + math.degrees(math.acos(z/math.sqrt(x**2 + z**2)))
        psi = 90 + math.degrees(math.acos(math.sqrt(x**2 + z**2)))
    elif y>=0 and x<=0: #Q2
        theta = 90 - math.degrees(math.acos(z/math.sqrt(x**2 + z**2)))
        psi = 90 + math.degrees(math.acos(math.sqrt(x**2 + z**2)))
    elif y<=0 and x<= 0: #Q3
        theta = 90 - math.degrees(math.acos(z/math.sqrt(x**2 + z**2)))
        psi = 90 - math.degrees(math.acos(math.sqrt(x**2 + z**2)))
    else:
        theta = 90 + math.degrees(math.acos(z/math.sqrt(x**2 + z**2)))
        psi = 90 - math.degrees(math.acos(math.sqrt(x**2 + z**2)))
    
    return theta, psi

if __name__ == '__main__':
    #print(angles_from_xyz({'x':0,'y':1,'z':1}))
    pass