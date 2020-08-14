/* upgrade:
vector initilize with size n: vector<type> vec(n)
vector input: for (auto &elem: vec) {cin >> elem}
vector sort with lamda: [](){}
vector make vecotr unique: unique(vec.begin(), vec.end()) => 중복된 원소 뒤로 보내버려 생긴 쓰레기값의 시작점 리턴
                            erase(unique(vec.begin(), vec.end()) , vec.end());
*/
// 문자열 다룰 때 string 은 유용하다. ( 비교 연산자 > 지원)

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 20001

using namespace std;

/* 문제 정의
단어 N개 -> 정렬 (길이순, 길이가 같으면 사전식)
 */

/* 해결 알고리즘 생각

*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto &word : words)
    {
        cin >> word;
    }

    ///////////////////solution//////////////////

    sort(words.begin(), words.end(), [](string &a, string &b) {
        if (a.length() == b.length())
        {
            return a < b;
        }
        return a.length() < b.length();
    });

    ////////////////////output///////////////////
    words.erase(unique(words.begin(), words.end()), words.end());
    string last = words[0];
    for (auto &word : words)
    {
        cout << word << '\n';
    }
    return 0;
}

/*legacy



*/