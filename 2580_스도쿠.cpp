#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define SIZE 9

using namespace std;

/* 문제 정의
스도쿠 -> 스도쿠 풀기
 */

/* 해결 알고리즘 생각
backtraking search
그냥 dfs하면 9^(9*9)
가지치기하면 엄청 줄어들듯
*/

int board[SIZE][SIZE];

bool bs(int index) //y,x에 값 할당하기 return true if found
{
    int y = index / SIZE, x = index % SIZE;
    if (index == SIZE * SIZE)
        return true;

    if (board[y][x] == 0)
    {
        for (int n = 1; n <= 9; n++)
        {
            bool is_valid = true;
            //row check pruning
            for (int i = 0; i < SIZE; i++)
                if (x != i && board[y][i] == n)
                {
                    is_valid = false;
                    break;
                }
            //col check pruning
            for (int i = 0; i < SIZE && is_valid; i++)
                if (y != i && board[i][x] == n)
                {
                    is_valid = false;
                    break;
                }
            //box check pruning
            for (int i = y / 3 * 3; i < y / 3 * 3 + 3 && is_valid; i++)
                for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++)
                    if (!(y == i && x == j) && board[i][j] == n)
                    {
                        is_valid = false;
                        break;
                    }
            if (is_valid)
            {
                board[y][x] = n;
                if (bs(index + 1))
                    return true;
                board[y][x] = 0;
            }
        }
        return false; //failed
    }
    else
    {
        return bs(index + 1);
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];

    ///////////////////solution//////////////////
    assert(bs(0));

    ////////////////////output///////////////////
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

/*legacy



*/