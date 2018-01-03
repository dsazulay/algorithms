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