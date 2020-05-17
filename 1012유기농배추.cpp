#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 2510
#define MAXSIZE 55

using namespace std;

/* 문제 정의
이차원 좌표 k개-> 그룹의 개수
 */

/* 해결 알고리즘 생각
grouping 문제
인접 리스트 만들고
앞에서부터 노드 하나씩 dfs로 탐색
    if visit = 0
        count++
    탐색한 노드 visit = 1
return count
*/

int arr[MAXSIZE][MAXSIZE];
int ans_count = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    int _x, _y;
    if (arr[x][y] == 1)
    {
        arr[x][y] = -1;
        for (int i = 0; i < 4; i++)
        {
            _x = x + dx[i];
            _y = y + dy[i];
            dfs(_x, _y);
        }
    }
}

int main()
{
    // cout << "0";
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testcase_num, m, n, k, x, y;
    cin >> testcase_num;
    while (testcase_num--)
    {
        // cout << "1";
        ans_count = 0;g
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            // cout << "2";
            cin >> x >> y;
            arr[x + 1][y + 1] = 1; //1base 좌표계
        }
        for (int y = 1; y <= n; y++)
        {
            // cout << "3";
            for (int x = 1; x <= m; x++)
            {
                // cout << "4";
                // cout << 'x';
                if (arr[x][y] == 1)
                {
                    dfs(x, y);
                    // cout << "dfs\n";
                    ans_count++;
                }
            }
        }
        cout << ans_count << '\n';
    }

    return 0;
}