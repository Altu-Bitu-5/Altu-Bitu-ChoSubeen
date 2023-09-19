#include <iostream>
using namespace std;
/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */
int main() {
    // 입출력 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 & 연산
    int m, x, value = 0;    // m: 수행해야할 연산 수
    string op;  // 수행해야할 연산
    cin >> m;   // 수행해야할 연산 수 입력
    // 연산 수만큼 반복
    while (m--) {
        cin >> op;  // 수행해야할 연산 입력 받음

        // x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") {  // 만약 연산이 all이면
            for (int i = 1; i <= 20; i++) { // 반복 - 집합을 {1, 2, 3, ..., 20}으로 바꿈
                value = value | (1 << i);
            }
        }
        else if (op == "empty") {   // 만약 연산이 empty이면
            value = 0;  // 집합을 공집합으로 바꿈
        }

            // x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else {
            cin >> x;   // 피연산자를 입력 받음
            if (op == "add") {  // 만약 연산이 add이면
                value = value | (1 << x);   // 피연산자 x를 추가
            }
            else if (op == "remove") {  // 만약 연산이 remove이면
                value = value & ~(1 << x);  // 피연산자 x를 제거
            }
            else if (op == "check") {   // 만약 연산이 check이면 - 조건에 따라 결과 출력
                if (value & (1 << x)) { // 만약 집합에 x가 있으면
                    cout << "1\n";  // 1을 출력
                } else {    // 집합에 x가 없으면
                    cout << "0\n";  // 0을 출력
                }
            }
            else if (op == "toggle") {  // 만약 연산이 toggle이면
                value = value ^ (1 << x);   // x가 있으면 제거, 없으면 추가
            }
        }
    }
    return 0;
}