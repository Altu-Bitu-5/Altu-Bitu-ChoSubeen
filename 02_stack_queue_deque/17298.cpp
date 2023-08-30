//
// Created by Subeen on 8/29/2023.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findNge(stack<int> &s){
    vector<int> nges = {-1};
    vector<int> temp;

    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
        if(s.empty()) break;
        for (int i = temp.size()-1; i >= 0; --i) {
            if(s.top() < temp[i]){
                nges.push_back(temp[i]);
                break;
            }
            else continue;
        }
        if(nges.size()-1 != temp.size()){
            nges.push_back(-1);
        }
    }
    return nges;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, element;
    stack<int> s;
    vector<int> v;

    // 입력
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        s.push(element);
    }

    // 연산
    v = findNge(s);

    for (int i = v.size()-1; i >= 0 ; --i) {
        cout << v[i] << " ";
    }

    return 0;
}
