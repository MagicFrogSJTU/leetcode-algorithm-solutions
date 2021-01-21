#include <iostream>
#include <climits>
#include <map>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
// @lc code=end
int main(int argc, char **argv)
{
    cout << Solution() << endl;
    return 0;

    auto results = Solution();
    for (auto vec : results){
        for(int i: vec) cout << i << " ";
        cout << endl;
    }
}
