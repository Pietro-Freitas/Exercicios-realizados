/*
    Código elegantemente feito por: Pietro
    Se compilou, envia
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

vector<int>nums = {5, 3, 4, 7};
vector<int> falha  = {-1};
map<int, vector<int>> memo; 


vector<int> dp(int target){
    if(target == 0) return {};
    if(target < 0) return falha;
    if(memo.count(target)) return memo[target];

    for(int i = 0; i < (int) nums.size(); i++){
        vector<int> result = dp(target-nums[i]);
        if(result != falha){
            result.pb(nums[i]);
            return memo[target] = result;
        }
    }

    return memo[target] = falha;
}

void solve() {
    int target = 7;
    memo.clear();
    vector<int> ans = dp(target);
    if(ans == falha) cout << "Não é possivel";
    else for(auto i : ans) cout << i << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}