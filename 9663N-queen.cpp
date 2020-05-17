/*
반복(dfs)의 종료 조건을 잘못 설정함 (n-1이 아니라 n)

DFS: 각 반복 단위를 명확히 설정해라. 
(상태 방문: goal test -> {자식 생성 -> 방문})할 것인지,
(상태 방문: {자식 생성 -> goal test -> 방문})할 것인지

dfs는 goal_test를 상태 처음 방문했을 때 하고 자식을 생성하는 게 낫다
*/

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

long long cnt;
int queen_pos_in_col[MAX], n;

void dfs(int col_to_check)
{
    if (col_to_check >= n) //goal test (base case)
    {
        cnt++;
        // cout << endl;
        return;
    }
    for (int row = 0; row < n; row++) //recursive dfs
    {
        bool pruning = false;
        for (int col = 0; col < col_to_check; col++) //pruning
        {
            if (queen_pos_in_col[col] == row)
            { //같은 행
                pruning = true;
                break;
            }
            if (row - queen_pos_in_col[col] == col_to_check - col)
            { // 대각선1 체크
                pruning = true;
                break;
            }
            if (row - queen_pos_in_col[col] == -(col_to_check - col))
            { // 대각선2 체크
                pruning = true;
                break;
            }
        }
        if (pruning)
            continue;
        queen_pos_in_col[col_to_check] = row;
        dfs(col_to_check + 1);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    fill(queen_pos_in_col, queen_pos_in_col + MAX, -1);

    dfs(0);

    cout << cnt;

    return 0;
}

/*legacy



*/