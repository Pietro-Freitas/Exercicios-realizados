#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 10e5;
vector<int> g[MAX];
bool vis[MAX];

void bfs(int s){
    queue<int> q;
    q.push(s), vis[s] = true;

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : g[v]) if(!vis[u]){
            q.push(u), vis[u] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    

    return 0;
}