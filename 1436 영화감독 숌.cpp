#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

/* 문제 정의
N -> N 번째 종말의 수, N <= 10000
 */

/* 해결 알고리즘 생각
666 1666 2666 3666 4666 5666 6660 6661 6662 ... 7666 ...
N <= 10000
N이 10000이라 해도 10000*666 이내에서 모두 발견 (***666은 모두 종말의 수이므로)

방법 1.
1부터 INF까지 i를 증가시키며 종말의 수인지 확인, 맞으면 count++
10^8 안에 가능한가?
    666, (666_, _666), (__666, _666_, 666__), ...
    중복허용 1가지, 2*10가지, 3*100가지, 4*1000가지, 5*10000가지.
    ****666, 7자리 수 안에 가능. 각 수 테스트에 O(자리수) 걸리면 가능할듯.

방법 2.
*666* 형태 숫자 생성
순서를 지정할 수 있는가?
    yes -> 그대로 배열로 저장
        how?
        
    no -> 만들어야 하는 범위 지정해서 만들고 sort
        666, (666_, _666), (__666, _666_, 666__), ...
        중복허용 1가지, 2*10가지, 3*100가지, 4*1000가지, 5*10000가지.
n번째 구하기
*/

bool has_666(int n)
{
    int continuance = 0;
    int digit = 0;
    while (n > 0)
    {
        digit = n % 10;
        if (digit == 6)
        {
            continuance++;
            if (continuance >= 3)
                return true;
        }
        else
        {
            continuance = 0;
        }
        n /= 10;
    }
    return false;
}

int main()
{
    int count_666 = 0;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int i;
    for (i = 666;; i++)
    {
        if (has_666(i))
            count_666++;
        if (count_666 == N)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}