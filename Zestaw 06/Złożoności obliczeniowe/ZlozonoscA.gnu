set title "ADTgraph removeVertex operation"
set xlabel "n"
set ylabel "t"
t(n) = a * n * n + b * n + c
fit t(x) "zlozonoscA.dat" using 1:2 via a , b , c
plot "zlozonoscA.dat" using 1:2 , t(x) lw 2
pause -1 "Hit any key to continue."