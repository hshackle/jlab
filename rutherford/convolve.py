import scipy.integrate as integrate
import math
from sympy.functions.special.delta_functions import Heaviside
import numpy
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.odr import ODR, Model, Data, RealData


def convolve_func(theta,phi):
    return 1/numpy.power(numpy.sin(theta/2), 4)*(1-numpy.absolute(theta-phi)/.13) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + .13) + 1)
#* Heaviside(-numpy.absolute(theta-phi) + .122)

def convolve(phi):
    sol = []
    for i in phi:
        sol.append(integrate.quad(lambda x: convolve_func(x, i), 0.01, 3.14159)[0])
    #result = integrate.quad(lambda x: convolve_func(x, phi), 0.01, 3.14159)
    return numpy.array(sol)

def fitFunc(A, x):
    return A[0]*convolve(x)


"""xdata = numpy.array([.174, .2618, .3491, .5236, .6981, .8727, 1.047])
ydata = numpy.array([9.64, 0.66, 0.12, 0.02, 0.005, 0.002156, 0.0009])
x_err = numpy.array([0.0087, 0.0087, 0.0087, 0.0087, 0.0087, 0.0087, 0.0087])
y_err = numpy.array([1.79, 0.3, 0.005, 0.00049, 0.000253, 0.00009, 0.00004])"""
xdata = numpy.array([.3491, .5236, .6981, .8727, 1.047])
ydata = numpy.array([ 0.12, 0.02, 0.005, 0.002156, 0.0009])
x_err = numpy.array([ 0.0087, 0.0087, 0.0087, 0.0087, 0.0087])
x_err = x_err*2
y_err = numpy.array([0.005, 0.00049, 0.000253, 0.00009, 0.00004])
conv_model = Model(fitFunc)
data = RealData(xdata,ydata, sx=x_err, sy=y_err)
odr = ODR(data, conv_model, beta0=[0.005])

out = odr.run()
out.pprint()

x_fit = numpy.linspace(xdata[0] - 0.05, xdata[-1]+ .05, 1000)
y_fit = fitFunc(out.beta, x_fit)

plt.errorbar(xdata*57.296, ydata, xerr=x_err*57.296, yerr=y_err, linestyle='None',ecolor='b', marker='None')
plt.semilogy(x_fit*57.296, y_fit)

plt.show()

"""plt.plot(xdata, ydata, 'b-', label='data')

popt, pcov = curve_fit(fitFunc, xdata, ydata)
plt.plot(xdata, fitFunc(xdata, *popt), 'r-', label='fit')

# Constrain the optimization to the region of ``0 < a < 3``, ``0 < b < 2``
# and ``0 < c < 1``:

popt, pcov = curve_fit(fitFunc, xdata, ydata, bounds=(0, 1))
plt.plot(xdata, fitFunc(xdata, *popt), 'g--', label='fit-with-bounds')

plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()

x = numpy.linspace(0.01, 3.14, 1000)
y = []
for i in x:
    y.append(convolve(i))

y = numpy.array(y)"""
"""
print(convolve(numpy.radians(0)))
print(convolve(numpy.radians(5)))
print(convolve(numpy.radians(10)))
print(convolve(numpy.radians(15)))
print(convolve(numpy.radians(20)))
print(convolve(numpy.radians(30)))
print(convolve(numpy.radians(40)))
print(convolve(numpy.radians(60)))
x = x/(2*3.14159)*360
y = y/1200
pylab.plot(x,y)
pylab.show()"""


