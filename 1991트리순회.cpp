/*
알고리즘이 동작할지 머릿속으로 돌려보고 제출하기
preorder, inorder, postorder는 '나'를 언제 평가할지 순서에 따라 결정 (왼쪽 -> 오른쪽은 동일)
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 27

using namespace std;

/* 문제 정의
이진 트리 -> 전위 / 중위 / 후위 순회 결과
 */

/* 해결 알고리즘 생각
정의대로 해결
전위 순회: me - left - right
후위 순회: left - right - me
중위 순회: left - me - right
자료구조: 연결 리스트 (자식노드 저장)

전위순회 예시 pre_order(node) {
    if (node.first == -1) //없는 노드 방문할 경우
        return;
    print(node) //me 에대응
    pre_order(left_child)
    pre_order(right_child)
}
*/

pair<char, char> node[MAX];

void pre_order_traversal(int n)
{
    cout << (char)('A' + n);
    if (node[n].first != '.' - 'A')
        pre_order_traversal(node[n].first);
    if (node[n].second != '.' - 'A')
        pre_order_traversal(node[n].second);
}

void in_order_traversal(int n)
{
    if (node[n].first != '.' - 'A')
        in_order_traversal(node[n].first);
    cout << (char)('A' + n);
    if (node[n].second != '.' - 'A')
        in_order_traversal(node[n].second);
}

void post_order_traversal(int n)
{
    if (node[n].first != '.' - 'A')
        post_order_traversal(node[n].first);
    if (node[n].second != '.' - 'A')
        post_order_traversal(node[n].second);
    cout << (char)('A' + n);
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int node_num;
    char parent, left, right;
    cin >> node_num;
    while (node_num--)
    {
        cin >> parent >> left >> right;
        node[parent - 'A'] = {left - 'A', right - 'A'};
    }
    pre_order_traversal(0);
    cout << '\n';
    in_order_traversal(0);
    cout << '\n';
    post_order_traversal(0);
    return 0;
}

/*legacy



*/