#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,d,l;
    cin>>n>>d>>l;
    ll cnt = 1;
    ll dia = d;
    while(d--){
        cout<<cnt<<" "<<cnt+1<<endl;
        cnt++;
    }
    l-=2;
    n-=cnt;
    if(n==0 && l==0) return;
    if(dia==1){
        if(n>0){
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(l>n){
            cout<<-1<<endl;
            return;
        }
        cnt++;
        while(l>1){
            cout<<2<<" "<<cnt<<endl;
            cnt++;
            l--;
            n--;
        }
        while(n>0){
            cout<<2<<" "<<cnt<<endl;
            cnt++;
            n--;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}