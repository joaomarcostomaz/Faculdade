set key bottom right
set terminal pdf enhanced monochrome dashed
set output 'grafico.pdf'
set title '' 
set origin 0.0,0.0 
set xlabel "Numero de Elementos no Conjunto" 
set ylabel "Tempo Gasto(seconds)"
plot 'data.dat' using 1:2 title "tempo" with linespoints linewidth 2 linetype 1
set terminal latex
