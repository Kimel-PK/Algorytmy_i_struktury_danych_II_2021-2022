# Zestaw 5

## Zadania A

Proszę zapoznać się z pakietem [Graphviz](https://graphviz.gitlab.io/). Następnie korzystając z programu `dot` proszę stworzyć plik `.jpg` z grafem:

- zawierającym trzy wierzchołki
- zawierającym połączenia, w obydwu kierunkach, pomiędzy wszystkimi wierzchołkami

Przykładowy [plik z prostym grafem](smallGraph) oraz [rezultat](smallGraph.jpg). Aby stworzyć obrazek wystarczy w linii komend uruchomić:

```bash
dot -Tjpg smallGraph -o smallGraph.jpg
```

[Tutaj](https://www.graphviz.org/pdf/dotguide.pdf) można znaleźć przewodnik po programie `dot`.

## Zadania B

Proszę uzupełnić Państwa implementację grafu z poprzedniego zestawu o metodę tworzącą plik, który może być wykorzystany przez program `dot` do narysowania grafu.
