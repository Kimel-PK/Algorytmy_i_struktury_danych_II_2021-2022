# Zestaw 11

## Zadanie A

Prowadzicie Państwo serwis internetowy zapewniający dostęp do gier za pośrednictwem strumienia danych. Gry są uruchamiane na serwerach w waszej firmie i chcecie rozsyłać obraz oraz dźwięk do swoich użytkowników z jak najmniejszym opóźnieniem. Zbadaliście sieć połączeń pomiędzy waszą firmą oraz komputerami `127` klientów (jesteście raczkującą firmą) oraz zapisaliście ją w [pliku](randgraph). Pierwsze dwie kolumny zawierają indywidualne numery `2 ... 128` komputerów (numer `1` to wasza firma, numery to komputery klientów) pomiędzy, którymi są połączenia. Trzecia kolumna zawiera średnie opóźnienie sygnału z danymi dla danego połączenia. Aby znaleźć optymalną ścieżkę sygnału z danymi od waszej firmy (numerek `1`) do klientów należy skonstruować minimalne drzewo rozpinające graf połączeń. Proszę korzystając z algorytmu Prima policzyć takie drzewo.

### Odpowiedź A

Program `ZadanieA` generuje rozwiązanie i zapisuje je do pliku o nazwie `wynik.dot`, jednak narysowanie grafu z użyciem biblioteki `Graphviz` daje nieczytelny obraz.

## Zadanie B

Proszę znaleźć drzewko z poprzedniego zadania korzystając z algorytmu Kruskala. Proszę porównać efektywność obydwu algorytmów.
