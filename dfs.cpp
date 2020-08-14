/*
에러: Segfault: vector<bool> visit 초기화 안함.
해결: vector<bool> visit(MAXV);
교훈: 벡터 사용하려면 초기화하자!
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAXV 1000
/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

stack<int> st;
queue<int> q;
vector<int> adj[MAXV];
vector<bool> visit(MAXV);

void dfs_recursive(int node)
{
    if (visit[node] == true)
        return;
    cout << node << ' ';
    visit[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        dfs_recursive(adj[node][i]);
    }
}

void dfs_stack(int cur)
{
    st.push(cur);
    while (!st.empty())
    {
        cur = st.top();
        st.pop();
        if (visit[cur])
            continue;
        visit[cur] = true;
        cout << cur << ' ';
        for (int i = 0; i < adj[cur].size(); i++)
            st.push(adj[cur][i]);
    }
}

void bfs(int cur)
{
    q.push(cur);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visit[cur])
            continue;
        visit[cur] = true;
        cout << cur << ' ';
        for (int i = 0; i < adj[cur].size(); i++)
        {
            q.push(adj[cur][i]);
        }
    }
}

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, V;
    cin >> N;
    cin >> M;
    cin >> V;
    int from, to;
    for (int t = 0; t < M; t++)
    {
        cin >> from;
        cin >> to;
        adj[from].push_back(to);
        if (from != to)
            adj[to].push_back(from);
    }
    for (int i = 0; i < MAXV; i++)
    {
        sort(adj[i].begin(), adj[i].end(), comp);
    }
    fill(visit.begin(), visit.end(), 0);
    dfs_stack(V);
    for (int i = 0; i < MAXV; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    fill(visit.begin(), visit.end(), 0);
    bfs(V);
    return 0;
}