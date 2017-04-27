import scipy.integrate as integrate
import math
from sympy.functions.special.delta_functions import Heaviside
import numpy
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.odr import ODR, Model, Data, RealData


def lowerconvolve_func(theta,phi):
    return 1/numpy.power(numpy.sin(theta/2), 4)*(1-numpy.absolute(theta-phi)/0.0998) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + 0.0998) + 1)

def higherconvolve_func(theta,phi):
    return 1/numpy.power(numpy.sin(theta/2), 4)*(1-numpy.absolute(theta-phi)/0.119381) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + 0.119381) + 1)
#* Heaviside(-numpy.absolute(theta-phi) + .122)

def lowerconvolve(phi):
    sol = []
    for i in phi:
        sol.append(integrate.quad(lambda x: lowerconvolve_func(x, i), 0.01, 3.14159)[0])
    #result = integrate.quad(lambda x: convolve_func(x, phi), 0.01, 3.14159)
    return numpy.array(sol)

def higherconvolve(phi):
    sol = []
    for i in phi:
        sol.append(integrate.quad(lambda x: higherconvolve_func(x, i), 0.01, 3.14159)[0])
    #result = integrate.quad(lambda x: convolve_func(x, phi), 0.01, 3.14159)
    return numpy.array(sol)

def lowerfitFunc(A, x):
    return A[0]*lowerconvolve(x)

def higherfitFunc(A, x):
    return A[0]*higherconvolve(x)

def nonConv(A, x):
    return A[0]/numpy.power(numpy.sin(x/2), 4)

"""def plum_convolve_func(theta,phi):
    return numpy.exp(numpy.divide(-numpy.power(theta,2),numpy.power(0.017, 2)))*(1-numpy.absolute(theta-phi)/.122) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + .122) + 1)"""
#* Heaviside(-numpy.absolute(theta-phi) + .122)

def lowerplum_convolve_func(theta,phi, mean):
    return numpy.exp(numpy.divide(-numpy.power(theta,2),numpy.power(mean, 2)))*(1-numpy.absolute(theta-phi)/.122) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + .122) + 1)

def lowerplum_convolve(phi, mean):
    plum_sol = []
    for i in phi:
        plum_sol.append(integrate.quad(lambda x: lowerplum_convolve_func(x, i, mean), 0.0, 3.14159)[0])
    #result = integrate.quad(lambda x: convolve_func(x, phi), 0.01, 3.14159)
    return numpy.array(plum_sol)

def lowerplum_fitFunc(A, x):
    return A[0]*lowerplum_convolve(x, A[1])

def higherplum_convolve_func(theta,phi):
    return numpy.exp(numpy.divide(-numpy.power(theta,2),numpy.power(0.017, 2)))*(1-numpy.absolute(theta-phi)/.119381) *0.5 * (numpy.sign(-numpy.absolute(theta-phi) + .119381) + 1)

def higherplum_convolve(phi):
    plum_sol = []
    for i in phi:
        plum_sol.append(integrate.quad(lambda x: higherplum_convolve_func(x, i), 0.0, 3.14159)[0])
    #result = integrate.quad(lambda x: convolve_func(x, phi), 0.01, 3.14159)
    return numpy.array(plum_sol)

def higherplum_fitFunc(A, x):
    return A[0]*higherplum_convolve(x)


def plum_nonConv(A, x):
    return A[0]*numpy.exp(-numpy.power(x,2)/numpy.power(0.017453,2))

xdata = numpy.array([.174, .2618, .3491, .5236, .6981, .8727, 1.047])
xdata = xdata - 0.0314
ydata = numpy.array([9.64, 0.66, 0.12, 0.02, 0.005, 0.002156, 0.0009])
x_err = numpy.array([0.0087, 0.0087, 0.0087, 0.0087, 0.0087, 0.0087, 0.0087])
y_err = numpy.array([1.79, 0.03, 0.005, 0.00049, 0.000253, 0.00009, 0.00004])
"""xdata = numpy.array([.3491, .5236, .6981, .8727, 1.047])
ydata = numpy.array([ 0.12, 0.02, 0.005, 0.002156, 0.0009])
x_err = numpy.array([ 0.0087, 0.0087, 0.0087, 0.0087, 0.0087])"""
#x_err = x_err*2
#y_err = numpy.array([0.005, 0.00049, 0.000253, 0.00009, 0.00004])
higherconv_model = Model(higherfitFunc)
higherdata = RealData(xdata,ydata, sx=x_err, sy=y_err)
higherodr = ODR(higherdata, higherconv_model, beta0=[0.005])

