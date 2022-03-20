set title "SetHashed Intersection operation"
set xlabel "n"
set ylabel "t"
t(n) = b * n + c 
fit t(x) "zlozonoscB2.dat" using 1:2 via b , c
plot "zlozonoscB2.dat" using 1:2 , t(x) lw 2
pause -1 "Hit any key to continue."