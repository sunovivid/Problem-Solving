#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 100005

using namespace std;

/* 문제 정의
1~4 자연수 n개 -> 합이 4를 넘지 않도록 최소 그룹핑 
 */

/* 해결 알고리즘 생각
정렬. 4는 무시. 3은 1로 최대한 채우기. 1이 남으면 2에 병합
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, x, y, z, w;
    x = y = z = w = 0;
    cin >> n;
    vector<int> s(n);
    for (auto &elem: s) {
        cin >> elem;
    }
    ///////////////////solution//////////////////
    sort(s.begin(),s.end());
    for (int i=0;i<n;i++) {
        if (s[i] == 1)
            x++;
        else if (s[i] == 2)
            y++;
        else if (s[i] == 3)
            z++;
        else
            w++;
    }
    // cout << x << y << z << w << '\n';

    assert(x+y+z+w==n);
    int result = 0;
    if (x > z)  
    {
        result += z;
        result += (y/2);
        result += (x-z)/4;
        if(y%2 == 1)
            if ((x-z)%4 == 3)
                result += 2;
            else
                result += 1;
        else
            result += ((x-z)%4 > 0);
    }
    else {
        result += z;
        result += (y+1)/2;
    }
        

    ////////////////////output///////////////////
    cout << result + w;
    return 0;
}

/*legacy



*/