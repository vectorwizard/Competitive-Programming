#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool func(string x,string s){
    int n = x.size();
    int m = s.size();
    if(n<m) return false;
    for(int i=0;i<=n-m;i++){
        string st = x.substr(i,m);
        if(st==s) return true;
    }
    return false;
}
void solve() {
    int n,m;
    cin>>n; cin>>m;
    string x,s;
    cin>>x; cin>>s;
    string st = x;
    if(func(st,s)) {
        cout<<0<<endl;
        return;
    }
    st = st+st;
    if(func(st,s)) {
        cout<<1<<endl;
        return;
    }
    st = st+st;
    if(func(st,s)) {
        cout<<2<<endl;
        return;
    }
    st = st+st;
    if(func(st,s)) {
        cout<<3<<endl;
        return;
    }
    st = st+st;
    if(func(st,s)) {
        cout<<4<<endl;
        return;
    }
    st = st+st;
    if(func(st,s)) {
        cout<<5<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
