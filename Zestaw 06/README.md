# Zestaw 6

## Zadanie A

Proszę zaimplementować ADT graph, posiadający wszystkie operacje z zadania A w zestawie 4. Tym razem proszę wykorzystać reprezentację w której dla każdego wierzchołka przechowywana jest list sąsiadów. Sprawdzić złożoność obliczeniową wybranej operacji i porównać z zadaniem `A` zestawu 4.

## Zadanie B

Proszę się zastanowić jak wykorzystać reprezentację grafową do rozwiązania problemu znalezienia minimalnej liczby "faz" sygnalizacji świetlnej na skrzyżowaniu (strzałeczki oznaczają ulice jednokierunkowe):

![schemat skrzyżowań](https://user-images.githubusercontent.com/57668948/157849939-aead0c05-46c2-4447-97b6-57cad2cd195b.jpg)

Sygnalizacja świetlna w każdej "fazie" powinna zezwalać na ruch przez skrzyżowanie jedynie tym samochodom, których trajektorie nie będą się przecinać. Aby usprawnić działanie skrzyżowania, liczba tych etapów powinna być jak najmniejsza.

Wykorzystując jedną z napisanych przez Państwa implementacji grafów oraz zadanie A z poprzedniego zestawu proszę narysować reprezentację grafową takiego skrzyżowania.

## Odpowiedź

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
A -> 2 -> 1 -> 4 -> (B/C)
A -> 2 -> 1 -> D
B -> 3 -> A
B -> 3 -> 2 -> 1 -> 4 -> C
B -> 3 -> 2 -> 1 -> D
D -> 4 -> 3 -> A
D -> 4 -> (B/C)
E -> 1 -> 4 -> 3 -> A
E -> 1 -> 4 -> (B/C)
E -> 1 -> D
```

Aby rozwiązać problem musimy znaleźć najmniejszą liczbę podzbiorów powyższego zbioru, w którym trasy nie mogą mieć wspólnych węzłów `1`, `2`, `3`, `4` chyba że mają wspólny początek.

## Zadanie C

Na szachownicy, na określonej pozycji, znajduje się pojedyncza figura - skoczek (koń). Proszę znaleźć taką trasę skoczka po szachownicy, aby każde pole było odwiedzone jedynie raz. Można wykorzystać jedną z wcześniej zaimplementowanych przez Państwa reprezentacji grafu lub skorzystać z gotowych bibliotek. Państwa wynik końcowy proszę przedstawić w formie rysunku.

### Rozwiązanie BruteForce

Rekurencyjne sprawdzanie wszystkich możliwości w około godzinę zwróciło następujący wynik:

![bruteforce](https://user-images.githubusercontent.com/57668948/161426511-410c5c6c-9be6-4caf-9595-288f4b95d23e.png)

### Algorytm Warnsdorffa

Algorytm Warnsdorffa pozwala na rozwiązanie tego problemu w czasie liniowym.

Jedno z rozwiązań (każde uruchomienie programu startuje z losowego pola szachownicy) zwrócone natychmiast:

![warnsdorff](https://user-images.githubusercontent.com/57668948/161426521-709eb4fa-713e-4530-9f5f-e653fbad59cb.png)
