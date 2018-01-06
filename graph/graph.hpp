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
    void addVertex(T vertex);
    void addEdge(T start, T end);
    void print();
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

template <typename T>
void Graph<T>::addVertex(T vertex)
{
    if (edges.count(vertex))
        return;
    
    vector<T> v;
    edges.insert({vertex, v});
}

template <typename T>
void Graph<T>::addEdge(T start, T end)
{
    if (edges.count(start))
        edges[start].push_back(end);
    else
    {
        vector<T> v;
        v.push_back(end);
        edges.insert({start, v});
    }
}

template <typename T>
void Graph<T>::print()
{
    for (auto &next: edges)
    {
        cout << next.first << ": ";
        
        auto v = next.second;
        for (auto it = v.begin(); it != v.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}