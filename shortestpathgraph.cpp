#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
  vector<ll> children;
} graph[5001];

int main(){
  ll n, m;
  cin >> n >> m;
  for(ll i = 0; i < m; i++){
    ll a, b;
    cin >> a >> b;
    graph[a].children.push_back(b);
    graph[b].children.push_back(a);
  }
  ll s, t;
  cin >> s >> t;
  if(s == t){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> dist(n + 1, -1);
  queue<ll> q;
  dist[s] = 0;
  q.push(s);
  while(!q.empty()){
    ll curr = q.front();
    q.pop();
    for(ll neighbor : graph[curr].children){
      if(dist[neighbor] == -1){
        dist[neighbor] = dist[curr] + 1;
        q.push(neighbor);
        if(neighbor == t){
          cout << dist[t] << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
