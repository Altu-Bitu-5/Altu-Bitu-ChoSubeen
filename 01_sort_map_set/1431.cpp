//
// Created by Subeen on 8/20/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct guitar{
    string name;
    int sum = 0;
};

// 각 자리 수의 합
int sumAll(string s){

    int sum = 0;

    for (int i = 0; i < s.size(); ++i) {
        if(isdigit(s[i])) sum +=(s[i]-'0');
        else continue;
    }

    return sum;
}


bool compare(guitar a, guitar b){
    if(a.name.size() != b.name.size()){
        return a.name.size() < b.name.size();
    }
    if(a.sum != b.sum) {
        return a.sum < b.sum;
    }
    return a.name < b.name;
}


int main(){

    // 입력
    int n;
    cin >> n;
    vector<guitar> v(n);


    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;   // 기타 이름 입력
    }

    // 각 벡터 sum 구하기
    for (int i = 0; i < n; ++i) {
        v[i].sum = sumAll(v[i].name);
    }

    // 이름의 길이가 짧은 것부터 정렬
    sort(v.begin(), v.end(), compare);

    // 출력
    for (int i = 0; i < n; ++i) {
        cout << v[i].name << '\n';
    }
    return 0;
}