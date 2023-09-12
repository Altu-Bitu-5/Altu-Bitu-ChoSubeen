//
// Created by Subeen on 9/12/2023.
//

#include<iostream>
#include <string>

using namespace std;
typedef long long ll;

ll movieTitle(int n) {
    ll title = 666;

    // 반복 - 666부터
    while (true) {
        if (to_string(title).find("666") != string::npos) {
            n--;
        }
        title++;
        if (n == 0) break;
    }

    return title - 1;
}

int main() {

    // 입력
    int n;
    cin >> n;

    // 연산 & 출력
    cout << movieTitle(n);
    return 0;
}