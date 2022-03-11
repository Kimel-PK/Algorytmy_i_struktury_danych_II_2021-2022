# Zestaw 10

## Zadanie A

Średnie czasy przejazdu samochodem pomiędzy polskimi miastami można odczytać z tabelki (dane pochodzą z google maps). W pierwszych dwóch kolumnach znajdują się miasta a w trzeciej kolumnie znajduje się czas przejazdu w minutach. Proszę znaleźć najkrótszy czas przejazdu pomiędzy wszystkimi parami miast. Wynik powinien być w postaci tabeli, której wiersze oraz kolumny odpowiadają kolejnym miastom natomiast wartości tabelki odpowiadają najkrótszym czasom przejazdu.

> Wskazówka: proszę skorzystać z algorytmu Floyda Warszalla.

## Zadanie B

Korzystająć z tabelki czasów przejazdu (dane pochodzą z google maps) proszę znaleźć najszybszą trasę pomiędzy wszystkimi parami miast. Korzystając z programu dot (lub innego programu) oraz tabelki ze współrzędnymi geograficznymi miast (pierwsza kolumna zawiera nazwę miasta, druga oraz trzecia kolumna zawiera współrzędne geograficzne) proszę zaznaczyć na grafie wszystkie miasta oraz najszybsze trasy pomiędzy parami miast (jeden rysunek dla każdej pary).

> Wskazówka 1: proszę skorzystać z algorytmu Floyda Warszalla.

> Wskazówka 2: Przykładowy plik do programu dot gdzie podane są współrzędne wierzchołków. Wykonanie polecenia:
>
> ```text
> dot -Kfdp -n -Tpng example_dot -o example_dot.png```
> ```
>
> powinno skutkować stworzeniem pliku.
