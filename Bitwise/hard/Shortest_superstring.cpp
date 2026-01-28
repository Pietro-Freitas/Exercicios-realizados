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
#define eb emplace_back
#define ii pair<int, int>
#define FOR(i, ini, N) for (int i = ini; i < N; i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define INF 0x3f3f3f3f
const int MAX = 12;

vector<vector<string>> dp((1 << MAX), vector<string>(MAX, "#"));

string tsp(vector<string> words, int mask, int word, int n)
{
    if (mask == (1 << n) - 1)
        return "";
    if (dp[mask][word] != "#")
        return dp[mask][word];

    string ans = "";
    FOR(choice, 0, n)
    {
        if ((mask & (1 << choice)) == 0){
            int maxOverlap = 0;
            for (int i = 1; i <= min(words[word].size(), words[choice].size()); i++) if (words[word].substr(words[word].size() - i) == words[choice].substr(0, i))maxOverlap = i;
            
            string subproblem = words[choice].substr(maxOverlap) + tsp(words, mask | (1 << choice), choice, n);
            if (ans.empty() || subproblem.size() < ans.size())
            {
                ans = subproblem;
            }
        }
    }
    return dp[mask][word] = ans;
}

string shortestSuperstring(vector<string> words)
{
    string ans = "";
    for (int i = 0; i < sz(words); i++){
        for(int j = 0; j < (1 << sz(words)); j++) for(int k = 0; k < sz(words); k++) dp[j][k] = "#";
        string candidate = words[i] + tsp(words, 1 << i, i, sz(words));
        if (ans.empty() || candidate.size() < ans.size()){
            ans = candidate;
        }
    }
    return ans;
}

void solve()
{
    int t;
    cin >> t;
    vector<string> words(t);
    for (auto &i : words)
        cin >> i;

    cout << shortestSuperstring(words) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}