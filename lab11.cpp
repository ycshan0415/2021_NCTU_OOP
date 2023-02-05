#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[19] = {0}, b[19] = {0};
    int n, e, akey, bkey;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> e;
        for (int j = 0; j < 19; j++){
            akey = (e + j) % 19;
            if (a[akey] == 0){
                a[akey] = e;
                break;
            }
        }
    
        for (int j = 0; j < 9; j++){
            bkey = (e + j*j) % 19;
            if (b[bkey] == 0){
                b[bkey] = e;
                break;
            }
        }
    }

    for (int i = 0; i < 19; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 19; i++){
        cout << b[i] << " ";
    }

    return 0;
}
