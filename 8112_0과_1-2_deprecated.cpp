#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>
#include <queue>

#define MAX 1000010

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
    cout << "T" << endl;
    //base case
    if (n==1) {
        cout << '1' << '\n';
        return;
    }
    //init
    int k;
    bool visited[MAX] = {false,};
    pair<int,bool> parent[MAX];
    cout << "X" << endl;
    
    //bfs
    queue<int> q;
    q.push(1);
    parent[1] = {-1,'X'};
    while (!q.empty()) {
        k = q.front();
        q.pop();
        cout << "방문: " << k << endl;

        if (visited[k])
            continue;
        if (k == 0)
            break;
        visited[k] = true;

        cout << "처리시작: " << k << endl;
        q.push(k*10 % n);
        parent[k*10 % n] = {k,0};
        q.push((k*10 + 1) % n);
        parent[(k*10 + 1) % n] = {k,1};
    }
    
    //print path
    int p = k;
    while (p != -1) {
        cout << parent[p].second ? '1' : '0';
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
    cout << "B" << endl;
    while(t--) {
        cin >> n;
        solve(n);
    }
    return 0;
}

/*legacy



*/