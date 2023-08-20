//
// Created by Subeen on 8/20/2023.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, count=0;
    cin >> n >> m;

    vector<string> v1(n);
    vector<string> v2(m);

    // 입력
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());

    for (int i = 0; i < v2.size(); ++i) {
        if(binary_search(v1.begin(), v1.end(), v2[i]))
            count++;
        else continue;
    }

    // 출력
    cout << count;


    return 0;
}