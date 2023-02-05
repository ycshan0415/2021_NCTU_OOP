#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define Max 200000

void Prim(vector<vector<int>> V)
{
	vector<int> minWeight;
	vector<int> vertex;
	vector<bool> visited;
	vector<int> MST;

    minWeight.resize(V.size());
	visited.resize(V.size());
	fill(visited.begin(), visited.end(), false);
	vertex.push_back(0);
	visited[0] = true;
	fill(minWeight.begin(), minWeight.end(), Max);
	minWeight[0] = 0;
	
	while (vertex.size() < V.size())
	{
		int x = vertex[vertex.size() - 1];         
		for (int i = 0; i < minWeight.size(); ++i)
		{
			if (!visited[i] && V[x][i] < minWeight[i])
			{
				minWeight[i] = V[x][i];
			}
		}

		int min = Max;
		int index = 0;
		for (int i = 0; i < minWeight.size(); ++i)
		{
			if (minWeight[i] < min && !visited[i])
			{
				min = minWeight[i];
				index = i;
			}
		}

		visited[index] = true;
		vertex.push_back(index);
		MST.push_back(min);
	}

    int total = 0;
	for (int i = 0; i < MST.size(); ++i)
	{
		total += MST[i];
	}
    cout << total;
}

int main()
{
	int nodes, edges;
    cin >> nodes >> edges;
    
	vector<vector<int>> V;
	V.resize(nodes);
	
    for (int i = 0; i < nodes; ++i)
	{
		V[i].resize(nodes);
		for (int j = 0; j < nodes; ++j)
			V[i][j] = Max;
	}

    int start, end, cost;
	for (int i = 0; i < edges; ++i)
	{
		cin >> start >> end >> cost;
		V[start][end] = V[end][start] = cost;
	}
	
	Prim(V);

	return 0;
}
