//
// Created by Subeen on 9/4/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int idx = 0;    // 마지막으로 화살표가 가리키는 글자의 인덱스

// 행운 바퀴 추측
vector<char> luckWheel(vector<char> &v, int s, char c) {
    idx += s;
    // 만약 s가 vector의 마지막 인덱스 값보다 크면
    if (idx > v.size() - 1) {
        idx = idx - (v.size() - 1);
    }

    // 만약 행운 바퀴 자리가 ?가 아니면
    if (v[idx] != '?' && v[idx] != c) {
        v[idx] = '!';
    } else {
        v[idx] = c;
    }
    return v;
}

int main() {
    int n, k;   // 바퀴 칸 수, 돌리는 횟수
    int s;
    char c;

    // 입력
    cin >> n >> k;

    vector<char> v(n + 1, '?'); // 행운의 바퀴 모든 칸을 ?로 초기화

    // 연산
    while (k--) {
        cin >> s >> c;
        v = luckWheel(v, s, c);

        // 행운의 바퀴가 없는 경우
        if (find(v.begin(), v.end(), '!') != v.end()) {
            break;
        }
    }

    // 출력
    // 행운의 바퀴가 없는 경우
    if (find(v.begin(), v.end(), '!') != v.end()) {
        cout << "!";
    } else {
        v.erase(v.begin()); // A ? B C ?
        idx--;  // idx == 2
        // 재정렬
        while (idx <= v.size() - 1) {
            char tmp = v.back();
            // vector 젤 앞에 tmp 추가
            v.insert(v.begin(), tmp);
            v.pop_back();
            idx++;
        }

        bool isRepete = false;
        // 중복 문자 확인
        for (int i = 0; i < v.size()-1; ++i) {
            for (int j = i+1; j < v.size(); ++j) {
                if(v[i] == v[j] && v[i] != '?'){
                    //cout << "0!";
                    isRepete = true;
                    break;
                }
            }
        }
        // 출력
        if(!isRepete){
            for (int i = v.size(); i > 0; --i) {
                cout << v[i];
            }
        }
        else{
            cout << "!";
        }

    }


    return 0;
}
