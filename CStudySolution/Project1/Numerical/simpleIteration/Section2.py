import math
from math import cos,sin

# x = 10000
# for iteration in range(1, 101):
#     xnew = x - (2*x**2-5*x+3)/(4*x-5)
#     print("iteration : %d, x = %f, xnew = %f" % (iteration, x, xnew))
#     if abs(xnew - x) <= 0.000001: break
#     x = xnew

def fx(x):
    return (2*x**2 - 5*x + 3)

def fx_derivative(x):
    return 2*(x - cos(x)*sin(x) - 2)

def Newton(x):
    for iteration in range(1,101):
        xnew = x - fx(x)/fx_derivative(x)
        print("iteration : %d, x = %f, xnew = %f" % (iteration, x, xnew))
    if abs(xnew - x) <= 0.000001: return
    x = xnew

def BisectionMethod(x_positive, x_negative):    
    if fx(x_positive) <= 0 or fx(x_negative) >= 0:
        print('wrong input')

    for iteration in range(1,101):
        xnew = (x_negative+x_positive)/2
        xnew_value = fx(xnew)
        print("iteration : %d, x_positive = %f, x_nagative = %f, x_new = %f, x_positive_value : %f, x_nagative_value : %f, xnew_value %f" % (iteration, x_positive, x_negative, xnew, fx(x_positive), fx(x_negative), fx(xnew)))
        if xnew_value > 0: x_positive = xnew
        elif xnew_value < 0: x_negative = xnew
        else: return

        if abs(x_positive - x_negative) <= 0.000001:
            return

BisectionMethod(0,1.3)