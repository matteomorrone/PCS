#include <iostream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

class unidirected_edge 
{
    int from_;
    int to_;

public:
    unidirected_edge(int a, int b)
        : from_(std::min(a,b)), to_(std::max(a,b))
    {}
    
    int from() const {return from_;}
    int to()   const {return to_;}

    /* Operator < */
    bool operator<(const unidirected_edge& altro) const 
    {
        if (from_ != altro.from_) return from_ < altro.from_; 
        return to_ < altro.to_; 
    }

    /* Operator == */
    bool operator==(const unidirected_edge& altro) const 
    {
        return (from_ == altro.from_ && to_ == altro.to_);
    }
};

std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) 
{
    os << "(" << e.from() << "," << e.to() << ")";
    return os;
}

class unidirected_graph
{
    std::map<int, std::set<int>>       vicini;
    std::map<unidirected_edge, int>    numeri;
    std::vector<unidirected_edge>      archi;

public:
    /* Costruttore di default */
    unidirected_graph()
    {}

    /* Costruttore di copia */
    unidirected_graph(const unidirected_graph& altro)
        : vicini(altro.vicini), numeri(altro.numeri), archi(altro.archi)
    {}

    /* neighbours() */
    std::set<int> neighbors(int n) const 
    {
        return vicini.at(n);
    }
    
    /* add_edge() */
    void add_edge(int a, int b) 
    {
        unidirected_edge e(a,b);
        if (numeri.find(e) == numeri.end()) // Per vedere se l'arco c'è già
        {
            int numero = archi.size();
            archi.push_back(e);
            numeri[e] = numero;
            vicini[a].insert(b);
            vicini[b].insert(a);
        }
    }

    /* all_edges() */
    std::vector<unidirected_edge> all_edges() const {return archi;}

    /* all_nodes() */
    std::set<int> all_nodes() const 
    {
        std::set<int> nodi;
        for (const auto& coppia : vicini) nodi.insert(coppia.first); // La coppia è (nodo, valore)
        return nodi;
    }

    /* edge_number() */
    int edge_number(const unidirected_edge& e) const 
    {
        return numeri.at(e);
    }

    /* edge_at() */
    unidirected_edge edge_at(int i) const 
    {
        return archi.at(i);
    }
    
    /* operator-() */
    unidirected_graph operator-(const unidirected_graph& altro) const 
    {
        unidirected_graph risultato;
        for (const auto& e : archi) 
        {
            if (altro.numeri.find(e) == altro.numeri.end()) risultato.add_edge(e.from(), e.to());
        }
        return risultato;
    }
};


    