#include <iostream>
#include <queue>
using namespace std;


int main() {
    queue<int> buffer;
    int requests, time;
    cin >> requests;
    for(int i = 0; i < requests; i++){
        cin >> time;
        buffer.push(time);
        while(!buffer.empty() && buffer.front() < time - 5000){
            buffer.pop();
        }
        cout << buffer.size() << " ";
    }
    return 0;
}