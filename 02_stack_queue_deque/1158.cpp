//
// Created by Subeen on 8/25/2023.
//

#include <iostream>
#include <queue>
using namespace std;

vector<int> result(queue<int> &q, int k){
    vector<int> v;  // 제거되는 사람
    int cnt = 1;
    while(!q.empty()){
        while(cnt <k){
            int temp = q.front();
            q.pop();    // 큐의 앞 원소 제거
            // 큐의 뒤에 삽입
            q.push(temp);
            cnt++;
        }
        cnt = 1;
        // 큐의 front 값 vector에 저장 & 삭제
        v.push_back(q.front());
        q.pop();
    }

    return v;
}

int main(){
    queue<int> q;
    vector<int> v;

    // 입력
    int n, k;
    cin >> n >> k;

    // 큐에 값 저장
    for (int i = 0; i < n; ++i) {
        q.push(i+1);
    }

    // 연산
    v = result(q, k);

    // 출력
    cout << "<";
    for (int i = 0; i < v.size(); ++i) {
        if(i==v.size()-1) cout << v[i] << ">";
        else
            cout << v[i] << ", ";
    }
    return 0;
}