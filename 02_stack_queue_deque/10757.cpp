//
// Created by Subeen on 8/25/2023.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string calc(string a, string b){
    int sum=0;
    string result="";

    // a문자열을 더 긴 문자열로 맞추기
    if(a.length() < b.length()) {
        string temp = a;
        a = b;
        b = temp;
    }

    // 두 수 뒤집어서 자릿수 맞추기
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // 반복문으로 연산 처리
    for(int i=0; i<a.length();i++){
        // 만약 인덱스가 b의 길이보다 크거나 같다면 a문자열만 추가
        if(i>=b.length()) sum += a[i]-'0';
        else{
            sum = sum + (a[i] - '0') + (b[i] - '0');

        }
        if(sum >= 10) {
            sum = sum -10;
            result += sum + '0';
            sum = 1;
        }
        else{
            result += sum + '0';
            sum = 0;
        }

    }
    if(sum != 0) result += sum + '0';

    // 다시 뒤집기
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    string a, b;
    cin >> a >> b;

    // 연산
    string result = calc(a, b);

    // 출력
    cout << result;

    return 0;
}