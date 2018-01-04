#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include "graph.hpp"

template <typename Graph>
void breadthFirstSearch(Graph graph, typename Graph::node start)
{
    typedef typename Graph::node node;

    queue<node> frontier;
    unordered_set<node> visited;

    frontier.push(start);

    while (!frontier.empty())
    {
        auto current = frontier.front();
        frontier.pop();

        cout << "Visiting: " << current << endl;
        visited.insert(current);
        
        for (auto& next: graph.neighbors(current))
        {
            if (!visited.count(next))
                frontier.push(next);
        }
    }
}

template <typename Graph>
void deepFirsthSearch(Graph graph, typename Graph::node start)
{
    typedef typename Graph::node node;

    stack<node> frontier;
    unordered_set<node> visited;

    frontier.push(start);

    while (!frontier.empty())
    {
        auto current = frontier.top();
        frontier.pop();
        
        if (!visited.count(current))
        {
            cout << "Visiting: " << current << endl;
            visited.insert(current);
            
            auto edges = graph.neighbors(current);

            for (auto it = edges.rbegin();
                it != edges.rend();
                ++it)
            {
                frontier.push(*it);
            }
        }
    }
}

template <typename Graph>
bool isCyclicUtil(Graph graph, typename Graph::node node, unordered_set<typename Graph::node> visited, unordered_set<typename Graph::node> recStack)
{
    if (!visited.count(node))
    {
        visited.insert(node);
        recStack.insert(node);
    
        auto edges = graph.neighbors(node);

        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            if (!visited.count(*it) && isCyclicUtil(graph, *it, visited, recStack))
                return true;
            else if (recStack.count(*it))
                return true;
        }
    }

    recStack.erase(node);
    return false;
}

template <typename Graph>
bool isCyclic(Graph graph, typename Graph::node start)
{
    typedef typename Graph::node node;
    
    unordered_set<node> visited;
    unordered_set<node> recStack;

    auto edges = graph.neighbors(start);

    // TODO: iterate over all vertices
    // for (auto it = edges.begin(); it != edges.end(); ++it)
    // {
        if (isCyclicUtil(graph, start, visited, recStack))
            return true;
    // }

    return false;
}