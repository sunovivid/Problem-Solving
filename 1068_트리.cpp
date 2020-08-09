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
1,2. deprecated 버전 참고

3. parent배열 입력받고 제거할 노드에서 parent = -1로 바꿔 연결 끊기
vector<vector<int>>로 이루어진 자식 배열 만들어서 순회하며 자식 배열 size == 0이면 leaf_cnt++
*/

vector<vector<int>> children;
vector<int> parentArr;
int leaf_num = 0;

void treeTraverse(int root) //해당 노드를 root로 가지는 subtree의 리프 노드 수만큼 leaf_node++
{
    if (children[root].size() == 0) //지울 노드가 리프 노드면 leaf_num++;
    {
        leaf_num++;
        return;
    }
    for (auto child : children[root]) //리프 노드가 아니면 자식들 순회
        treeTraverse(child);
}

int main() {
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, parent, deleteNode, root = -1;
    cin >> n;
    children.resize(n);
    parentArr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent;
        parentArr[i] = parent;
        if (parent == -1)
            root = i;
    }
    //assert(root == 0);
    assert(root != -1);
    cin >> deleteNode;

    ///////////////////solution//////////////////
    if (deleteNode == root) {
        cout << 0; 
        return 0;
    }
    parentArr[deleteNode] = -1;
    for (int i = 0; i < n; i++)
    {
        if (parentArr[i] != -1)
            children[parentArr[i]].push_back(i);
    }

    treeTraverse(root); //root가 0이라는 보장 있나? 없다.

    ////////////////////output///////////////////
    cout << leaf_num;

    return 0;
}

/*legacy



*/