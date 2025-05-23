import math
from math import cos,sin
from scipy.optimize import newton, bisect, fsolve, root

# x = 10000
# for iteration in range(1, 101):
#     xnew = x - (2*x**2-5*x+3)/(4*x-5)
#     print("iteration : %d, x = %f, xnew = %f" % (iteration, x, xnew))
#     if abs(xnew - x) <= 0.000001: break
#     x = xnew

def fn(x):
    return (2*x**2 - 5*x + 3)

def fn_derivative(x):
    return 2*(x - cos(x)*sin(x) - 2)

def f2(x):
    return (x**2+cos(x)**2-4*x)

def Newton(x):
    for iteration in range(1,101):
        xnew = x - fn(x)/fn_derivative(x)
        print("iteration : %d, x = %f, xnew = %f" % (iteration, x, xnew))
    if abs(xnew - x) <= 0.000001: return
    x = xnew

def BisectionMethod(x_positive, x_negative):    
    if fn(x_positive) <= 0 or fn(x_negative) >= 0:
        print('wrong input')

    for iteration in range(1,101):
        xnew = (x_negative+x_positive)/2
        xnew_value = fn(xnew)
        print("iteration : %d, x_positive = %f, x_nagative = %f, x_new = %f, x_positive_value : %f, x_nagative_value : %f, xnew_value %f" % (iteration, x_positive, x_negative, xnew, fn(x_positive), fn(x_negative), fn(xnew)))
        if xnew_value > 0: x_positive = xnew
        elif xnew_value < 0: x_negative = xnew
        else: return

        if abs(x_positive - x_negative) <= 0.000001:
            return

def rfalsi(fn,x1,x2,tol=0.001, ilimit=100):
    if x1 > x2:
        x1, x2 = x2, x1
    
    y1 = fn(x1)
    y2 = fn(x2)
    xh = 0
    i = 0

    if y1 == 0: return y1, i
    elif y2 == 0: return y2, i
    elif y1 * y2 > 0:
        print("there's no root within the given range")
    else:
        for i in range(1, ilimit + 1):
            xh = x2-(x2-x1)/(y2-y1)*y2
            yh = fn(xh)
            print("%d iteration: x1 : %f, x2 : %f, xh : %f, y1: %f, y2: %f, yh: %f" % (i,x1,x2,xh,y1,y2,yh))
            if abs(yh) < tol: break
            elif (yh * y1) > 0:
                x2 = xh
                y2 = yh
            else:
                x1 = xh
                y1 = yh
    
    return xh, i

def Secant(fn, x1, x2, tol=0.000001, ilimit = 100):
    for i in range(1, ilimit+1):
        xnew = x2 - (x2-x1)/(fn(x2)-fn(x1)) * fn(x2)
        print("%d iteration: x1 : %f, x2 : %f, xnew : %f, f(x1): %f, f(x2): %f, f(xnew): %f" % (i, x1, x2, xnew, fn(x1), fn(x2), fn(xnew)))
        if abs(xnew-x2) < tol: break
        else:
            x1 = x2
            x2 = xnew
    else:
        print("can't find value from this range")
    return xnew, i

# scipy functions
print("%.6f" % newton(fn, 2))
print(bisect(fn, 1.1, 1.8))
print(fsolve(fn, [1,2,3,4]))
print(root(fn, 1000))
