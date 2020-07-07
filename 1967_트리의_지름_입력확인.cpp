#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10010

using namespace std;

/* 문제 정의
weighted 트리 -> 트리의 최장 경로 길이
 */

/* 해결 알고리즘 생각
각 노드에서 리프 노드까지 최장 경로 길이, 노드를 경유하는 최장 경로 길이 기록
전역 노드 경유 최장 경로 길이 갱신

def traverseTree(int root)
    global maxTreePathCost
    root->maxLeafPathCost = -INF
    for child in children
        root->maxLeafPathCost = max(root->maxLeafPathCost, child->maxLeafPathCost + child->parentPathCost)
    maxTreePathCost = max(root->maxLeafCost+secondLargest, maxTreePathCost)
*/
int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l, r, w;
    cin >> n;
    while (n--)
    {
        cin >> l >> r >> w;
        children[l].push_back({r, w});
    }
    ///////////////////solution//////////////////
    maxLeafCost.resize(n);
    treeTraverse(1);
    ////////////////////output///////////////////
    cout << maxTreePathCost;
    return 0;
}

/*legacy



*/