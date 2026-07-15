#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll a,b,c;
    cin>>a>>b>>c;
    ll diff1 = b-a;
    ll diff2 = c-b;
    if(diff1==diff2){
        cout<<"YES"<<endl;
        return;
    }
    ll x = c+a;
    ll y = 2*b-c;
    ll z = 2*b-a;
    if(x%(2*b)==0 && x/(2*b)>0){
        cout<<"YES"<<endl;
    }
    else if(y%a==0 && y/a>0){
        cout<<"YES"<<endl;
    }
    else if(z%c==0 && z/c>0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
