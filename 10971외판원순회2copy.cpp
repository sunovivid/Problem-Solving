/*
2차원 배열 초기화
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 11

using namespace std;

/* 문제 정의
그래프 가중치 인접행렬 -> 모든 노드 순회 최소 비용
 */

/* 해결 알고리즘 생각
노드 수가 최대 10개이므로 10! = 3 * 10^6
O(n)이면 완전탐색으로 가능할듯?

인접행렬 입력받기
모든 경로 테스트? dfs로
visit[n] = 0
max_sum = 0
void dfs(now, weight_sum) {
    exist_remain = False
    for (i = 1 to n)
        if (visit[i] != 1)
            if (w[now][i] != 0) //길이 없는 경우
                continue
            visit[i] = 1
            dfs(i, weight_sum + w[now][i])
            visit[i] = 0
            exist_remain = True
    if exist_remain == False
        max_sum = max(weight_sum, max_sum)
        return;
}
*/
int visit[MAX] = {
    0,
};

int w[MAX][MAX], mindist[MAX][MAX];
int n = 0, min_sum = 987654321;

void mindist_dfs(int from, int now, int to, int sum)
{
    for (int i = 0; i < n; i++)
    {
        if (visit[i] != 1 && w[from][i] != 0)
        {
            if (i == to)
            {
                mindist[from][to] = min(sum + w[now][i], mindist[from][to]);
                continue;
            }
            visit[i] = 1;
            mindist_dfs(from, i, to, sum + w[now][i]);
            visit[i] = 0;
        }
    }
}

void dfs(int start, int now, int w_sum, int count)
{
    if (count == n)
    {
        //집으로 돌아갈 땐 방문한 도시 다시 방문해도 됨
        //마지막 위치 (now) 에서 집 (start)으로 가는 최단 경로를 계산해야 되는 것 아닌가?
        //다시 brute-force (단, 이미 방문한 지역을 또 방문하는 것은 무조건 손해이므로 기존과 같이 제외, 집 만나면 바로 탐색 중단)
        //단, 여기서 brute-force 계산하면 O(n!*n!)이므로 미리 계산해두기( O(2n!)) a에서 b로 가는 최단 경로는 항상 일정하므로.
        // min_sum = min(w_sum + mindist[now][start], min_sum);
        if (w[now][start] != 0)
            min_sum = min(w_sum + w[now][start], min_sum);
    }
    // bool exist_remain = false;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] != 1 && w[now][i] != 0)
        {
            visit[i] = 1;
            dfs(start, i, w_sum + w[now][i], count + 1);
            visit[i] = 0;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }

    // fill(&mindist[0][0], &mindist[MAX - 1][MAX], 987654321);
    fill(&visit[0], &visit[MAX], 0);

    // for (int from = 0; from < n; from++)
    // {
    //     for (int to = 0; to < n; to++)
    //     {
    //         visit[from] = 1;
    //         mindist_dfs(from, from, to, 0);
    //         visit[from] = 0;
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mindist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // fill(&visit[0], &visit[MAX], 0);

    for (int i = 0; i < n; i++)
    {
        visit[i] = 1;
        dfs(i, i, 0, 1);
        visit[i] = 0;
    }
    cout << min_sum;
    return 0;
}

/*legacy



*/