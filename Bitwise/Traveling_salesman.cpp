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
#define FOR(i,ini,N) for(int i=ini;i<N;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define INF 0x3f3f3f3f
const int MAX = 1000;

vector<vector<int>> dist = {{0, 20, 42, 25}, {20, 0, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};

vector<vector<int>> dp( (1<<dist.size()), vector<int>(dist.size(), -1));

int tsp(int setOfCities, int city, int n){
    // Base case
    if(setOfCities == (1<<n) - 1){
        //return the cost from the city original
        return dist[city][0];
    }
    if(dp[setOfCities][city] != -1){
        return dp[setOfCities][city];
    }
    //otherwise try all possible options
    int ans = INF; 
    for(int choice = 0; choice < n; choice++){
        // need t check if city is visited or not
        if((setOfCities & (1<<choice)) == 0){
            int subProb = dist[city][choice] + tsp((setOfCities|(1<<choice)), choice, n);
            ans = min(ans, subProb);
        }
    }
    
    return dp[setOfCities][city] = ans;
}

void solve() {
    cout << tsp(1, 0, 4) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}