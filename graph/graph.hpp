#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
class Graph
{
public:
    typedef T node;
    Graph();
    ~Graph();
    vector<T> vertices();
    vector<node> neighbors(node);
    unordered_map<node, vector<node>> edges;

private:
    
};


template <typename T>
Graph<T>::Graph()
{
    // edges = {
    //     {'A', {'B'}},
    //     {'B', {'A', 'C', 'D'}},
    //     {'C', {'A'}},
    //     {'D', {'E', 'A'}},
    //     {'E', {'B'}}
    // };

    edges = {
        {'A', {'B', 'C'}},
        {'D', {}},
        {'E', {}},
        {'B', {'D', 'E', 'F'}},
        {'C', {'F', 'G'}},
        {'F', {}},
        {'G', {}}
    };
}

template <typename T>
Graph<T>::~Graph()
{

}

template <typename T>
vector<T> Graph<T>::vertices()
{
    vector<T> vertices;
    
    for (auto it = edges.begin(); it != edges.end(); ++it)
        vertices.push_back(it->first);
    
    return vertices;
}

template <typename T>
vector<T> Graph<T>::neighbors(T id)
{
    return edges[id];
}