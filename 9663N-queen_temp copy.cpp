#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 15

using namespace std;

/* 문제 정의
그 유명한 N-퀸
 */

/* 해결 알고리즘 생각
DFS(backtracking)

DFS는 재귀로 구현
backtracking 제약조건 - 이전 열과 같은 숫자 있으면 안됨
bool exist_queen_in_row[n] 을 기억하면 될듯!

NO. 대각선도 체크해야 함!!
2차원 배열 필요?
bool 정보 -> int 정보로 차원 늘리면 배열 차원은 2차원 -> 1차원 축소 가능
(2차원 bool 배열 (한 행에 한 개 조건)) <=> (1차원 int 배열 (arr[행] = true인 열의 위치))
(2차원 bool 배열 (한 열에 한 개 조건)) <=> (1차원 int 배열 (arr[열] = true인 행의 위치))
(2차원 bool 배열) <=> (1차원 vector<int> 배열 (사실상 2차원 배열이나 공간 절약 가능))
*/

/*
*/

int cnt = 0, n;
bool exist_queen_in_row[MAX];

void dfs(int col)
{
    if (col >= n - 1) //base case
    {
        cnt++;
        cout << endl;
        return;
    }
    for (int row = 0; row < n; row++) //recursive dfs
    {
        if (exist_queen_in_row[row]) //pruning
            continue;
        cout << row;
        exist_queen_in_row[row] = true;
        dfs(col + 1);
        exist_queen_in_row[row] = false;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    fill(exist_queen_in_row, exist_queen_in_row + MAX, false);

    dfs(0);

    cout << cnt;

    return 0;
}

/*legacy



*/