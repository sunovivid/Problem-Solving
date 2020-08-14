/*배운 점:
1.
move, count는 std에서 사용하는 변수라
전역 변수와 using namespace std를 사용하면 모호성 문제가 생긴다.
다른 변수명 사용!

2.
cin cout사용시 입출력 많으면 느려짐
싱글 스레드 환경에서는 main 안에 
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
사용 (함수라서) scanf, printf등 다른 입출력 함수와 병용 불가. cin cout만 써야함
웬만하면 scanf, printf 사용
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//원판의 개수 -> 수행 과정

//재귀적으로 해결하는 방법?
//원래 구조가 나오도록..

//hanoi(from, to, n) = hanoi(from, to, n-1) + hanoi(from, to, 1)

int move_count = 0;
vector<pair<int, int>> vec_move_from_to;

void hanoi(int from, int to, int n)
{
    if (n == 1)
    {
        move_count++;
        vec_move_from_to.push_back({from, to});
        return;
    }
    int temp = 6 - from - to; //(from, to) (1,2) -> 3, (1,3) -> 2, (2,3) -> 1
    hanoi(from, temp, n - 1);
    hanoi(from, to, 1);
    hanoi(temp, to, n - 1);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    hanoi(1, 3, N);
    cout << move_count << '\n';
    for (auto p : vec_move_from_to)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}