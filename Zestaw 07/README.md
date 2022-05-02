# Zestaw 7

## Zadanie A

Korzystając wyników `zadania B` z poprzedniego zestawu, proszę napisać program minimalizujący liczbę "faz" sygnalizacji świetlnej dla skrzyżowania:

![schemat skrzyżowań](https://user-images.githubusercontent.com/57668948/157850303-1d4ecd37-298f-40c3-b354-cca0b0c35a28.jpg)

### Zachłanny algorytm kolorowania grafu

Wybieramy wierzchołek, który ma największą ilość sąsiadów i nie został jeszcze pomalowany. Kolorujemy go na pierwszy wolny kolor różny od kolorów sąsiadów.

Wynik zwrócony przez program `ZadanieA`

```text
A-D - 0
D-A - 0
D-B - 0
D-C - 0
A-B - 1
A-C - 1
B-A - 1
E-D - 1
E-A - 2
E-B - 2
E-C - 2
B-C - 3
B-D - 3
```

Otrzymujemy 4 fazy cyklu prezentujące się w nastepujący sposób:


