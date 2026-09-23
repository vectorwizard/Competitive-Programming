#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll total = a+b;
    ll per = 2;
    for(ll i=0;i<n;i++){
        if(s[i]=='*'){
            per = 2;
            continue;
        }
        if(per==2){
            if(a>b){
                a--;
                per = 1;
            }
            else if(b>0){
                b--;
                per = 0;
            }
            else{
                per = 2;
            }
        }
        else if(per==1){
            if(b>0){
                b--;
                per = 0;
            }
            else per = 2;
        }
        else{
            if(a>0){
                a--;
                per = 1;
            }
            else per = 2;
        }
    }
    cout<<(total-(a+b))<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
