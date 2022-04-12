# Zestaw 1

## Zadanie A

Proszę zaimplementować typ danych setSimple reprezentujący matematyczny zbiór oraz operacje które dla dwóch zbiorów `A`, `B` realizują:

- sumę zbiorów `A ∪ B`
- część wspólną zbiorów `A ∩ B`
- różnicę zbiorów `A - B`
- sprawdzanie identyczności zbiorów `A ≡ B`

oraz dla elementu `x` i zbioru `A` realizują:

- wstawianie `x` do zbioru `A`
- usuwanie `x` ze zbioru `A`
- sprawdzanie czy `x ∈ A`

Proszę założyć, że istnieje skończona liczba `N` możliwych elementów. Można sobie na przykład wyobrazić, że wszystkie rozpatrywane przez nas zbiory są podzbiorami pewnego zbioru `Ω` zawierającego `N` elementów. Dzięki takiemu założeniu implementacja każdego z rozpytywanych zbiorów może być oparta na jednowymiarowej tablicy o rozmiarze `N`. Każdy index `i` = 1 ... `N` (lub `i` = 0 ... `N` - 1) tej tablicy odpowiadałby jednemu z elementów `Ω`. Wartość przechowywana w tablicy pod indeksem `i` (lub `i` - 1) wskazuje na to czy dany element należy (np. `true` , `1`) do rozpatrywanego zbioru czy nie (np. `false`, `0`).

Państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych operacji. Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.

## Zadanie B

Proszę zaimplementować typ danych `setLinked` reprezentujący matematyczny zbiór oraz wszystkie operacje z `zadania A`. Tym razem w implementacji proszę wykorzystać posortowane listy łączone.

Podobnie jak w poprzednim zadaniu państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych operacji. Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.

## Zadanie C

Korzystając z wyników zadań A oraz B proszę się zastanowić która implementacja jest lepsza i w jakiej sytuacji. Swoją odpowiedź proszę przesłać za pośrednictwem e-mail. Uwaga: to zadanie może być zaliczone pod warunkiem prawidłowego wykonania A oraz B.

### Odpowiedź

Przechowywanie danych w tablicy (`SetSimple`), świetnie sprawdza się w stosunkowo małych lub gęstych zbiorach. Złożoność obliczeniowa jest bardzo mała, kosztem zajmowanej pamięci. Wielkość zbioru musi być z góry znana.

Lista wiązana (`SetLinked`) sprawdza się najlepiej, kiedy chcemy oszczędzać przestrzeń w RAMie. Struktura bez względu na postać zbioru jest gęsto upakowana. Niestety kosztem niskiego zużycia pamięci jest większa złożoność obliczeniowa. Wielkość zbioru nie musi być z góry określona.

## Zadanie D

Proszę zaimplementować typ danych `dictionarySimple`, będący uproszczoną wersją zbioru, posiadającą jedynie trzy operacje:

- wstawianie `x` do zbioru `A`
- usuwanie `x` ze zbioru `A`
- sprawdzanie czy `x ∈ A`

Tym razem w zbiorze przechowywane będą ciągi znaków o długości 50. W implementacji proszę wykorzystać jednowymiarową tablicę, której elementy są ciągami znaków.

Podobnie jak w poprzednich zadaniach państwa implementację proszę wykorzystać w programie, który bada złożoność obliczeniową poszczególnych metod (lub funkcji). Dla każdej z zaimplementowanych operacji program powinien produkować jeden plik, który może być uruchomiony z wykorzystaniem programu gnuplot. W wiadomości e-mail proszę opisać podejście wykorzystane do badania złożoności obliczeniowej i skonfrontować Państwa wyniki z wartościami teoretycznymi.

Dodatkowo proszę porównać te wyniki do Państwa wyników z A oraz B i zastanowić się która implementacja jest lepsza i w jakiej sytuacji. Swoją odpowiedź proszę przesłać za pośrednictwem e-mail.

## UWAGI

- Dla każdej implementacji typu danych oraz dla każdej zaimplementowanej operacji proszę dodatkowo:
  - zamieścić w Państwa programie test sprawdzający czy operacje są zaimplementowane prawidłowo
  - aby ułatwic Państwu pracę możemy się umówić, że w teście będzie sprawdzana niewielka ilość przypadków - na tyle mała aby można było je wypisać na ekranie komputera i przeanalizować ręcznie
- Badając złożoność obliczeniową operacji, proszę się zastanowić jak powina wyglądać zależność `t(n)` czasu wykonania problemu `(t)` od rozmiaru problemu `(n)` i nanieść tą hipotezę na odpowiedni wykres. Wystarczy zbadanie złożoności obliczeniowej jednej wybranej operacji dla danego problemu.
- W większości zadań nie jest określony typ danych elementów zbioru. Można korzystać na przykład z liczb całkowitych. Nie powinno mieć to większego znaczenia jeżeli pewne warunki są spełnione. Jakie to warunki?
  - Wskazówka: `≡`, `<`, `>`
