# Zestaw 11

## Zadanie A

Prowadzicie Państwo serwis internetowy zapewniający dostęp do gier za pośrednictwem strumienia danych. Gry są uruchamiane na serwerach w waszej firmie i chcecie rozsyłać obraz oraz dźwięk do swoich użytkowników z jak najmniejszym opóźnieniem. Zbadaliście sieć połączeń pomiędzy waszą firmą oraz komputerami `127` klientów (jesteście raczkującą firmą) oraz zapisaliście ją w [pliku](randgraph). Pierwsze dwie kolumny zawierają indywidualne numery `2 ... 128` komputerów (numer `1` to wasza firma, numery to komputery klientów) pomiędzy, którymi są połączenia. Trzecia kolumna zawiera średnie opóźnienie sygnału z danymi dla danego połączenia. Aby znaleźć optymalną ścieżkę sygnału z danymi od waszej firmy (numerek `1`) do klientów należy skonstruować minimalne drzewo rozpinające graf połączeń. Proszę korzystając z `algorytmu Prima` policzyć takie drzewo.

### Odpowiedź A

Program `ZadanieA` generuje rozwiązanie i zapisuje je do pliku o nazwie `wynikA.dot`, który możemy przedstawić z użyciem biblioteki `Graphviz`. Graf narysowany na podstawie zapisanych danych może i nie należy do najlepszych, ale daje ogólny pogląd na to jak wygląda nasze drzewo.

![wynikA](https://user-images.githubusercontent.com/57668948/166916278-137fd5c7-296e-49a5-8892-7d89f396ed93.png)

## Zadanie B

Proszę znaleźć drzewko z poprzedniego zadania korzystając z `algorytmu Kruskala`. Proszę porównać efektywność obydwu algorytmów.

### Odpowiedź B

Program `ZadanieB` generuje rozwiązanie i zapisuje je do pliku o nazwie `wynikB.dot`, podobnie jak w `Zadaniu A` rysunek grafu nie należy do najlepszych.

![wynikB](https://user-images.githubusercontent.com/57668948/166916301-7d44f9f4-b9c1-4ec2-ae60-476a30d05a65.png)

W podanych przykładzie `algorytm Prima` wykonuje się w czasie rzedu `0,0001` sekundy.

`Algorytm Kruskala` wykonuje się w czasie rzędu `0,0005` sekundy.

Porównanie obu algorytmów:

Algorytm Prima:

- Rozpoczyna budowę od dowolnego wierzchołka grafu
- Może przechodzić przez każdy wierzchołek więcej niż raz
- Ma złożoność rzędu `O(N²)`, gdzie `N` to liczba wierzchołków, złożoność może zostać poprawiona do `O(E log N)` z wykorzystaniem kopca Fibonacciego
- Działa tylko na spójnych grafach
- Działa szybciej w gęstych grafach

Algorytm Kruskala:

- Rozpoczyna budowę od wierzchołka o najmniejszej wadze
- Przechodzi przez każdy wierzchołek tylko raz
- Ma złożoność rzędu `O(E log N)`, gdzie `N` to liczba wierzchołków
- Działa zarówna w grafach spójnych jak i nie spójnych
- Działa szybciej w rzadkich grafach
