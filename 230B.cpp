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
    int last = -1;
    bool fl = true;
    for(int i=0;i<n;i++){
        if(last==-1){
            if(a[i]==0) continue;
            else last = i;
        }
        else{
            if(a[i]==1){
                if((i-last)<=k) fl = false;
                else last = i;
            }
        }
    }
    if(fl==false) {
        cout<<"No"<<endl;
        return;
    }

    last= -1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            bool blocked = false;
            for(int j=0;j<n;j++){
                if(a[j]==1 && abs(i-j)<=k){
                    blocked = true;
                }
            }
            if(blocked==false) {
                fl = false;
                break;
            }
        }
    }

    if(fl==false) {
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}  

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
