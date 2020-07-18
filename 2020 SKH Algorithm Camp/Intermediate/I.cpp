#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 13

using namespace std;

/* 문제 정의
(월, 일, 이름) 배열 -> 각 월에 이름의 수
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> birth_month[MAX];
    ///////////////////solution//////////////////
    for (int i=0;i<n;i++) {
        int mm, dd;
        string name;
        cin >> mm >> dd >> name; //cin 05?
        bool is_exist = false;
        for (auto na: birth_month[mm]) {
            if (na.compare(name) == 0) {
                is_exist = true;
                break;
            }
        }
        if (!is_exist) {
            birth_month[mm].push_back(name);
        }
    }
    ////////////////////output///////////////////
    for (int m=1;m<=12;m++) {
        cout << birth_month[m].size() << '\n';
    }
    return 0;
}