#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        cout<<"First"<<endl;
    }
    else if(b>a){
        cout<<"Second"<<endl;
    }
    else{
        if(c%2==0){
            cout<<"Second"<<endl;
        }
        else cout<<"First"<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
