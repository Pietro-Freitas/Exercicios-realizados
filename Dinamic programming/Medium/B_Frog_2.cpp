#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f

int N, K;
vector<int> h;

const int MAX = 1e5+10;

int memo[MAX];

int dp(int i){
    if(i == 0) return 0;
    if(memo[i] != -1) return memo[i];
    int ret = INF;
    for(int j = max(0, i-K); j < i; j++)
        ret = min(ret, dp(j) + abs(h[j] - h[i]));
    
    return memo[i] = ret;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

   cin >> N >> K;
    h.resize(N);
    for(int& l : h) cin >> l;

    memset(memo, -1, sizeof memo);

    cout << dp(N-1) << endl;

    return 0;
}