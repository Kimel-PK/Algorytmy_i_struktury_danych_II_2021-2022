set title "PriorityQueueBinary Dequeue operation"
set xlabel "n"
set ylabel "t"
t(n) = b * log(n) + c
fit t(x) "zlozonoscB.dat" using 1:2 via b , c
plot "zlozonoscB.dat" using 1:2 , t(x) lw 2
pause -1 "Hit any key to continue."