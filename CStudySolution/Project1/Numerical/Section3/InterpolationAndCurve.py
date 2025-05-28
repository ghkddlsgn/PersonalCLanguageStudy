from math import sin, cos
from typing import List


# def SimpleLineInterpolation(xp: float, x1: float, x2: float, y1: float, y2: float) -> float:

#     return y1 + (y2-y1)/(x2-x1)*(xp-x1)

def SimpleLineInterpolation(xp, x_list, y_list):
    if xp < x_list[0] or xp > x_list[-1]:
        raise ValueError("given x value is out of range")
    
    for i in range(1, len(x_list)):
        if xp < x_list[i]:
            return y_list[i-1] + (y_list[i]-y_list[i-1])/(x_list[i]-x_list[i-1])*(xp-x_list[i-1])

def LagrangeInterpolation(x, x_list, y_list):
    def getL(idx):
        result = 1
        for i in range(len(x_list)):
            if i == idx:
                continue
            denotation = x_list[idx] - x_list[i]
            notation = x - x_list[i]
            result *= notation / denotation
        return result
    
    sum = 0
    for i in range(len(x_list)):
        sum += (y_list[i] * getL(i))
    return sum

def NewtonInterpolation():
    return 0
