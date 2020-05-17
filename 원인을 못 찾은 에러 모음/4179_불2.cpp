#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 10 //MAX를 줄이면 에러가 나지 않는다. 메모리 문제인듯

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r, c;
    char map[MAX][MAX];
    int firemap[MAX][MAX] = {0};
    int visited[MAX][MAX] = {0};
    // memset(visited, 0, sizeof(visited));
    // memset(firemap, 0, sizeof(firemap));
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            map[i][j] = 'C';
        }
    return 0;
}