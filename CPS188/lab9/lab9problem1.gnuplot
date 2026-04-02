set terminal svg enhanced size 600,480

set title 'Average Water Temperature over the years'
set xlabel 'Years'
set ylabel 'Temperature (°C)'

#set key right center top

set xrange [1994 : 2026]

set yrange [0 : 14]

set grid
set boxwidth 1
set style fill pattern 

plot "yearlyaveragetemperature.txt" using 1:2 title "Temperature (°C)" with boxes lw 2 lc "#ABABFF" pt 0