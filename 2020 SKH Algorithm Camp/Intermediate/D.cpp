/*통일된 하나의 표현방식 찾으려다 쓸데없이 오래 걸림
    :end_of_vacation[MAX]을 휴가 마지막날로 할지 마지막 다음날로 할지 고민
    => 그냥 is_vacation 여부 따지면 됐음
아름다움을 추구하지 말고 안되면 그냥 케이스 나누자 -> 그게 더 아름다울 수도 있음

실수
-1 +1 헷갈림
최댓값 max로 갱신 안해줌
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1000005

using namespace std;

/* 문제 정의
휴가일수 k, (연휴의 시작 날짜, 끝 날짜) n개 -> 최대 휴가 길이
 */

/* 해결 알고리즘 생각
모든 연휴의 시작과 끝 케이스에서 휴가 일수 세기
시작 케이스
    max = 0
    for i = 0 to k
        for j = e[i] + 1
=> 시간초과

처음 가능한 케이스 큐에 모두 넣고, 날짜 하나씩 증가시켜가며 큐에 하나 넣고 하나 빼기 (큐 사이즈 = 휴가일수 큐 사이즈 일정하게)
큐의 back - front 의 최댓값 갱신하기
*/

/* 시간복잡도
O(n)
*/

bool is_vacation[MAX] = {false, };
int end_of_vacation[MAX] = {0, };
int start_of_vacation[MAX] = {0, };

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, last_vac_day = 1;
    cin >> n >> k;

    for (int i=1;i<=n;i++) {
        int s, e;
        cin >> s >> e;
        for (int j=s;j<=e;j++) {
            is_vacation[j] = true;
            start_of_vacation[j] = s;
            end_of_vacation[j] = e;
        }
        last_vac_day = max(e, last_vac_day);
    }
    // cout << last_vac_day << endl;
    ///////////////////solution//////////////////
    queue<int> q;
    for (int day=1; q.size()<k; day++) {
        if (!is_vacation[day]) {
            q.push(day);
        }
    }
    int max_vacation = 0;
    for (;q.back()<=last_vac_day+k+1;) {
        //maxvac 갱신
        max_vacation = max((is_vacation[q.back()+1] ? end_of_vacation[q.back()+1] : q.back())
                    - (is_vacation[q.front()-1] ? start_of_vacation[q.front()-1] : q.front())
                    + 1
                    , max_vacation); //eos: 연휴일 경우: 연휴 첫날
        // cout << "vac start: " << (is_vacation[q.front()-1] ? start_of_vacation[q.front()-1] : q.front()) << ' ';
        // cout << "vac end: " << (is_vacation[q.back()+1] ? end_of_vacation[q.back()+1] : q.back()) << ' ';
        // cout << "max vacation: " << max_vacation << ' ';
        //다음 상태로
        q.pop();
        q.push(is_vacation[q.back()+1] ? end_of_vacation[q.back()+1] + 1 : q.back()+1); //eov: 연휴가 아닐 경우: 해당 날짜 그대로, 연휴일 경우: 연휴 마지막 날
    
        // cout << "pop front, push " << q.back() << endl;
    }
    
    cout << max_vacation;
    ////////////////////output///////////////////

    return 0;
}