#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 55

using namespace std;

/* 문제 정의
트리 (각 노드의 부모 배열), 지울 노드 번호 -> 리프의 개수
 */

/* 해결 알고리즘 생각
1. 트리 구조 만들면서 리프 노드 카운트 O(n)
- preorder 로 노드 제거해서 제거된 리프 노드 카운트 O(k = 제거할 노드의 자손 수 + 1)
k < n 이므로 O(n)

2. 부모 배열에서 바로 푸는 법?
재귀적으로 부모가 i인 노드 삭제
def delete(i)
    for parent in arr
        if parent == i
            parent = -2
            delete(parent)
O(n^2)
def countleaf()
    for parent in arr
        if parent not in arr (exclude parent itself)
            count++
O(n^2) 비트마스크로 O(n)?
*/

// typedef struct
// {
//     vector<NODE *> children;
// } NODE;

// vector<NODE *> nodes;

vector<vector<int>> children;
vector<int> parentVec;
int leaf_num = 0;

void deleteNode(int root) //해당 노드를 root로 가지는 subtree의 리프 노드 수만큼 leaf_node--
{
    if (children[root].size() == 0) //지울 노드가 리프 노드면 leaf_num--;
    {
        leaf_num--;
        return;
    }
    for (auto child : children[root]) //리프 노드가 아니면 자식들 삭제
        deleteNode(child);
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, parent, root = -1, toDelete;
    cin >> n;
    children.resize(n);
    parentVec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent;
        parentVec.push_back(parent); //TODO:ERROR!
        if (parent != -1)
            children[parent].push_back(i);
        else
            root = i;
    }

    for (auto p : parentVec)
        cout << p << ", ";
    ///////////////////solution//////////////////
    // for (auto childrenVector : children)
    // {
    //     for (auto child : childrenVector)
    //         cout << child << ' ';
    //     cout << endl;
    // }
    if (toDelete == root) //root를 지우는 경우
    {
        cout << 0;
        return 0;
    }

    for (auto childrenVector : children)
    {
        if (childrenVector.size() == 0)
            leaf_num++;
    }
    deleteNode(toDelete);
    if (children[parentVec[toDelete]].size() == 1)
        leaf_num++;

    // ////////////////////output///////////////////
    // cout << leaf_num;

    return 0;
}

/*legacy



*/