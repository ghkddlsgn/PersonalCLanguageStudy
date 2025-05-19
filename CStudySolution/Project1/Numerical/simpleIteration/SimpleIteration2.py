x = 0 #initial guess
xnew = 5 #artityary value
iteration = 0
while abs(xnew - x) >= 0.000001:
    xnew = (2*x**2 + 3)/5
    x = xnew
    iteration += 1
    print('iteration : %d, xnew = %f, x = %f' % (iteration, xnew, x))

print('The root : %f' % xnew)