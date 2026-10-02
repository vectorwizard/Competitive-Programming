#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    if(k==2*n || k<n){
        cout<<-1<<endl;
        return;
    }
    int x = k;
    vector<vector<int>> a(n,vector<int>(n,-1));
    int extra = k - n;
    int i = n-1;int j = n-1;
    while(extra--){
        a[i][j] = x;
        a[i][j-1] = x-1;
        i--;j--;
        x-=2;
    }
    while(i>=0){
        a[i][j] = x;
        i--;j--;
        x--;
    }
    int cnt = k+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==-1) {
                a[i][j] = cnt;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}