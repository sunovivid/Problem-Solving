//3 6 9 12로 맞추는 나머지계산
//선택이 행동의 누적이면 행동을 복구시킬 필요가 없다
//
// +tip
//행동이 복잡하면 함수로 빼자
//char2차원 배열은 문자열 상수의 배열로 나타낼 수 있다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define CLOCKNUM 16
#define SWITCHNUM 10
#define INF 9876543
using namespace std;

/* 문제 정의
길이 16 (3,6,9,12) 수열 -> 모두 12로 맞추기 위해 필요한 스위치 최소 횟수
 */

/* 해결 알고리즘 생각
순서 상관없음 => 누른 횟수만 따지면 됨
4번 누르면 안 누른 것과 같음
각 스위치 0,1,2,3번 누른 경우 완전탐색
*/

/* 시간복잡도
4^10 = 2^20 = 1000^2 = 10^6 완탐 ok
*/
const char isSwitchLinkedToClock[SWITCHNUM][CLOCKNUM + 1] = { //'\0'때문에 한 칸 더 추가
    //0123456789012345
    "CCC.............",
    "...C...C.C.C....",
    "....C.....C...CC",
    "C...CCCC........",
    "......CCC.C.C...",
    "C.C...........CC",
    "...C..........CC",
    "....CC.C......CC",
    ".CCCCC..........",
    "...CCC...C...C.."};

inline void push(int clock[], int switchIndex)
{
    for (int i = 0; i < CLOCKNUM; i++)
        if (isSwitchLinkedToClock[switchIndex][i] == 'C')
        {
            clock[i] = (clock[i] % 12) + 3;
        }
}

int pushIthSwitch(int clock[], int switchIndex, int count)
{
    if (switchIndex == 10)
    {
        bool isAll12 = true;
        for (int i = 0; i < CLOCKNUM; i++)
            if (clock[i] != 12)
            {
                isAll12 = false;
                break;
            }
        if (isAll12)
            return count;
        return INF;
    }

    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++)
    {
        ret = min(ret, pushIthSwitch(clock, switchIndex + 1, count + cnt));
        push(clock, switchIndex);
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        int clock[CLOCKNUM];
        for (int i = 0; i < CLOCKNUM; i++)
            cin >> clock[i];
        int result = pushIthSwitch(clock, 0, 0);
        cout << (result == INF ? -1 : result) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}