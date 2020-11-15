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
N -> 소인수분해 결과
 */

/* 해결 알고리즘 생각
i = 2 부터 n/2까지 나눠보고 나누어떨이질때마다 출력
*/

/* 시간복잡도
O(n/2)
소수여서 나누어떨어지지 않아 전부 시도해봤을 때도 O(n/2)
나누어떨어지는 경우는 이보다 빠름 T(n) = 1 + T(n/k)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
    ///////////////////solution//////////////////
	for (int i=2; i<=n/2; ) {
		if (n % i == 0) {
			n /= i;
			cout << i << '\n';
			continue;
		}
		i++;
	}
	cout << n;
    ////////////////////output///////////////////
	
    return 0;
}