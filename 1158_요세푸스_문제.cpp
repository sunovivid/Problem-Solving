#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 16000

using namespace std;

/* 문제 정의
N, K -> 요세푸스 순열
 */

/* 해결 알고리즘 생각
def 원순열 생성(n)
    노드 생성
    for i = 1 to n-1
        노드 생성
        이전 노드와 링크 연결
    처음 생성 노드와 마지막 노드 링크 연결

원순열 생성
while 모든 노드가 제거될 때까지
    현재 위치로부터 k % n 번째 노드 제거
*/
typedef struct node
{
    int order;
    node *prev;
    node *next;
} NODE;

pair<int, NODE *> kill(NODE *curNode, int k)
{
    while (k--)
        curNode = curNode->next;
    curNode->prev->next = curNode->next;
    curNode->next->prev = curNode->prev;
    int order = curNode->order;
    free(curNode);
    return {order, curNode->prev};
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    vector<int> permu;
    cin >> n >> k;
    ///////////////////solution//////////////////
    //원순열 생성
    NODE *firstNode = (NODE *)malloc(sizeof(NODE));
    NODE *preNode = firstNode;
    NODE *lastNode = NULL;
    preNode->order = 1;
    for (int i = 2; i <= n; i++)
    {
        NODE *curNode = (NODE *)malloc(sizeof(NODE));
        curNode->order = i;
        curNode->prev = preNode;
        preNode->next = curNode;
        preNode = curNode;
    }
    lastNode = preNode;
    lastNode->next = firstNode;
    firstNode->prev = lastNode;

    //kill
    pair<int, NODE *> result = {-1, lastNode};
    for (int i = 1; i <= n; i++)
    {
        result = kill(result.second, k);
        permu.push_back(result.first);
    }
    ////////////////////output///////////////////
    string output = "<";
    for (auto x : permu)
    {
        output += to_string(x) + ", ";
    }
    output = output.substr(0, output.length() - 2);
    output += ">";
    cout << output;
    return 0;
}

/*legacy



*/