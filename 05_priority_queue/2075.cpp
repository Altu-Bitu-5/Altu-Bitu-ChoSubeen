//
// Created by Subeen on 9/19/2023.
//
#include <iostream>
#include <queue>
using namespace std;


int main(){
    // 입출력 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    // 입력
    int n, x, num_n, m;
    cin >> n;

    // 연산
    m =  n * n; // 전체 숫자 개수
    while(m--){
        cin >> x;
        pq.push(x);

        // 상위 n개의 수만 저장
        if(pq.size() > n){
            pq.pop();
        }
    }

    num_n = pq.top();   // n개의 숫자 중 가장 작은 숫자가 n번째 수

    // 출력
    cout << num_n << "\n";
    return 0;
}
