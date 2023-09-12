#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true); // 소수 여부를 저장할 배열
    is_prime[0] = is_prime[1] = false;  // 0과 1은 소수가 아님
    for (int i = 2; i * i <= n; i++) {  // 반복문을 통해 소수 여부를 판단함
        if (!is_prime[i]) { // 이미 소수가 아닌 경우
            continue;   // 넘어감
        }
        for (int j = i * i; j <= n; j += i) {   // i가 소수인 경우
            is_prime[j] = false;    // i의 배수 제거
        }
    }
    return is_prime;    // 소수 여부가 저장된 배열 리턴
}

// n = a + b를 만족시키는 a 반환
int goldbach(int n, vector<bool> &is_prime) {
    for (int a = 3; a <= n / 2; a+= 2) {    // 3보다 크거나 같고 n/2보다 작거나 같은 소수 탐색
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        if (is_prime[a] && is_prime[n - a]) {   // a가 소수이고 n-a가 소수이면
            return a;   // a를 리턴
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0 반환
    return 0;
}

/* [백준 6588: 골드바흐의 추측]
 * 1. 3보다 크거나 같고 n / 2보다 작거나 같은 소수 a를 오름차순으로 탐색한다.
 * 2. 1에서 찾은 a에 대하여 n - a(=b)도 소수이면 골드바흐의 추측이 성립한다.
 * 3. 골드바흐의 추측이 성립하면 a를, 성립하지 않으면 0을 반환한다.
 */

int main() {
    // 입력
    vector<int> arr;    // 테스트 케이스를 저장할 배열
    int input;  // 각 테스트 케이스를 저장할 변수

    // 반복
    while(1) {
        cin >> input;   // 테스트 케이스를 입력 받음
        if (input == 0) {   // 입력의 마지막을 의미하는 0이 입력되면
            break;  // 반복 중지
        }
        arr.push_back(input);   // 입력 받은 테스트 케이스를 arr 배열에 저장
    }

    // 연산
    int max_num = *max_element(arr.begin(), arr.end()); // 테스트 케이스들 중 최댓값을 찾음
    vector<bool> is_prime = getPrimes(max_num); // 소수 여부를 반환할 함수 getPrimes()를 호출

    for (int i = 0; i < arr.size(); i++) {  // 반복
        int a = goldbach(arr[i], is_prime); // 골드바흐의 추측 함수 goldbach() 호출. 추측을 만족하면 a를, 만족하지 않으면 0.

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";    // "n = a + b"의 형태로 출력
        } else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n";    // 골드바흐가 틀렸음을 출력
        }
    }
    return 0;
}