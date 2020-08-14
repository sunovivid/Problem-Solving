#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX 10001

using namespace std;

/* 문제 정의
수 정렬하기 (개수는 많고 숫자 범위는 좁을 때)
N <= 10^8, 메모리 제한 8MB = 8*10^6 byte
 */

/* 해결 알고리즘 생각
signed/unsigned int = 4byte, 2*10^6개 int
signed/unsigned short = 2byte, 4*10^6개 short 

비효율적인 0 체크 제거 버전
*/

int main()
{
    ////////////////////count////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, num, count[MAX];
    memset(count, 0, sizeof(count));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        count[num]++;
    }
    ///////////////////solution//////////////////
    //부분합 이용해 count 배열을 last index 배열로

    //input 배열의 뒤쪽부터 last index 배열 1씩 줄여가며 출력

    /*
    원래 방법의 단점: 숫자 범위의 count배열을 모두 확인해서 O(n + size(count))만큼 소요.
    입력이 1, 10000이라 하면 그 사이의 모든 숫자를 체크해서 비효율적
    
    이 방법의 장점:
    stable 특성을 추가한다. (같은 숫자의 경우 순서 유지)
    단점:
    시간복잡도: 상수계수가 약간 늘어난다.  O(n) (input배열 생성) + O(size(count)) (부분합) + O(n) (input배열로부터 부분합 정보 이용해 ouput배열 생성)
    공간복잡도: input배열을 유지해야 하므로 O(n)이 필요하다. (계수정렬이 입력 사이즈가 크다는 것을 생각했을 때 치명적)

    두 방법 모두 추가 개선사항:
    input의 min과 max를 고려해 그 사이 값만 count배열로 만든다. (인덱스-min값)을 인덱스로 사용
    */

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/