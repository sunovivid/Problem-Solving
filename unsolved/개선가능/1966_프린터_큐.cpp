//큐를 잘 사용하면 더 아름답게/ 풀 수 있을 것 같은데?

/**
 * 구현 패턴: 원하는 곳 찾고 거기서부터 특정 동작 (ex: 한 바퀴 더) 하는 패턴
 * 일단 먼저 for문으로 찾고, 찾은 이후부터 다시 for문으로 동작 수행 후 break로 바깥 for문 빠져나가기
 * for ()
 *     찾기
 *     if 발견
 *         for ()
 *     break
 * 2중 for문처럼 보이지만 실제로는 O(n)
 **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
길이 100이하 <중요도> 자연수 수열 -> 각 문서의 출력되는 순서
 */

/* 해결 알고리즘 생각
최악의 경우
100 개 문서, 중요도 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3...8 9

(우선순위, 최초 인덱스) pair 만들어서 우선순위로 정렬
높은 우선순위부터 출력 (출력 카운트++)
    같은 우선순위일 경우 '현재 출력 인덱스' 뒤부터 순서대로 출력
    (인덱스가 순환하는 큐 형태)
*/

/* 시간복잡도
O(nlgn(정렬) + 9(중요도 레벨수)*n)
*/

typedef pair<int, int> pii;

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        [] {
            //input
            int n, m;
            cin >> n >> m;
            vector<int> docs[10];
            int max_level = 0;
            for (int i = 0; i < n; i++)
            {
                int level;
                cin >> level;
                max_level = max(max_level, level);
                docs[level].push_back(i);
            }
            //solve
            int cnt = 1;
            int cur_doc_idx = docs[max_level].front();
            for (int level = max_level; level >= 1; level--)
            {
                // cout << "check level " << level << endl;
                int size = docs[level].size(); //같은 레벨 문서 수
                bool isFirstFound = false;
                int i;

                //마지막으로 출력한 문서 다음으로 최초로 출력할 문서 찾기
                for (i = 0; i < size; i++)
                    if (docs[level][i] >= cur_doc_idx) //현재 레벨에서 현재 인덱스보다 큰 인덱스 최초 발견
                    {
                        isFirstFound = true;
                        break;
                    }
                if (!isFirstFound) //없을 경우 맨 앞으로 돌아와 처음 인덱스로
                    i = 0;

                //찾은 곳부터 한 주기 돌기
                for (int j = i, repeat = 0; repeat < size; j = (j + 1) % size, repeat++)
                {
                    cur_doc_idx = docs[level][j];
                    // cout << "\tfound doc to print at " << docs[level][j] << endl;
                    if (docs[level][j] == m) //찾는 문서 발견하면 cnt 출력
                    {
                        cout << cnt << '\n';
                        return;
                    }
                    cnt++;
                }
            }
        }();
    }
    ////////////////////output///////////////////

    return 0;
}