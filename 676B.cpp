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
    vector<int> first(2);
    vector<int> second(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            int x = ch-'0';
            if(i==0 && j==1){
                first[0] = x;
            }
            else if(i==1 && j==0){
                first[1] = x;
            }
            else if(i==n-1 && j==n-2){
                second[0] = x;
            }
            else if(i==n-2 && j==n-1) second[1] = x;
        }
    }
    if(first[0]==first[1] && second[0]==second[1]){
        if(first[0]==second[0]){
            cout<<2<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<1<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        }
    }
    if(first[0]!=first[1] && second[0]!=second[1]){
        cout<<2<<endl;
        if(first[0]==1) cout<<1<<" "<<2<<endl;
        else cout<<2<<" "<<1<<endl;
        if(second[0]==0) cout<<n<<" "<<n-1<<endl;
        else cout<<n-1<<" "<<n<<endl;
        return;
    }
    if(first[0]!=first[1]){
        cout<<1<<endl;
        if(first[0]==second[0]) cout<<1<<" "<<2<<endl;
        else cout<<2<<" "<<1<<endl;
    }
    else{
        cout<<1<<endl;
        if(first[0]==second[0]) cout<<n<<" "<<n-1<<endl;
        else cout<<n-1<<" "<<n<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
