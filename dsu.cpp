// Include all standard C++ libraries
#include <bits/stdc++.h>
// Use standard namespace to avoid std:: prefix
using namespace std;
// Define long long as ll for shorter typing
typedef long long ll;

// Define a Disjoint Set Union (DSU) data structure
struct DSU {
    // Vector to store parent/size information for each element
    vector<ll> e;
    
    // Constructor: Initialize DSU with size N+1, all elements as -1 (each in own set)
    DSU(ll N) { e = vector<ll>(N+1,-1); }
    
    // Find root of set containing x (with path compression)
    ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    
    // Check if x and y are in same set
    bool same_set(ll x, ll y) {
        x = get(x), y = get(y);
        return x == y;
    }
    
    // Get size of set containing x
    ll size(ll x) { return -e[get(x)]; }
    
    // Unite sets containing x and y
    // Returns false if already in same set, true if union performed
    bool unite(ll x, ll y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        // Ensure x is the larger set (more negative e[x])
        if(e[x] > e[y]) swap(x,y);
        // Combine sets and make y point to x
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main() {
    // Declare variables for number of elements (n), operations (m), 
    // and operation inputs (x,y,z)
    ll n,m,x,y,z;
    
    // Read number of elements and operations
    cin >> n >> m;
    
    // Create DSU object with n elements
    DSU mySet(n);
    
    // Process m operations
    for(ll i = 0; i < m; i++) {
        // Read operation type (z) and two elements (x,y)
        cin >> z >> x >> y;
        
        // If z=1, unite sets; if z=2, check if in same set
        if(z==1) mySet.unite(x,y);
        else mySet.same_set(x,y) ? cout << "Y\n" : cout << "N\n";
    }
}
