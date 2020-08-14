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

bool visited[MAX] = {false,};
pair<int,bool> parent[MAX];

void printPath(int k) {
    // cout << "printPath " << k << endl;
    if (k == -2)
        return;
    printPath(parent[k].first);
    cout << (parent[k].second ? '1' : '0');
}

void solve(int n) {
    memset(visited, false, sizeof(visited));
    //base case
    if (n==1) {
        cout << '1' << '\n';
        return;
    }
    //init
    int k;
    for (int i=0;i<n;i++)
        parent[i].first = -1;
    
    //bfs
    queue<int> q;
    q.push(1);
    parent[1] = {-2,1};
    visited[1] = true;
    while (!q.empty()) {
        //visit
        k = q.front();
        q.pop();

        int children[2] = {(k*10) % n, (k*10 + 1) % n};
        bool found = false;
        for (int i=0;i<2;i++) {
            int child = children[i];
            
            //goal & visit test
            if (visited[child] || found)
                continue;
            if (child == 0) {
                found = true;
                parent[child] = {k,i};
                break;
            }

            //expand
            visited[child] = true;
            q.push(child);
            parent[child] = {k,i};
        }
        if (found)
            break;
    }
    
    // //parent test
    // for (int i=0;i<n;i++) {
    //     if (parent[i].first != -1)
    //         cout << "i: " << i << ", parent: " << parent[i].first << ", bool: " << parent[i].second << endl;
    // }

    //print path
    printPath(0);
    cout << '\n';
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    ///////////////////solution//////////////////
    while(t--) {
        cin >> n;
        solve(n);
    }
    return 0;
}

/*legacy



*/