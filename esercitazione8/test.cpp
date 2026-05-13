#include <iostream>
#include <cstdlib>
#include "grafo.hpp"

int main() 
{
    unidirected_graph g;

    // TEST 1: aggiunta
    g.add_edge(1, 2);
    g.add_edge(2, 1);
    if (g.all_edges().size() != 1) 
    {
        std::cout << "Errore: il grafo dovrebbe avere un solo arco." << std::endl;
        return EXIT_FAILURE;
    }

    // TEST 2: ordine from e to nei nodi
    unidirected_edge e = g.edge_at(0);
    if (e.from() != 1 || e.to() != 2) 
    {
        std::cout << "Errore: i nodi non sono ordinati correttamente nell'arco." << std::endl;
        return EXIT_FAILURE;
    }

    // TEST 3: differenza
    unidirected_graph g1, g2;
    g1.add_edge(10, 20);
    g1.add_edge(20, 30);
    g2.add_edge(20, 30);
    unidirected_graph diff = g1 - g2;
    if (diff.all_edges().size() != 1) 
    {
        std::cout << "Errore nella differenza tra grafi." << std::endl;
        return EXIT_FAILURE;
    }

    // TEST 4: vicini
    std::set<int> v = g1.neighbors(20);
    if (v.count(10) == 0 || v.count(30) == 0)
    {
        std::cout << "Errore: vicini del nodo 20 errati." << std::endl;
        return EXIT_FAILURE;
    }

    // TEST 5: numerazione 
    unidirected_edge e2(10, 20);
    if (g1.edge_number(e2) != 0)
    {
        std::cout << "Errore: numerazione arco errata." << std::endl;
        return EXIT_FAILURE;
    }

    // TEST 6: all_nodes
    std::set<int> nodi = g1.all_nodes();
    if (nodi.count(10) == 0 || nodi.count(20) == 0 || nodi.count(30) == 0)
    {
        std::cout << "Errore: nodi mancanti." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS; 
}