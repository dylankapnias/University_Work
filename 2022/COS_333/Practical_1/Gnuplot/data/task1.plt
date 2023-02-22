set datafile separator comma
set title 'Polynomial Regression on Iris Dataset'

set xlabel 'Petal Length (cm)'
set ylabel 'Petal Width (cm)'

set xrange[0.75:7.25]
set yrange[0:2.75]

f(x)=a*x**3+b*x**2+c*x+d

fit f(x) 'iris.data' using 3:4 via a,b,c,d

plot 'iris.data' using 3:4 lt 6 lc rgb 'blue', f(x) lc rgb 'red'
