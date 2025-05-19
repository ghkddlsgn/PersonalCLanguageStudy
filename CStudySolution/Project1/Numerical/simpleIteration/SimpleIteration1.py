from math import sqrt

x = 1.4 #the initial guess
for iteration in range(1,100 + 1):
    xnew = sqrt((5*x-3)/2)
    print(iteration, x)
    if abs(xnew - x) < 0.000001:
        break
    x = xnew

print('the root : %0.5f' % xnew)
print('the number of iteration : %d' % iteration)