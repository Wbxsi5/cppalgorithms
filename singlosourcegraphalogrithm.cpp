#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
  ll idx, dist;
};

vector<node> graph[10001];

bool operator>(node a, node b){
  return a.dist > b.dist;
}

int main(){
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  for(ll i = 0; i < m; i++){
    ll si, ti, wi;
    cin >> si >> ti >> wi;
    graph[si].push_back({ti, wi});
    graph[ti].push_back({si, wi});
  }
  vector<ll> dist(n+1, LLONG_MAX);
  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push({s, 0});
  dist[s] = 0;
  while(!pq.empty()){
    node now = pq.top();
    pq.pop();
    if(dist[now.idx] != now.dist) continue;
    if(now.idx == t){
      cout << now.dist << endl;
      return 0;
    }
    for(auto nextn: graph[now.idx]){
            if(dist[nextn.idx] > now.dist + nextn.dist){
                dist[nextn.idx] = now.dist + nextn.dist;
                pq.push({nextn.idx, dist[nextn.idx]});
            }
        }
    }
    cout << dist[t] << endl;
}
