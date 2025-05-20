import math

def fx(x):
    return 0

x_positive = 0
x_negative = 0

for iteration in range(1,101):
    xnew = (x_negative+x_positive)/2
    xnew_value = fx(xnew)

    print("x_positive_value : %f, x_nagative_value : %f, xnew_value %f" % (fx(x_positive), fx(x_negative), fx(xnew)))
    if xnew_value > 0: x_positive = xnew
    elif xnew_value < 0: x_negative = xnew
    else: break

    if abs(x_positive + x_negative) <= 0.000001:
        break

