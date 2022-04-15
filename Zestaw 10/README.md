# Zestaw 10

## Zadanie A

Średnie czasy przejazdu samochodem pomiędzy polskimi miastami można odczytać z [tabelki](czasy.txt) (dane pochodzą z google maps). W pierwszych dwóch kolumnach znajdują się miasta a w trzeciej kolumnie znajduje się czas przejazdu w minutach. Proszę znaleźć najkrótszy czas przejazdu pomiędzy wszystkimi parami miast. Wynik powinien być w postaci tabeli, której wiersze oraz kolumny odpowiadają kolejnym miastom natomiast wartości tabelki odpowiadają najkrótszym czasom przejazdu.

> Wskazówka: proszę skorzystać z [algorytmu Floyda Warszalla](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm).

### Wynik

Plik `wynik.txt` rozdzielony tabulatorami - [otwórz](wynik.txt)

Wyniki w postaci tabeli

![tabela czasy przejazdów](https://user-images.githubusercontent.com/57668948/163556255-216ca5d3-cbb6-4dae-bdfb-6800d90b9851.png)

## Zadanie B

Korzystająć z [tabelki czasów przejazdu](czasy.txt) (dane pochodzą z google maps) proszę znaleźć najszybszą trasę pomiędzy wszystkimi parami miast. Korzystając z programu `dot` (lub innego programu) oraz [tabelki ze współrzędnymi geograficznymi miast](positions.txt) (pierwsza kolumna zawiera nazwę miasta, druga oraz trzecia kolumna zawiera współrzędne geograficzne) proszę zaznaczyć na grafie wszystkie miasta oraz najszybsze trasy pomiędzy parami miast (jeden rysunek dla każdej pary).

> Wskazówka 1: proszę skorzystać z [algorytmu Floyda Warszalla](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm).
>
> Wskazówka 2: Przykładowy [plik do programu dot](example_dot) gdzie podane są współrzędne wierzchołków. Wykonanie polecenia:
>
> ```text
> dot -Kfdp -n -Tpng example_dot -o example_dot.png
> ```
>
> powinno skutkować stworzeniem pliku:
>
> ![example_dot](https://user-images.githubusercontent.com/57668948/163556280-83456e9f-f9b3-43ab-a637-2832c21ad4ae.png)
>
