# Zestaw 2

## Zadanie A

Implementacja zbioru wykorzystująca jednowymiarowe tablice o skończonym rozmiarze z `zadania A` w `zestawie 1` zakłada, że każdemu elementowi zbioru można przypisać liczbę naturalną `1 ... N`. Proszę zaimplementować funkcje implementujące takie przyporządkowanie dla zbiorów:

- liczb całkowitych `n`, `n + 1`, `n + 2`, ... , `m` gdzie `n < m`
- liczb całkowitych `n`, `n + 2`, `n + 4`, ... , `m` gdzie `n < m`
- liter `a`, `b`, `c`, ... , `z`, bez polskich znaków `ęóąśłżźć`
- dwuliterowych napisów, gdzie każda litera jest z zakresu `a - z` bez polskich znaków `ęóąśłżźć`

## Zadanie B

Proszę zaimplementować typ danych setHashed reprezentujący matematyczny zbiór oraz operacje które dla dwóch zbiorów `A`, `B` realizują:

- sumę zbiorów `A ∪ B`
- część wspólną zbiorów `A ∩ B`
- różnicę zbiorów `A - B`
- sprawdzanie identyczności zbiorów `A ≡ B`

oraz dla elementu `x` i zbioru `A`

realizują:

- wstawianie `x` do zbioru `A`
- usuwanie `x` ze zbioru `A`
- sprawdzanie czy `x ∈ A`

Tym razem proszę wykrzystać haszowanie otwarte. Państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych operacji. Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.

## Zadanie C

Korzystając z wyników zadań `A` oraz `B` z `zestawu 1` oraz `zadania B` z obecnego zestawu proszę się zastanowić która implementacja jest lepsza i w jakiej sytuacji.

Aby ułatwić Państwu zadanie, proszę założyć, że elementami przechowywanymi we wszystkich zbiorach są słowa składające się z 4 liter (bez polskich znaków). Można wykorzystać `zadanie A`.

### Odpowiedź

`SetSimple` - zbiór oparty na tablicy lub tablicy wielowyimarowej, sprawdza się w sytuacjach gdy nasze dane są "gęste" i stosunkowo małych rozmiarów. Tablica zapewnia nam złożoność O(1) w większosci operacji kosztem przestrzeni zajmowanej w pamięci lub na dysku.

`SetLinked` - zbiór oparty na liście wiązanej, sprawdza się w sytuacjach gdy dane są "rzadkie" i nie potrzebnie przechowywalibyśmy w pamięci dużo pustych pól. Wielkość zbioru w pamięci zależy tylko od jego zapełnienia, kosztem bardziej złożonych operacji dodawania, odejmowania czy wyszukiwania.

`SetHashed` - zbiór oparty na listach wiązanych z wykorzystaniem hashowania, posiada zalety `SetLinked` jednocześnie usprawniając operacje wyszukiwania. Dobrze dobrana ilość "binów" szybko zawęża obszary poszukiwań zapewniając lepszą złożoność obliczeniową wyszukiwania niż zwykły zbiór oparty na listach wiązanych.

## UWAGI

- Dla każdej implementacji typu danych oraz dla każdej zaimplementowanej operacji proszę dodatkowo:
  - zamieścić w Państwa programie test sprawdzający czy operacje są zaimplementowane prawidłowo
  - aby ułatwic Państwu pracę możemy się umówić, że w teście będzie sprawdzana niewielka ilość przypadków - na tyle mała aby można było je wypisać na ekranie komputera i przeanalizować
- Badając złożoność obliczeniową operacji, proszę się zastanowić jak powina wyglądać zależność `t(n)` czasu wykonania problemu `(t)` od rozmiaru problemu `(n)` i nanieść tą hipotezę na odpowiedni wykres. Wystarczy jeden wykres dla wybranej operacji w danym problemie.
- W większości zadań nie jest określony typ danych elementów zbioru. Można korzystać na przykład z liczb całkowitych. Nie powinno mieć to większego znaczenia jeżeli pewne warunki są spełnione. Jakie to warunki?
  - Wskazówka: `≡`, `<`, `>`
