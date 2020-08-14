//27%

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
vector<pair<int, int>> children[MAX]; //children[i]: i의 {자식노드번호, weight}
vector<int> maxLeafCost;
int maxTreePathCost;

void treeTraverse(int root)
{
    // cout << "traverse root: " << root << endl;
    //리프 케이스
    if (children[root].size() == 0)
        return;
    else if (children[root].size() == 1)
    {
        pair<int, int> child = children[root].back();
        treeTraverse(child.first);
        maxLeafCost[root] = maxLeafCost[child.first] + child.second;
        maxTreePathCost = max(maxTreePathCost, maxLeafCost[root]);
    }
    else
    {
        int secondLargestLeafCost = -987654321;
        maxLeafCost[root] = -987654321;
        for (auto childInfo : children[root])
        {
            int child = childInfo.first, w = childInfo.second;
            treeTraverse(child);
            int leafCostFromChild = maxLeafCost[child] + w;
            // cout << "Before: leafCostFromChild: " << leafCostFromChild << " maxLeafCost: " << maxLeafCost[root] << " secondLargestLeafCost: " << secondLargestLeafCost << endl;
            if (leafCostFromChild > maxLeafCost[root])
            {
                secondLargestLeafCost = maxLeafCost[root];
                maxLeafCost[root] = leafCostFromChild;
            }
            else if (leafCostFromChild > secondLargestLeafCost)
                secondLargestLeafCost = leafCostFromChild;
            assert(maxLeafCost[root] != -987654321 && secondLargestLeafCost != 987654321);
            // cout << "After: leafCostFromChild: " << leafCostFromChild << " maxLeafCost: " << maxLeafCost[root] << " secondLargestLeafCost: " << secondLargestLeafCost << endl;
        }
        maxTreePathCost = max(maxTreePathCost, maxLeafCost[root] + secondLargestLeafCost);
    }

    // cout << "root " << root << " result: " << maxTreePathCost << endl;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l, r, w;
    cin >> n;
    n -= 1;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r >> w;
        children[l].push_back({r, w});
    }
    ///////////////////solution//////////////////
    maxLeafCost = vector<int>(n + 1);
    // cout << "size: " << maxLeafCost.size();
    maxLeafCost.resize(n + 1);
    treeTraverse(1);
    ////////////////////output///////////////////
    cout << maxTreePathCost;
    return 0;
}

/*legacy



*/