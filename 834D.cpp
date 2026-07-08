#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    ll five = 0;
    ll two = 0;
    ll x = n;
    while(x%5==0 && x>0){
        five++;
        x/=5;
    }
    while(x%2==0 && x>0){
        two++;
        x/=2;
    }
    ll ans = 1;
    while(five>two && (ans*2)<=m){
        five--;
        ans = ans*2;
    }
    while(two>five && (ans*5)<=m){
        two--;
        ans = ans*5;
    }
    while((ans*10)<=m){
        ans = ans*10;
    }
    if(ans==1){
        cout<<(n*m)<<endl;
        return;
    }
    ans = ans*(m/ans);
    cout<<(n*ans)<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
