#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> mpp;
    int ind1=-1,ind2=-1;
    for(int i=0;i<n;i++){
        if(mpp.find(x-a[i])!=mpp.end()){
            ind1 = mpp[x-a[i]];
            ind2 = i;
            break;
        }
        mpp[a[i]] = i;
    }
    if(ind1==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<ind1+1<<" "<<ind2+1<<endl;
}  

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
