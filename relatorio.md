# Ideias

## Common ancestor 

> bfs aos dois vertices, guardar o "nivel" dos vertices e comparar com os do mesmo nivel do outro

## Arvore genealogica

- cada vertice pode ter 0, 1 ou 2 arestas a acabar em si
- não pode haver loops

> podemos percorrer todas as arestas e guardar o numero de ocorrencias do vertice de chegada, this breaks when any reaches 3 -> **O(n)**

> podemos ver loops com uma dfs -> **O(V+E)**

# 
### Links

- https://www.baeldung.com/cs/lowest-common-ancestor-acyclic-graph
- https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
- https://www.geeksforgeeks.org/graph-and-its-representations/

