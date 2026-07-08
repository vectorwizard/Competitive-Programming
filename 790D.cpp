#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<int> right(m+n,0);
    vector<int> left(m+n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            right[i+j] += grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            left[i-j+m] += grid[i][j];
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxi = max(maxi,right[i+j] + left[i-j+m] - grid[i][j]);
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
