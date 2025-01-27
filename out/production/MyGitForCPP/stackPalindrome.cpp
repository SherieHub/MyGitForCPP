        #include <iostream>
#include <stack>
using namespace std;

bool is_palindrome(string str){
    stack<char> s;
    char letter;
    
    for(int i = 0; i < str.length(); i++){
        if(i < str.length()/2){
            s.push(str[i]);
        }
        
        if(i == str.length()/2 && str.length() % 2 != 0) continue;
        
        if(i >= str.length()/2){
           letter = s.top();
            s.pop();
            if(letter != str[i]){
                return false;
            } 
        }
    }
    return true;
}

int main(){
    string str;
    
    cout << "Enter a string: ";
    cin >> str;
    
    if(is_palindrome(str)){
        cout << "The string is a palindrome!" << endl;
    }else{
        cout << "The string is not a palindrome!" << endl;
    }
    return 0;
}
