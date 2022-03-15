set title "SetSimple Sum operation"
set xlabel "n"
set ylabel "t"
t(n) = b * n + c 
fit t(x) "zlozonoscA2.dat" using 1:2 via b , c
plot "zlozonoscA2.dat" using 1:2 , t(x) lw 2
pause -1 "Hit any key to continue."