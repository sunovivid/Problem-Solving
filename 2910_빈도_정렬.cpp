#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1010

using namespace std;

/* 문제 정의
C, N, 수열 -> 빈도 내림차순 정렬
stable 정렬
 */

/* 해결 알고리즘 생각
arr[i] = i번째 입력된 숫자
<빈도, 숫자> 쌍 내림차순 정렬 
(빈도가 같으면 처음 등장한 숫자 우선(stable정렬))

*/
typedef pair<int, int> pii;

bool compare(pii a, pii b)
{
    return a.first > b.first; //빈도 내림차순 정렬
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, c, k; //c is int?
    cin >> n >> c;
    int input[MAX];
    pii freq[MAX];
    memset(freq, 0, sizeof(freq));
    bool is_exist;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    ///////////////////solution//////////////////
    for (int i = 0; i < n; i++)
    {
        is_exist = false;
        k = input[i];
        for (int j = 0; j < i; j++)
        {
            if (k == input[j]) //이미 등장한 숫자면
            {
                freq[j].first = freq[j].first + 1; //freq 갱신
                assert(freq[j].second != 0);
                is_exist = true;
                break;
            }
        }
        if (!is_exist) //등장하지 않은 숫자면
        {
            freq[i] = {1, k}; //freq에 등록 freq[최초 등장 인덱스] = (빈도, 숫자)
        }
    }
    stable_sort(freq, freq + n, compare); //같은 빈도를 가졌으면 최초 등장 인덱스가 작은 순서 유지
    ////////////////////output///////////////////
    for (int i = 0; i < n; i++)
    {
        if (freq[i].first == 0)
            break;
        for (int j = 0; j < freq[i].first; j++)
        {
            cout << freq[i].second << ' ';
        }
    }
    return 0;
}

/*legacy



*/