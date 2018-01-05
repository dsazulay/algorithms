#include "graph_algorithms.hpp"

int main (int argc, char *argv[])
{
    Graph<char> myGraph;

    deepFirsthSearch(myGraph, 'A');
    if (isCyclic(myGraph, 'A'))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}