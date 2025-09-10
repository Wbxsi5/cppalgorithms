#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<bool> vis(n + 1, false);
    vector<ll> key(n + 1, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    key[1] = 0;
    pq.push({0, 1});
    ll ans = 0;
    while(!pq.empty()){
        ll weight = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans += weight;
        for(auto& edge : adj[u]){
            ll v = edge.first;
            ll w = edge.second;
            if(!vis[v] && w < key[v]){
                key[v] = w;
                pq.push({w, v});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
