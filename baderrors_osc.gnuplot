set term pngcairo size 900,600
set output 'BadErrors.png'
set logscale xy
set xlabel 'N (points)'
set ylabel 'relative error'
set key left top
set grid xtics ytics
set datafile separator '\t'
plot 'osc_even.tsv' using 1:2 with linespoints title 'trapezoid', \
     'osc_odd.tsv'  using 1:3 with linespoints title 'Simpson (odd N)', \
     'osc_even.tsv' using 1:4 with linespoints title 'Gaussian'

