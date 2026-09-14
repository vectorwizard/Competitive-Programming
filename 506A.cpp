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
    string t;
    cin>>t;
    int i = 0;
    int j = n-1;
    int maxi = -1;
    while(i<n-1){
        string temp1 = t.substr(0,i+1);
        string temp2 = t.substr(j,i+1);
        if(temp1==temp2){
            maxi = max(maxi,i);
        }
        i++;
        j--;
    }
    string ans = t;
    for(int i=0;i<k-1;i++){
        for(int j = maxi+1;j<n;j++){
            ans+=t[j];
        }
    }
    cout<<ans<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
