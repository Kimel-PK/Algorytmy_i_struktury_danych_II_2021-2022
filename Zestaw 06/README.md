# Zestaw 6

## Zadanie A

Proszę zaimplementować ADT graph, posiadający wszystkie operacje z zadania A w zestawie 4. Tym razem proszę wykorzystać reprezentację w której dla każdego wierzchołka przechowywana jest list sąsiadów. Sprawdzić złożoność obliczeniową wybranej operacji i porównać z zadaniem `A` zestawu 4.

## Zadanie B

Proszę się zastanowić jak wykorzystać reprezentację grafową do rozwiązania problemu znalezienia minimalnej liczby "faz" sygnalizacji świetlnej na skrzyżowaniu (strzałeczki oznaczają ulice jednokierunkowe):

![schemat skrzyżowań](https://user-images.githubusercontent.com/57668948/157849939-aead0c05-46c2-4447-97b6-57cad2cd195b.jpg)

Sygnalizacja świetlna w każdej "fazie" powinna zezwalać na ruch przez skrzyżowanie jedynie tym samochodom, których trajektorie nie będą się przecinać. Aby usprawnić działanie skrzyżowania, liczba tych etapów powinna być jak najmniejsza.

Wykorzystując jedną z napisanych przez Państwa implementacji grafów oraz zadanie A z poprzedniego zestawu proszę narysować reprezentację grafową takiego skrzyżowania.

## Odpowiedź

Schemat ulic z zaznaczonymi wszystkimi możliwymi trasami prezentuje się następująco:

![graf trasy](https://user-images.githubusercontent.com/57668948/162615332-a09dd554-055f-4a08-9e29-eac567b2dc90.png)

Budujemy graf, w którym wierzchołkami są możliwe trasy, a krawędzie istnieją pomiędzy trasami, które ze sobą kolidują:

![graf schemat](https://user-images.githubusercontent.com/57668948/162614923-c94434ed-7e44-487a-b4ff-e12f474b8e32.png)

Aby znaleźć najmniejszą ilość cykli musimy zastosować algorytm kolorowania grafu. Każdy kolor odpowiada jednej fazie w cyklu

## Zadanie C

Na szachownicy, na określonej pozycji, znajduje się pojedyncza figura - skoczek (koń). Proszę znaleźć taką trasę skoczka po szachownicy, aby każde pole było odwiedzone jedynie raz. Można wykorzystać jedną z wcześniej zaimplementowanych przez Państwa reprezentacji grafu lub skorzystać z gotowych bibliotek. Państwa wynik końcowy proszę przedstawić w formie rysunku.

### Depth-first search

Rozwiązanie w trakcie przygotowania
