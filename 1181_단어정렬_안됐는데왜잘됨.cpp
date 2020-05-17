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
char lr(bool truth)
{
    return truth ? '<' : '>';
}

bool compare(string a, string b)
{
    cout << "Compare with " << a << " " << b << ": ";
    if (a.length() != b.length())
    {
        cout << lr(a.length() < b.length()) << endl;
        return a.length() < b.length();
    }
    if (a.compare(b) == -1)
    {
        cout << lr(true) << endl;
        return true;
    }
    cout << lr(false) << endl;
    return false;
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string words[MAX];
    cin >> n;

    ///////////////////solution//////////////////
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        // cout << words[i].length();
    }

    stable_sort(words, words + n, compare);
    ////////////////////output///////////////////
    string last = words[0];
    cout << words[0] << '\n';
    for (int i = 1; i < n; i++)
    {
        if (words[i].compare(last) == 0)
            continue;
        cout << words[i] << '\n';
        last = words[i];
    }
    return 0;
}

/*legacy



*/