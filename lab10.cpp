#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int adj[100][100], visited[100] = {0};

void DFS(int v){
    cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < n; i++){
        if (adj[v][i] == 1 && visited[i] == 0){
            DFS(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            DFS(i);
            cout << endl;
        }
    }
    return 0;
}
