//
// Created by Subeen on 9/19/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string base_word = "";

int findSimilarWord(string str) {
    vector<int> checkString(base_word.size());
    int cnt = 0;
    // 만약 str 길이가 base_word와 같으면
    if (str.size() == base_word.size()) {
        // 하나만 다르면 ok
        for (int i = 0; i < base_word.size(); ++i) {
            if (str.find(base_word[i]) == string::npos) {    // 존재하지 않음
                cnt++;
            }
            if (cnt >= 2) return 0;
        }
        return 1;
    } else if (str.size() == base_word.size() - 1) {
        // str의 문자들이 base_word에 있으면 ok
        for (int i = 0; i < base_word.size(); ++i) {
            if (str.find(base_word[i]) == string::npos) {
                return 0;
            }
            //if (cnt >= 2) return 0;
        }
        return 1;
    } else if (str.size() == base_word.size() + 1) {
        //
        for (int i = 0; i < str.size(); ++i) {
            if (base_word.find(str[i]) == string::npos) { // 없을때
                return 0;
            } else {
                checkString[i]++;
            }
        }
        //
        if (find(checkString.begin(), checkString.end(), 0) != checkString.end()) {
            return 0;
        } else {
            return 1;
        }

    } else return 0;

}


int main() {

    // 입력
    int n, count = 0;  // 단어개수
    string word;  // 기준이 되는 단어
    cin >> n;
    cin >> base_word;

    n--;
    while (n--) {
        cin >> word;
        int tmp = findSimilarWord(word);
        count += tmp;
    }

    cout << count;
    return 0;
}
