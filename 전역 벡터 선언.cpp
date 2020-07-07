#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10010

using namespace std;

vector<pair<int, int>> children[MAX]; //children[i]: i의 {자식노드번호, weight}
vector<int> maxLeafCost;
int maxTreePathCost;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, l, r, w;
    cin >> n;
    maxLeafCost = vector<int>(n + 1);
    cout << "size: " << maxLeafCost.size();
    return 0;
}

/*legacy



*/