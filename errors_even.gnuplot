set term pngcairo size 900,600
set output 'Errors.png'
set logscale xy
set xlabel 'N (points)'
set ylabel 'relative error'
set key left top
set grid xtics ytics
set datafile separator '\t'
plot 'errors_even.tsv' using 1:2 with linespoints title 'trapezoid', \
     ''                using 1:3 with linespoints title 'Simpson',   \
     ''                using 1:4 with linespoints title 'Gaussian'
set output 'Errors_OddSimpson.png'
set logscale xy
set xlabel 'N (points)'
set ylabel 'relative error'
set key left top
set grid xtics ytics
set datafile separator '\t'
plot 'errors_odd.tsv' using 1:2 with linespoints title 'trapezoid', \
     'errors_odd.tsv' using 1:3 with linespoints title 'Simpson (odd N)', \
     'errors_odd.tsv' using 1:4 with linespoints title 'Gaussian'
