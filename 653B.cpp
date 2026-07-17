#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n;
    cin>>n;
    ll twos = 0;
    ll threes = 0;
    while(n>1 && n%3==0){
        n/=3;
        threes++;
    }
    while(n>1 && n%2==0){
        n/=2;
        twos++;
    }
    if(n!=1){
        cout<<-1<<endl;
        return;
    }
    if(twos>threes){
        cout<<-1<<endl;
        return;
    }
    ll ans = twos;
    ll rem = threes-twos;
    ans+=(rem*2);
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
