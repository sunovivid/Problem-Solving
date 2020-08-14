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
    인접 노드 따라가면서 visited 큐에 넣기
    방문한 노드가 visited에 있을 경우
        자기 자신일 경우 사이클 형성
        형성된 사이클의 구성 요소는 이제 볼 필요 없음
    아니면 skip
*/

vector<int> arr(100010), visit(100010);
// = vector<int> arr; arr.resize(100010);
int cnt, n;

void dfs(int cur)
{
    visit[cur] = 1;
    int p = arr[cur];
    if (visit[p] == 0)
        dfs(p);
    else
    {
        if (visit[p] != 2)
        {
            cnt++;
            for (int i = p; i != cur; i = arr[i])
            {
                cnt++;
            }
        }
    }
    visit[cur] = 2;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        cnt = 0;
        fill(visit.begin(), visit.end(), 0);
        for (int i = 1; i <= n; i++)
            if (visit[i] == 0)
                dfs(i);
        cout << n - cnt << '\n';
    }
    return 0;
}