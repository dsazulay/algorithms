#include "graph_algorithms.hpp"

int main (int argc, char *argv[])
{
    Graph<char> myGraph;

    breadthFirstSearch(myGraph, 'A');

    return 0;
}



