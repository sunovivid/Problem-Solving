/*
Cycle: 출발 노드에서 시작해서 재귀적으로 탐색
이미 방문한 노드 발견하면 사이클이 있었던 것이므로
거기서부터 다시 사이클 돌기 (이 동작이 방문 경로를 유지하는 코스트를 대신한다)
마지막에 visited를 2로 바꿔주면서 종료하여 더 이상 방문할 필요 없다고 표시.

내가 짠 코드는 사이클로 연결되지만 사이클을 구성하지는 않는 노드들을 모두 탐색해야 하므로 비효율적 (최대 n^2) -> 통과 못할듯
스터디장님의 코드는 최대 노드 개수 * 2번만 방문하면 됨. (모두 연결되어 있는 경우)

코스트가 좀 더 들더라도 방문 한번 하면 다 찾아버리고 연결된 노드들은 방문 안하게 하는게 뽀인트.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001
/* 문제 정의
인접 리스트 (한 노드가 단일 노드 지목, 유향 그래프) -> cycle
 */

/* 해결 알고리즘 생각
1번 노드부터 N번 노드까지
    visited 초기화
    인접 노드 따라가면서 visited 표시하기
    방문한 노드가 visited에 있을 경우
        자기 자신일 경우 사이클 형성
        형성된 사이클의 구성 요소는 이제 볼 필요 없음
    아니면 skip
*/

/*
의사코드
is_worth_check 배열 초기화
for i = 1 to n
    if is_worth_check:
        visited 초기화
        path 큐 초기화
        count = 0
        node = i
        while (true)
            node = adj[node]
            if visited[node] == 0:
                visited[node] = 1
                path 큐에 넣기
            else:
                if node == i:
                    count += size(path)
                    큐의 원소들에 대해 is_worth_check[원소] = False
                else
                    break
return n - count;
구현은 안할거야~
*/
int get_uncycled_num(vector<int> adj, int n)
{
    vector<int> visit(MAX);
    for (int i = 1; i <= n; i++)
    {
        fill(visit.begin(), visit.end(), 0);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> adj;
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> adj[i];
            get_uncycled_num(adj, n);
        }
    }

    return 0;
}