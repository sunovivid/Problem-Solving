#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각
생각
    모든 시작점에서 동시에 BFS 시작
    문 노드의 잠긴 문 수 = 자식 문 수의 합 + 1
    BFS 퇴각도 가능한가?
    탐색 종료: remain == 0

강의
    .들을 한 노드로, #은 엣지로 생각
    #만날때마다 door + 1 해서 UCS (priority queue)
    step 1 : 각각 탈출하는 경우
        모든 자식들 BFS해서 goal까지 수 더해줌
    step 2 : 공통 경로 존재하는 경우 체크
        바깥 (.으로 둘러싸서 구현)에서 UCS해서 모든 노드까지의 열어야 하는 문 수 구하기
        자식들 BFS해서 만나면 자식들이 연 문 수 합 + 방금 구한 바깥까지의 문 수 (문#에서 만나면 +1)
            의문: Bidirectional search는 optimal하지 않은가? 그냥 최초로 만나면 거기서부터 하면 안되나?
            => optimal하나 (BFS, uniform path cost) 그러더라도 더 짧은 경로 존재할 수 있음 
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/