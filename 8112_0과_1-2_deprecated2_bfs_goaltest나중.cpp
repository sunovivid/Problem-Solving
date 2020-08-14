#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>
#include <queue>

#define MAX 100001

using namespace std;

/* 문제 정의
N -> 조건을 만족하는 수 중 최솟값
조건:
N의 배수
1로 시작
0과 1로 이루어짐
 */

/* 해결 알고리즘 생각
BFS (액션: *10, *10+1)
long long int 안에 담기지 않을 수 있으므로
    => 각 노드의 N으로 나눈 나머지 저장

시간 복잡도: O(V+E) = O(V + 2V) = O(3V) (V = N)

결과 출력
bfs 경로 거꾸로
*/
void solve(int n) {
    cout << "C" << endl;
    //base case
    if (n==1) {
        cout << '1' << '\n';
        return;
    }
    //init
    int k;
    bool visited[MAX] = {false,};
    pair<int,bool> parent[MAX];
    for (int i=0;i<n;i++)
        parent[i].first = -1;
    cout << "X" << endl;
    
    //bfs
    queue<int> q;
    q.push(1);
    parent[1] = {-2,1};
    while (!q.empty()) {
        k = q.front();
        q.pop();
        cout << "visit: " << k << endl;

        if (visited[k])
            continue;
        if (k == 0)
            break;
        visited[k] = true;

        cout << "   k: " << k << endl;
        q.push(k*10 % n);
        cout << "   child1: " << k*10 % n << endl;
        parent[k*10 % n] = {k,0};
        q.push((k*10 + 1) % n);
        cout << "   child2: " << (k*10 + 1) % n << endl;
        parent[(k*10 + 1) % n] = {k,1};
    }
    
    //parent test
    for (int i=0;i<n;i++) {
        if (parent[i].first != -1)
            cout << "i: " << i << ", parent: " << parent[i].first << ", bool: " << parent[i].second << endl;
    }

    //print path
    cout << "found!" << endl; 
    int p = k;
    while (p != -2) {
        cout << "node " << p << endl; 
        cout << (parent[p].second ? '1' : '0');
        cout << endl;
        p = parent[p].first;
    }
    cout << '\n';
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout << "A" << endl;
    int t, n;
    cin >> t;
    ///////////////////solution//////////////////
    while(t--) {
        cin >> n;
        cout << "B" << endl;
        solve(n);
    }
    return 0;
}

/*legacy



*/