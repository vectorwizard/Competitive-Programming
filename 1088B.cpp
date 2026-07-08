#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 676767677;
ll func(int s,int k){
    ll ans = 0;
    for(int i=1;i*i<=s;i++){
        if(s%i==0){
            ans++;
            if(s/i != i) ans++;
        }
    }
    return ans%mod;
}
void solve() {
    int x,y;
    cin>>x>>y;
    int s = x-y;
    if(s==0){
        cout<<1<<endl;
    }
    else cout<<func(abs(s),x+y)<<endl;
    if(x>=y){
        for(int i=0;i<x;i++) cout<<1<<" ";
        for(int i=0;i<y;i++) cout<<-1<<" ";
    }
    else{
        for(int i=0;i<y;i++) cout<<-1<<" ";
        for(int i=0;i<x;i++) cout<<1<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}