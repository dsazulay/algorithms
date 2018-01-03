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
    vector<node> neighbors(node);

private:
    unordered_map<node, vector<node>> edges;
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
        {'B', {'D', 'E', 'F'}},
        {'C', {'F', 'G'}},
        {'D', {}},
        {'E', {}},
        {'F', {}},
        {'G', {}}
    };
}

template <typename T>
Graph<T>::~Graph()
{

}

template <typename T>
vector<T> Graph<T>::neighbors(T id)
{
    return edges[id];
}
