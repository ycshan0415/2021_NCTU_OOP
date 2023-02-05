#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	vector<int> v;
    int count;
    char query;
    cin >> count;
    
    for (int i = 0; i < count; i++){
        cin >> query;
        if (query == 'a'){
            int element;
            cin >> element;
            v.push_back(element);
        }
        else if (query == 'e'){
            int element;
            cin >> element;
            for (int j = 0; j < v.size(); j++){
                if (v[j] == element){
                    v.erase(v.begin() + j);
                }
            }
        }
        else if (query == 'r'){
            reverse(v.begin(), v.end());
        }
        else if (query == 'd'){
            v.pop_back();
        }
        else if (query == 's'){
            cout << v.size() << ' ';
        }
        else if (query == 'p'){
            for (int j = 0; j < v.size(); j++){
                cout << v[j] << ' ';
            }
        }
    }
    return 0;
}