//55분. 트라이 구현에 오래걸림
//자료구조 SET 사용하면 바로 풀 수 있음 (중복 입력 무시해서 set 개수 구하면 됨)
// STL 자료구조들을 더 익혀둬야겠다고 생각

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 13

using namespace std;

/* 문제 정의
(월, 일, 이름) 배열 -> 각 월에 이름의 수
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/

typedef struct node {
    bool is_EOS;
    struct node *next[25];
} Node;

typedef struct {
    int num;
    Node *head;
} Trie;

Node *create_node() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->is_EOS = false;
    for (int i=0;i<25;i++) //초기화
        node->next[i] = NULL;
    return node;
}

bool trie_insert(Trie *trie, string s) {
    if (trie->head == NULL)
        trie->head = create_node();
    Node *cur = trie->head;
    for (int i=0;i<s.length();i++) {
        if (cur->next[s[i]-'A'] == NULL) //-'A'
            cur->next[s[i]-'A'] = create_node();
        cur = cur->next[s[i]-'A'];
    }
    if (!(cur->is_EOS)) {
        trie->num += 1;
        cur->is_EOS = true;
        return true;
    }
    return false;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    Trie *birth_trie[13];
    ///////////////////solution//////////////////
    //init trie array
    for (int i=1;i<=12;i++) {
        birth_trie[i] = (Trie *)malloc(sizeof(Trie));
        birth_trie[i]->head = NULL;
        birth_trie[i]->num = 0;
    }
    for (int i=0;i<n;i++) {
        int mm, dd;
        string name;
        cin >> mm >> dd >> name; //cin 05?
        bool is_exist = false;
        trie_insert(birth_trie[mm], name);
    }
    ////////////////////output///////////////////
    for (int m=1;m<=12;m++) {
        cout << birth_trie[m]->num << '\n';
        //trie_free(birth_trie[m]);
    }
    return 0;
}