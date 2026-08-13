#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    if(n==a && n==b){
        cout<<"YES"<<endl;
        return;
    }
    int sum = a+b;
    if((n-sum)>=2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}