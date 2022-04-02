# Zestaw 4

## Zadanie A

Proszę zaimplementować ADT graph, który dla grafu `G` oraz wierzchołków `x`, `y` ma implementacje następujących operacji:

- `adjacent (G, x, y)` - sprawdzanie, czy istnieje krawędź pomiędzy `x` oraz `y`
- `neighbours (G, x)` - zwraca sąsiadów `x`
- `addVertex (G, x)` - dodaje `x` do `G`
- `removeVertex (G, x)` - usuwa `x` z `G`
- `addEdge (G, x, y)` - dodaje krawędź pomiędzy `x` i `y`
- `removeEdge (G, x, y)` - usuwa krawędź pomiędzy `x` i `y`
- `getVertexValue (G, x)` - zwraca wartość skojarzoną z `x`
- `setVertexValue (G, x, v)` - kojarzy wartość `v` z wierchołkiem `x`
- `getEdgeValue (G, x, y)` - zwraca wartość skojarzoną z krawędzią pomiędzy `x` oraz `y`
- `setEdgeValue (G, x, y, v)` - kojarzy wartość `v` z krawędzią pomiędzy `x` oraz `y`

Państwa implementację proszę, na początek, oprzeć ma macierzy połączeń. Dodatkowo proszę zbadać złożoność jednej wybranej operacji (wykres oraz opis).
