#include <iostream>
#include <stack>
using namespace std;


int main() {  
    string input;
    int n, i, j;

    cin >> n;
    for (i = 0; i < n; i++){
        stack<char> brackets;
        cin >> input;
        for (j = 0; j < input.length(); j++){
            if (input[j] == '{' || input[j] == '[' || input[j] == '('){
                brackets.push(input[j]);
            }
            else if (brackets.empty()){
                cout << "no" << endl;
                break;
            }
            else if (input[j] == ')' || input[j] == ']' || input[j] == '}'){
                switch (input[j]){
                    case ')':
                        if (brackets.top() == '('){
                            brackets.pop();
                            break;
                        }
                    case ']':
                        if (brackets.top() == '['){
                            brackets.pop();
                            break;
                        }
                    case '}':
                        if (brackets.top() == '{'){
                            brackets.pop();
                            break;
                        }
                }
            }
        }
        if (j == input.length() && brackets.empty())
            cout << "yes" << endl;
        else if (!brackets.empty())
            cout << "no" << endl;
    }
    return 0;
}