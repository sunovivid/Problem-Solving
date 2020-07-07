#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
길이n 수열, 항 하나가 빠지고 섞인 길이 n-1수열, 항 하나가 더 빠지고..
-> 빠진 항 두개
 */

/* 해결 알고리즘 생각
정렬해서 불일치 찾기
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n-1), c(n-2);
    for (auto &elem: a) {
        cin >> elem;
    }
    for (auto &elem: b) {
        cin >> elem;
    }   
    for (auto &elem: c) {
        cin >> elem;
    }
    ///////////////////solution//////////////////
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    bool isFound = false;
    for (int i=0;i<n-1;i++) {
        if (a[i] != b[i]) {
            cout << a[i] << '\n';
            isFound = true;
            break;
        }
    }
    if (!isFound)
        cout << a[n-1] << '\n';
    
    isFound = false;
    for (int i=0;i<n-2;i++) {
        if (b[i] != c[i]) {
            cout << b[i] << '\n';
            isFound = true;   
            break; 
        }
    }
    if (!isFound)
        cout << b[n-2] << '\n'; 
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/