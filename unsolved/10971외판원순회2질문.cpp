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

void dfs(int start, int now, int w_sum)
{
    bool exist_remain = false;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] != 1 && w[now][i] != 0)
        {
            visit[i] = 1;
            dfs(start, i, w_sum + w[now][i]);
            visit[i] = 0;
            exist_remain = true;
        }
    }
    if (!exist_remain)
    {
        if (w[now][start] != 0)
            min_sum = min(w_sum + w[now][start], min_sum);
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
        dfs(i, i, 0);
        visit[i] = 0;
    }
    cout << min_sum;
    return 0;
}

/*legacy



*/