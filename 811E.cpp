#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int x = a[i]%10;
        if(x%2==1){
            a[i] = a[i] + x;
        }
    }
    bool fl = true;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            fl = false;
            break;
        }
    }
    if(fl){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]%10==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        int x = a[i]%10;
        if(x==4){
            a[i] = a[i] + 18;
        }
        else if(x==8){
            a[i] = a[i] + 14;
        }
        else if(x==6){
             a[i] = a[i] + 6;
        }
    }
    fl = true;
    for(int i=1;i<n;i++){
        int x = a[i]%20;
        int y = a[i-1]%20;
        if(y!=x){
            fl = false;
            break;
        }
    }
    if(fl) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
