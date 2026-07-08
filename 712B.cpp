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
    string a,b;
    cin>>a;
    cin>>b;
    if(a==b){
        cout<<"YES"<<endl;
        return;
    }
    unordered_map<int,int> mpp;
    mpp[-1] = 0;
    int x = 0;
    int patch=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1') x++;
        else x--;
        mpp[i] = x;
        if(a[i]==b[i]){
            if(patch>0){
                if(mpp[i-1]!=0 || mpp[i-patch-1]!=0){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            patch = 0;
        }
        else{
            patch++;
        }
    }
    if(patch>0){
        if(mpp[n-1]!=0 || mpp[n-1-patch]!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

