#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph
{
    private:
        vector<pair<int, edge> > graph;
        vector<pair<int, edge> > MST;
        int *parents;
        int V;
    
    public:
        Graph(int V);
        void AddWeightedEdge(int u, int v, int w);
        int find_set(int i);
        void union_set(int u, int v);
        void Kruskal();
        void print();
};

Graph::Graph(int V)
{
    parents = new int[V];

    for (int i = 0; i < V; i++)
        parents[i] = i;

    graph.clear();
    MST.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w)
{
    graph.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int idx)
{
    while(parents[idx] != idx)
    {  
        parents[idx] = parents[parents[idx]];  
        idx = parents[idx];  
    }  
    return idx;  
}

void Graph::union_set(int u, int v)
{
    parents[u] = parents[v];
}

void Graph::Kruskal()
{
    int i, uRep, vRep;
    sort(graph.begin(), graph.end());  // increasing weight
    for (i = 0; i < graph.size(); i++)
    {
        uRep = find_set(graph[i].second.first);
        vRep = find_set(graph[i].second.second);
        if (uRep != vRep)
        {
            MST.push_back(graph[i]);
            union_set(uRep, vRep);
        }
    }
}

void Graph::print()
{
    int total = 0;
    for (int i = 0; i < MST.size(); i++)
    {
        total += MST[i].first;
    }
    cout << total;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    Graph g(nodes);
    int start, end, cost;
    for (int i = 0; i < edges; i++)
    {
        cin >> start >> end >> cost;
        g.AddWeightedEdge(start, end, cost);
    }

    g.Kruskal();
    g.print();
    
    return 0;
}

