#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    while(1){
        priority_queue<int, vector<int>, greater<int>> heap; 
        int n, v;
        int cost = 0; 
        cin >> n;
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            cin >> v;
            heap.push(v);
        }
        while(heap.size() > 1){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            int sum = x + y;
            heap.push(sum);
            cost += sum;
        }
        cout << cost << endl;
    }  
    return 0;
}
