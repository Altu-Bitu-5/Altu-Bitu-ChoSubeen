//
// Created by Subeen on 8/20/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// 일일기초대사량 변화 고려 X
void dietResult1(long a, long b, long c, long d, int day){// 일일에너지섭취량, 일일기초대사량, 일일활동대사량, 다이어트전체중, 다이어트 기간
    long losing_weight = 0;  // 일일에너지섭취량 - 일일에너지소비량(=일일기초대사량+일일활동대사량)

    losing_weight = (a - (b + c))*day;

    if((d+losing_weight) <= 0) cout << "Danger Diet" << '\n';
    else cout << (d+losing_weight) << " " << b << '\n';
}

// 일일기초대사량 변화 고려 O(데시 사망 조건 두개임, 요요 여부도 체크해야함)
void dietResult2(long a, long b, long c, long d, long e, int day, int t){// 일일에너지섭취량, 일일기초대사량, 일일활동대사량, 다이어트전체중, 다이어트 기간, 역치
    long losing_weight = 0;
    while(day > 0){ // 다이어트 중
        losing_weight = (a-(b+c));
        d = d + losing_weight;
        if(abs(losing_weight)>t) b-=ceil(abs((double)losing_weight)/2);
        day--;
        if(b<=0 || d<=0) {
            cout << "Danger Diet";
            return;
        }
    }

    // 다이어트 후
    losing_weight = e - b;
    if(losing_weight <= 0) cout << d << ' ' << b << ' ' << "NO";
    else cout << d << ' ' << b << ' ' << "YOYO";

}
//일일활동대사량 = 일일에너지소비량-일일기초대사량
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력 - 다이어트 전 (체중, 일일에너지섭취량, 일일기초대사량)
    long init_weight, init_energy, init_basic;
    int t;  // 기초대사량변화역치
    cin >> init_weight >> init_energy >> t;
    init_basic = init_energy;

    // 입력 - 다이어트 중 (다이어트 기간, 일일에너지섭취량, 일일활동대사량)
    int day;
    long d_energy, d_activity;
    cin >> day >> d_energy >> d_activity;


    // 출력
    dietResult1(d_energy, init_basic, d_activity, init_weight, day);
    dietResult2(d_energy, init_basic, d_activity, init_weight, init_energy, day, t);
    //cout << ceil(abs((double)-5)/2);
    return 0;
}
