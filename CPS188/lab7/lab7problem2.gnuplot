# This app is a Gnuplot file (dem, plot, gp..) viewer, editor, compiler for your browser.
# It allows you to create and view Gnuplot file directly on your browser and generate a SVG image.
# This app only works locally without going through the server. It allows you to view/compile Gnuplot file instantly, real-time.
# You can choose a Gnuplot file to edit from your computer or from Google Drive.
# You can easily view or edit your Gnuplot file including plot, data, functions.

# How to change output SVG width/height size ex) set terminal svg enhanced size 800,600
# Please do not set "output" filename, The default is "output/out.svg". Changing this value may result in an error.
# Use the "Options" menu above to add data and image files.

#set terminal svg enhanced size 600,480

label1 = "T = 3000K"
label2 = "T = 4000K"
label3 = "T = 5000K"

set title 'Black Body Radiation'
set xlabel 'Wavelength (μm)'
set ylabel 'Spectral Energy Density (W/m³)'

set key right center top

set xrange [0 : 0.000003]
set xtics 0.0000005

set yrange [0 : 50000000000000]
set ytics 10000000000000

set grid

plot "blackBodyRadiation.txt" with lp using 2:3
replot "blackBodyRadiation.txt" with lp using 5:6
replot "blackBodyRadiation.txt" with lp using 8:9



