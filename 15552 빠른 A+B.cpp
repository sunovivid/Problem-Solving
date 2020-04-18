#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int a, b;
    for (int i = 0; i < T; i++)
    {
        cin >> a;
        cin >> b;
        cout << a + b << '\n';
    }
    return 0;
}