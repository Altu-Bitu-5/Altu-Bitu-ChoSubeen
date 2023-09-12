//
// Created by Subeen on 9/12/2023.
//
#include <iostream>

using namespace std;

// 명령대로 움직이도록 함
string order(string s, string k_pos, string r_pos) {
    string init_pos = k_pos;
    string r_init_pos = r_pos;
    string k_r_pos = "";
    if (s == "R") {   // 오른쪽
        k_pos[0]++;
        if (k_pos == r_pos) {
            r_pos[0]++;
        }
    } else if (s == "L") {  // 왼쪽
        k_pos[0]--;
        if (k_pos == r_pos) {
            r_pos[0]--;
        }
    } else if (s == "B") {    // 아래
        k_pos[1]--;
        if (k_pos == r_pos) {
            r_pos[1]--;
        }
    } else if (s == "T") {    // 위
        k_pos[1]++;
        if (k_pos == r_pos) {
            r_pos[1]++;
        }
    } else if (s == "RT") {    // 오른위 대각선
        k_pos[0]++;
        k_pos[1]++;
        if (k_pos == r_pos) {
            r_pos[0]++;
            r_pos[1]++;
        }
    } else if (s == "LT") {    // 왼위 대각선
        k_pos[0] -= 1;
        k_pos[1] += 1;
        if (k_pos == r_pos) {
            r_pos[0] -= 1;
            r_pos[1] += 1;
        }
    } else if (s == "RB") {    // 오른아래 대각선
        k_pos[0] += 1;
        k_pos[1] -= 1;
        if (k_pos == r_pos) {
            r_pos[0] += 1;
            r_pos[1] -= 1;
        }
    } else if (s == "LB") {    // 왼아래 대각선
        k_pos[0] -= 1;
        k_pos[1] -= 1;
        if (k_pos == r_pos) {
            r_pos[0] -= 1;
            r_pos[1] -= 1;
        }
    }

    // 문자 아스키코드로 비교하여 체스판 넘어가는 경우 처리
    if (k_pos[0] < 65 || k_pos[0] > 72 || k_pos[1] < 49 || k_pos[1] > 56 || r_pos[0] < 65 || r_pos[0] > 72 ||
        r_pos[1] < 49 || r_pos[1] > 56) {
        k_pos = init_pos;
        r_pos = r_init_pos;
    }

    k_r_pos = k_pos + r_pos;
    return k_r_pos;
}

int main() {
    // 입력
    string king_pos, rock_pos, moving_order, final_pos;
    int moving_num;
    cin >> king_pos >> rock_pos >> moving_num;

    // 연산
    final_pos = king_pos + rock_pos;
    for (int i = 0; i < moving_num; ++i) {
        cin >> moving_order;
        final_pos = order(moving_order, final_pos.substr(0, 2), final_pos.substr(2));
    }

    // 출력
    cout << final_pos[0] << final_pos[1] << "\n" << final_pos[2] << final_pos[3];
    return 0;
}
