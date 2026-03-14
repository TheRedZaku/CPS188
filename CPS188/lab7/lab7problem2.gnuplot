set terminal svg enhanced size 600,480

set title 'Black Body Radiation'
set xlabel 'Wavelength (μm)'
set ylabel 'Spectral Energy Density (W/m³)'

set key right center top

set xrange [0 : 0.000003]
set xtics ("0.5" 0.0000005, "1" 0.000001, "1.5" 0.0000015, "2" 0.000002, "2.5" 0.0000025, "3" 0.000003)

set yrange [0 : 50000000000000]
set ytics 10000000000000

set grid

plot "blackBodyRadiation.txt" using 1:2 title "3000K" with lp lw 3 lc "#AD2105" pt 0, \
"blackBodyRadiation.txt" using 1:3 title "4000K" with l dt 4 lw 3 lc "#E84120" pt 0, \
"blackBodyRadiation.txt" using 1:4 title "5000K" with l dt 3 lw 3 lc "#F5A190" pt 0