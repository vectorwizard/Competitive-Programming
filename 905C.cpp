#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(k!=4){
        int mini = 1e9;
        for(int i=0;i<n;i++){
            if(a[i]%k == 0) mini = 0;
            else mini = min(mini,k-(a[i]%k));
        }
        cout<<mini<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]%k == 0){
            cout<<0<<endl;
            return;
        }
    }
    int evens = 0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            evens++;
        }
    }
    if(evens>=2){
        cout<<0<<endl;
    }
    else if(evens==1){
        cout<<1<<endl;
    }
    else{
        int minim = 1e9;
        bool fl = false;
        for(int i=0;i<n;i++){
            if(a[i]%4==3){
                fl = true;
                break;
            }    
        }
        if(fl){
            cout<<1<<endl;
        }
        else cout<<2<<endl;
    }
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
