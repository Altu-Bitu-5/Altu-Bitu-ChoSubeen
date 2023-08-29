//
// Created by Subeen on 8/28/2023.
//

#include<iostream>
#include <stack>

using namespace std;

// 스택이 비었는지 확인
string check(stack<char> &s) {
    if (s.empty()) return "yes";
    else return "no";
}

// 짝이 맞는지 확인
string checkPair(stack<char> &s, string str) {

    for (int i = 0; i < str.length()-1; ++i) {
        if (str[i] == '(' || str[i] == '[') s.push(str[i]);
        else if (str[i] == ')') {
            if(s.empty()) return "no";
            else if(s.top() == '(') s.pop();
        }
        else if(str[i] == ']'){
            if(s.empty()) return "no";
            else if(s.top()=='[') {
                s.pop();
            }
        }
        else continue;
       // cout << s.top();

    }
   // cout << s.top();
    if(s.empty()) return "yes";
    else return "no";
    //cout << s.top();
    //return check(s);

}




int main() {

    stack<char> s;
    string str, ans;

    while (true) {
        getline(cin, str);
        if (str[0] == '.') break;
        ans = checkPair(s, str);
        //ans = check(s);
        while(!s.empty()) s.pop();

        cout << ans << "\n";
    }

    return 0;
}