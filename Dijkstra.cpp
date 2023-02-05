#include <iostream>
using namespace std;

#define Max 200000

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    int begin, target;
    cin >> begin >> target;

    int graph[nodes][nodes];
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            graph[i][j] = 0;
            
    int start, end, cost;
    for (int i = 0; i < edges; i++)
	{
        cin >> start >> end >> cost;
        graph[start][end] = cost;
    }
    
    int dist[nodes];
    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
	{
        dist[i] = Max;
        visited[i] = false;
    }

    int source = begin; 
    dist[source] = 0;
 
    for (int i = 0; i < nodes - 1; i++)
	{
        int min = Max, idx = 0;
        for (int j = 0; j < nodes; j++)
		{
            if (!visited[j] && dist[j] <= min)
			{
                idx = j;
                min = dist[j];
            }
        }

        int n = idx;
        visited[n] = true;
 
        for (int j = 0; j < nodes; j++)
		{
            if (!visited[j] && graph[n][j] != 0 && dist[n] != 10000
                && dist[n] + graph[n][j] < dist[j])
			{
                dist[j] = dist[n] + graph[n][j];
            }
        }
    }

    cout << dist[target];
    
    return 0;
}