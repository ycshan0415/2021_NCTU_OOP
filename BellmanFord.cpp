#include <iostream>
using namespace std;

#define Max 200000

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int begin, target;
    cin >> begin >> target;

    int start[edges], end[edges], cost[edges];
    for (int i = 0; i < edges; i++)
    {
        start[i] = end[i] = cost[i] = 0;
        cin >> start[i] >> end[i] >> cost[i];
    }

    int dist[nodes];
    for (int i = 0; i < nodes; i++)
        dist[i] = Max;
    
    
    dist[begin] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            if (dist[start[j]] != Max && dist[start[j]] + cost[j] < dist[end[j]])  // relax
            {
                dist[end[j]] = dist[start[j]] + cost[j];
            }
        }
    }

    int flag = 0;
    for (int i = 0; i < edges; i++)
    {
        if (dist[start[i]] != Max && dist[start[i]] + cost[i] < dist[end[i]])
        {
            flag = 1;
        }
    }

    if (flag)
        cout << "Negative loop detected!";
    else
        cout << dist[target];

    return 0;
}