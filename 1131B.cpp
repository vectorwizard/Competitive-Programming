#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    int n = x+y+z;
    string ans = "";
    if(x==max({x,y,z})){
        for(int i=0;i<n;i++){
            ans+='P';
        }
    }
    else if(y==max({x,y,z})){
        for(int i=0;i<n;i++){
            ans+='R';
        }
    }
    else{
        for(int i=0;i<n;i++){
            ans+='S';
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}