higherout = higherodr.run()
higherout.pprint()

lowerconv_model = Model(lowerfitFunc)
lowerdata = RealData(xdata,ydata, sx=x_err, sy=y_err)
lowerodr = ODR(lowerdata, lowerconv_model, beta0=[0.005])

lowerout = lowerodr.run()
lowerout.pprint()

lowerplum_conv_model = Model(lowerplum_fitFunc)
lowerplum_data = RealData(xdata,ydata, sx=x_err, sy=y_err)
lowerplum_odr = ODR(lowerplum_data, lowerplum_conv_model, beta0=[0.05, 10])

lowerplum_out = lowerplum_odr.run()
lowerplum_out.pprint()

higherplum_conv_model = Model(higherplum_fitFunc)
higherplum_data = RealData(xdata,ydata, sx=x_err, sy=y_err)
higherplum_odr = ODR(higherplum_data, higherplum_conv_model, beta0=[0.05])

higherplum_out = higherplum_odr.run()
higherplum_out.pprint()


nonconv_model = Model(nonConv)
nondata = RealData(xdata,ydata, sx=x_err, sy=y_err)
nonodr = ODR(nondata, nonconv_model, beta0=[0.005])

nonout = nonodr.run()
nonout.pprint()


plum_nonconv_model = Model(plum_nonConv)
plum_nondata = RealData(xdata,ydata, sx=x_err, sy=y_err)
plum_nonodr = ODR(plum_nondata, plum_nonconv_model, beta0=[0.005])

plum_nonout = plum_nonodr.run()
plum_nonout.pprint()

x_fit = numpy.linspace(xdata[0] - 0.01, xdata[-1]+ .01, 1000)
lowery_fit = lowerfitFunc(lowerout.beta, x_fit)
highery_fit =higherfitFunc(higherout.beta, x_fit)
lowerplum_y_fit = lowerplum_fitFunc(lowerplum_out.beta, x_fit)
higherplum_y_fit = higherplum_fitFunc(higherplum_out.beta, x_fit)
nony_fit = nonConv(nonout.beta, x_fit)
#plum_nony_fit = plum_nonConv(plum_nonout.beta, x_fit)

fig, ax = plt.subplots()

ax.errorbar(xdata*57.296, ydata, xerr=x_err*57.296, yerr=y_err, linestyle='None',ecolor='r', marker='None', label='Experimental Data', mew=10, ms=20)
#ax.semilogy(x_fit*57.296, lowery_fit, label=r'Rutherford Scattering, $\chi^2/$ndf$ = 1.89$', linestyle='--')
ax.semilogy(x_fit*57.296, highery_fit, label=r'Rutherford Scattering, $\chi^2/$ndf$ = 2.14$', linestyle='--')
#ax.fill_between(x_fit*57.296, lowery_fit, highery_fit)
#ax.plot(x_fit*57.296, highery_fit)
#ax.plot(x_fit*57.296, lowerplum_y_fit, color='green')
#plt.plot(x_fit*57.296, y_fit)
ax.semilogy(x_fit*57.296, lowerplum_y_fit, label=r'Thomson Scattering, $\chi^2/$ndf$ = 109$', color='g')
plt.ylabel('Count Rate [1/s]', fontsize=18)
plt.xlabel(r'Howitzer Angle [$\theta$]', fontsize=18)
print(higherfitFunc(higherout.beta,[0]))
#ax.semilogy(x_fit*57.296, nony_fit, label=r'Rutherford Scattering, $\chi^2/$ndf = 8.18')
legend = ax.legend(loc='upper center', fontsize='xx-large')
#plt.plot(x_fit*57.296, plum_nony_fit)
#plt.plot(x_fit*57.296, plum_nony_fit)

axes=plt.gca()
axes.set_ylim([.001, 100])
axes.set_xlim([5, 100])
plt.xticks(fontsize=18)
plt.yticks(fontsize=18)
#plt.yscale('log')

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


