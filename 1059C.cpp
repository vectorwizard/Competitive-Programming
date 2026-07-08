#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b;
    cin>>a>>b;
    int x = __builtin_clz(a);
    int y = __builtin_clz(b);
    if(a==b){
        cout<<0<<endl;
        return;
    }
    if(x>y){
        cout<<-1<<endl;
        return;
    }
    int n1=0;
    int n2 = 0;
    for(int i=31-x;i>=0;i--){
        if((a&(1<<i))==0 && (a&(1<<i))!=(b&(1<<i))){
            n1 = n1|(1<<i);
            a = a|(1<<i);
        }
    }
    if(a==b){
        cout<<1<<endl;
        cout<<n1<<endl;
        return;
    }
    x = __builtin_clz(a);
    for(int i=31-x;i>=0;i--){
        if((a&(1<<i))!=0 && (a&(1<<i))!=(b&(1<<i))){
            n2 = n2|(1<<i);
            a = a& ~(1<<i);
        }
    }
    cout<<2<<endl;
    cout<<n1<<" "<<n2<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
