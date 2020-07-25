#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
알파벳, @로 이루어진 문자열 -> 처리한 문자열
처리:
    문자열의 앞부터 @를 만날 때마다 앞의 모든 뒤집기
 */

/* 해결 알고리즘 생각
O(nlgn) 까지 허용
스택?
    @만날때마다 뒤집기 -> O(n^2)
double linked list
    @만날 때마다 head 바꿔주기
뒤에서부터 부분 구조 이용?
    부분 구조 어떻게 담지?
*/

/* 시간복잡도
O(n)
*/
typedef struct node {
    char c;
    struct node *next;
    struct node *prev;
} Node;

typedef struct {
    Node *head;
    Node*tail;
} List;

Node *createNode(char c) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->c = c;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void printAdjNode(Node *node, Node *caller, Node* last) {
    cout << node->c;
    //마지막 노드인 경우
    if (node == last)
        return;
    if (node->prev == caller)
        printAdjNode(node->next, node, last);
    else
        printAdjNode(node->prev, node, last);
}

void printList(List *list) {
    printAdjNode(list->head, NULL, list->tail);
    cout << endl;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    char c;
    cin >> n;
    ///////////////////solution//////////////////
    List *list = (List *)malloc(sizeof(List));
    cin >> c;
    Node *initNode = createNode(c);
    list->head = initNode;
    list->tail = initNode;
    // printList(list);
    while (--n) {
        cin >> c;
        // cout << c << " 입력: ";
        if (c == '@') { //뒤집기
            // cout << "뒤집기";
            Node *temp = list->head;
            list->head = list->tail;
            list->tail = temp;
        }
        else { //연결하기
            Node *newNode = createNode(c);
            newNode->prev = list->tail;
            if (list->tail->next == NULL) //빈 곳에 연결
                list->tail->next = newNode;
            else
                list->tail->prev = newNode;
            list->tail = newNode;
            // cout << newNode->c << "연결";
        }
        // cout << endl;
        // printList(list);
    }
    ////////////////////output///////////////////
    printList(list);
    //free
    return 0;
}