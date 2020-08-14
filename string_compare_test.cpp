#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>

#define MAX

using namespace std;

char lr(bool truth)
{
    return truth ? '<' : '>';
}

bool compare1(string a, string b)
{
    cout << "Compare with " << a << " " << b << ": ";
    if (a.length() != b.length())
    {
        cout << lr(a.length() < b.length()) << endl;
        return a.length() < b.length();
    }
    cout << lr(a < b) << endl;
    return a < b;
}

bool compare2(string a, string b)
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
    string a = "im", b = "no";
    compare1(a, b);
    compare2(a, b);
    ///////////////////solution//////////////////

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/