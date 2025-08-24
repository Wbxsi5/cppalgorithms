#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dist (201, vector<ll> (201, 1e18));
vector<vector<ll>> parent(201, vector<ll> (201, 0));

void fp(ll s, ll e){
  cout << dist[s][e] << endl;
  stack<ll> path;
  while(s != e){
    path.push(e);
    e = parent[s][e];
  }
  path.push(e);
  while(path.size()){
    cout << path.top() << " ";
    path.pop();
  }
  cout << endl;
}

int main(){
  ll s1, e1, s2, e2, n, m;
  cin >> s1 >> e1 >> s2 >> e2 >> n >> m;
  ll start, end ,d;
  for(ll i = 1; i <= m; i++){
    cin >> start >> end >> d;
    if(start != end && d < dist[start][end]){
      dist[start][end] = d;
      dist[end][start] = d;
    }
  }
  for(ll i = 1; i <= n; i++){
    for(ll j = 1; j <= n; j++){
      parent[i][j] = i;
      if(i == j) dist[i][j] = 0;
    }
  }
  for(ll k = 1; k <= n; k++){
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= n; j++){
        if(dist[i][k] != 1e18 && dist[k][j] != 1e18 && i != k && j != k){
          if(dist[i][k] + dist[k][j] < dist[i][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
            parent[i][j] = parent[k][j];
          }
          else if (dist[i][k] + dist[k][j] == dist[i][j] && parent[k][j] < parent[i][j]){
            parent[i][j] = parent[k][j];
          }
        }
      }
    }
  }
  fp(s1,e1);
  fp(s2,e2);
  return 0;
}
