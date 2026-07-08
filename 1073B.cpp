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
    int noofzeros = 0;
    int noofones = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0) noofzeros++;
        if(a[i]==1) noofones++;
    }
    if(noofzeros==0){
        cout<<"No"<<endl;
        return;
    }
    else if(noofzeros==1){
        cout<<"Yes"<<endl;
    }
    else{
        if(noofones==0){
            cout<<"No"<<endl;
            return;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}