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
    vector<vector<int>> vec(n);
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++) {
            int x;
            cin>>x;
            vec[i].push_back(x);
            mpp[vec[i].back()]++;
        }
    }
    for(int i=0;i<n;i++){
        bool poss=true;
        for(auto it:vec[i]){
            if(mpp[it]<=1){
                poss=false;
                break;
            }
        }
        if(poss==true){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

