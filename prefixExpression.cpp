#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int size;
    cout << "Enter number of inputs: ";
    cin >> size;
    
    char expression[size];
    int a, b, res;
    
    cout << "Enter expression: ";
    
    for (int i = 0; i < size; i++) {
        cin >> expression[i];
    }
    
     for(int i = size-1; i >= 0; i--){
        switch(expression[i]){
    
            case '+':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b + a;
                s.push(res);
                break;
            case '-':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b - a;
                s.push(res);
                break;
            case '*':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b * a;
                s.push(res);
                break;
            case '/':
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b / a;
                s.push(res);
                break;
            default:
                int num = (int)expression[i] - '0';
                s.push(num);
        }
    }
    cout << "Answer is " << s.top();
    return 0;
}
