//
// Created by Subeen on 9/3/2023.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// 최대공약수 찾기
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 분수 더하기
pair<ll, ll> plusFraction(pair<ll, ll> p1, pair<ll, ll> p2) {
    pair<ll, ll> sum;

    // 분모의 최소공배수 찾기
    ll lcm = p1.second * p2.second / gcd(max(p1.second, p2.second), min(p1.second, p2.second));
    sum.second = lcm;

    // 분자 계산
    sum.first = p1.first * lcm / p1.second + p2.first * lcm / p2.second;

    // 기약분수로 만들기
    ll n = gcd(max(sum.first, sum.second), min(sum.first, sum.second));
    sum.first = sum.first / n;
    sum.second = sum.second / n;

    return sum;
}

int main() {

    // 입력
    pair<ll, ll> p1, p2, ans;   // <분자, 분모>
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;


    // 연산
    ans = plusFraction(p1, p2);

    // 출력
    cout << ans.first << " " << ans.second;

    return 0;
}