/*
visited 안쓰는 방법, 안쓰는 숫자(-1)로 초기화한 후 visit 확인 대신 방문할 노드 값이 -1인지 확인
대신 방문하면 반드시 해당 값 수정해야
dfs로 깊이, 자식 수 구할 수 있다.

자식 선택이 무조건 부모보다 이득인 것 확인
-> 리프노드부터 선택하는 것이 이득인 것 확인
-> 리프노드부터 탐색하면서 이득인가 확인할 필요 없이 (리프노드부터 탐색은 구현 복잡)
   각 노드의 이득(depth - childnum) 계산해서
   내림차순 배열해서 k개 선택해 합 구하기 (구하는 것이 합이므로)
전제(가능한 이유):
부모가 선택됐으면 모든 자손 노드가 선택됨. -> -childnum은 타당함.
일부 자손 선택되지 않은 노드의 경우 -> childnum은 실제 선택된 자손들의 수보다 크므로 -childnum은 실제 이득보다 나쁘게 평가됨.
그러나 아래서부터 선택되므로 더 나쁘게 평가해도 됨.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200001
/* 문제 정의
n, k, 간선 n-1개 -> 행복도 합의 최대 (or select k city)
트리구조
k개 공업도시에서 사절단을 보냄.
행복도: 사절단이 1번 도시까지 오면서 지난 관광도시 개수
n <= 2*10^5

 */

/* 해결 알고리즘 생각
브루트 포스 nCk : 겁나큼. 안됨/
그리디: 트리의 리프로부터 해당 노드에서 
사절을 보내는 게 이득인지 손해인지 확인, 이득이면 추가
모든 노드 확인해도 O(n)

리프로부터 확인하는 그리디가 가능한 이유?
자식 노드의 이득은 항상 부모 노드의 이득보다 큼. why?
부모 노드가 공업 도시가 될 때 이득을 볼 수 있으면 
자식 노드는 최소한 그만큼의 이득 + 부모 노드가 관광 도시라면 추가이득을 볼 수 있으므로.
*/

/*
node {
    depth
    자식수
}
    
*/

vector<int> adj[MAX];
vector<pair<int, int>> node; //depth, childnum

int get_node_childnum_bydfs(int cur, int depth)
{
    node[cur].first = depth;
    node[cur].second = 0;
    for (auto child : adj[cur])
    {
        if (node[child].second == -1)
        {
            node[cur].second += get_node_childnum_bydfs(child, depth + 1);
        }
    }
    return node[cur].second + 1;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, a, b, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    node.resize(n, {1, -1});
    get_node_childnum_bydfs(1, 0);
    vector<int> value;
    for (int i = 1; i <= n; i++)
    {
        value.push_back(node[i].first - node[i].second); //모든 노드의 (depth - 자식수) 내림차순 정렬
    }
    sort(value.begin(), value.end());
    for (int i = value.size() - 1; i >= 0 && k; i--)
    {
        sum += value[i];
        k--;
    }
    cout << sum;
    return 0;
}