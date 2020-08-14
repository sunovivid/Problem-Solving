#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 300005

using namespace std;

/* 문제 정의
트리 -> ㄷ트리 ㅈ트리 개수 비교
 */

/* 해결 알고리즘 생각
DFS하면서 자식의 노드 수 + 깊이 저장
자식 수 = 1이고 깊이가 3이상이면 ㄷ트리 카운트++
자식 수 = 2이고 깊이가 2이상, 1이상이면 ㄷ트리 카운트++
자식 수 = 3이고 깊이가 모두 1이상이면 ㅈ트리 카운트++
*/

/* 시간복잡도
O(n)
*/

int height[MAX], num_grandchild[MAX], d_cnt, g_cnt = 0;
vector<int> tree[MAX];

void dfs(int node)
{
    height[node] = 1;
    num_grandchild[node] = 0;
    int temp_gcnt = 0;
    for (auto child : tree[node])
    {
        dfs(child);
        height[node] = max(height[node], height[child] + 1);
        if (height[child] >= 2)
            num_grandchild[node] += 1;
        if (tree[child].size() > 1)
            temp_gcnt += (tree[child].size() * (tree[child].size() - 1)) / 2;
    }
    if (tree[node].size() >= 3) //루트가 ㅈ트리 중심
    {
        g_cnt += (tree[node].size() - 2);
    }
    if (tree[node].size() >= 2) //루트가 ㄷ트리 중심
    {
        d_cnt += num_grandchild[node] * (tree[node].size() - 1);
    }
    if (tree[node].size() >= 1)
    {
        //루트가 ㅈ트리 가장자리
        g_cnt += temp_gcnt;
        //루트가 ㄷ트리 가장자리
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }
    ///////////////////solution//////////////////
    dfs(1);
    ////////////////////output///////////////////
    cout << "D: " << d_cnt << ", G: " << g_cnt << endl;
    if (d_cnt > g_cnt * 3)
        cout << 'D';
    else if (d_cnt < g_cnt * 3)
        cout << 'G';
    else
        cout << "DUDUDUNGA";
    return 0;
}