#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1005
#define swap(a,b) ((a)^=(b)^=(a)^=(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

/* 문제 정의
0,1 2차원 배열 -> 1로 된 가장 큰 정사각형 크기
 */

/* 해결 알고리즘 생각
    모든 정사각형 테스트: O(2^(n*m))
    DP[i][j] = (오른쪽 아래가 n,m인 가장 큰 정사각형 크기)
    if (arr[i][j-DP[i-1][j-1] ~ j-1] == 1)
        DP[i][j] = DP[i-1][j-1]

수정0: 중복된 정보를 최대한 활용(제거)하면 여러 번의 if문을 한 번의 min/max, DP로 대체가능
    DP에 '정사각형 넓이의 제곱근 (한 변의 길이)' 저장
    if (arr[i][j] == 1)
        DP[i][j] = min(DP[i-1][j-1], DP[i-1][j], DP[i][j-1]) + 1

55% 틀렸습니다
수정1
    dp 첫 라인에 1이 주어지고 나머지 전부 0인 경우 max_size가 갱신 안 돼서 0으로 유지
    => 입력에 1이 존재하면 max_size 1로 초기화해줌

개선1
    전부 다 입력받지 말고 입력받으면서 dp 갱신, dp 테이블을 2라인만 유지
    라인을 스왑하는 게 아니라 두 라인을 유지하며 0, 1 라인을 번갈아 가며 덮어쓰기 테크닉
*/

/* 시간복잡도
n^3 (n^2번의 DP 갱신에 각 갱신당 2n-1개 arr 원소 확인)

개선1
    O(n*m)
*/

int line[2][MAX] = {0,};
char temp[MAX];

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, prev = 0, cur = 1, max_size = 0;

    cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> temp;
        for (int j=0;j<m;j++) {
            if (temp[j] == '0')
                line[cur][j+1] = 0;
            else {
                line[cur][j+1] = min(min(line[prev][j+1], line[cur][j]), line[prev][j]) + 1; //j+1 칸 채우기 = 모두 0인 첫 arr[-1][] 또는 arr[][-1]을 만드는 효과 (초깃값 예외 필요 없어짐)
                max_size = max(line[cur][j+1], max_size);
            }
        }
        swap(prev,cur);
    }
    ////////////////////output///////////////////
    cout << max_size * max_size;
    return 0;
}