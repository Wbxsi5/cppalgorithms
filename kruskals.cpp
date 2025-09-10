#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>

ll n, m;
vector<pair<ll, pii>> edges;
vector<ll> parent, depth;

ll find(ll node){
  if(parent[node] == -1) return node;
  return parent[node] = find(parent[node]);
}

void unite(ll a, ll b){
  ll parent_a = find(a);
  ll parent_b = find(b);
  if(parent_a != parent_b){
    if(depth[parent_b] < depth[parent_a]){
      swap(parent_a, parent_b);
    }
    parent[parent_a] = parent_b;
    if(depth[parent_a] == depth[parent_b]){
      depth[parent_b]++;
    }
  }
}

int main(){
  cin >> n >> m;
  ll from,to, weight;
  for(ll i = 0; i < m; i++){
    cin >> from >> to >> weight;
    edges.push_back({weight, {from, to}});
  }
  parent = vector<ll>(n+1, -1);
  depth = vector<ll>(n+1, 1);
  sort(edges.begin(), edges.end());
  ll total = 0, edges_used = 0;
  for(auto edge: edges){
    from = edge.second.first;
    to = edge.second.second;
    if(find(from) != find(to)){
      total += edge.first;
      unite(from, to);
      edges_used++;
    }
  }
  cout << total << endl;
}
