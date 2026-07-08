#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> A(2,0);
    vector<int> B(2,0);
    cin>>A[0]>>A[1]>>B[0]>>B[1];
    vector<vector<int>> houses(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>houses[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>houses[i][1];
    }
    
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}