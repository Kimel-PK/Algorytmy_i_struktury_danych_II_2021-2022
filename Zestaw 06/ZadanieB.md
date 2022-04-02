# Zadanie B

## Problem

Wyszukanie najmniejszej ilości "faz" sygnalizacji świetlnej. Samochody, których trasy przecinają się nie mogą jechać jednocześnie podczas trwania fazy.

## Analiza

Problem można zobrazować następującym grafem:

![graph](https://user-images.githubusercontent.com/57668948/161397237-a6c51793-355e-41ea-981b-4c83699667a7.png)

Schemat wygląda trochę jak rondo. Węzły `1`, `2`, `3`, `4` mogą należeć tylko do jednej trasy jednocześnie, ale trasa może się "rozgałęziać".

Przykładowo trasy:

```text
E -> 1 -> D
E -> 1 -> 4 -> C
E -> 1 -> 4 -> B
```

Mogą być wykorzystywane jednocześnie w trakcie trwania fazy. Dodatkowo węzły `2` i `3` są "nie blokowane" to znaczy, że samochody jadące z ulicy `B` mogą bezkolizyjnie skręcać w ulicę `A`.

Wszystkie trasy, które muszą znaleźć się w ciągu jednego pełnego cyklu to:

```text
A -> 2 -> 1 -> 4 -> B
A -> 2 -> 1 -> 4 -> C
A -> 2 -> 1 -> D
B -> 3 -> A
B -> 3 -> 2 -> 1 -> 4 -> C
B -> 3 -> 2 -> 1 -> D
D -> 4 -> 3 -> A
D -> 4 -> B
D -> 4 -> C
E -> 1 -> 4 -> 3 -> A
E -> 1 -> 4 -> B
E -> 1 -> 4 -> C
E -> 1 -> D
```

Aby rozwiązać problem musimy znaleźć najmniejszą liczbę podzbiorów powyższego zbioru, w którym trasy nie mogą mieć wspólnych węzłów `1`, `2`, `3`, `4` chyba że mają wspólny początek.
