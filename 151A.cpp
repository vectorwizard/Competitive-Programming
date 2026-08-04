#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k,x;
    cin>>n>>k>>x;
    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    if(k==1){
        cout<<"NO"<<endl;
        return;
    }
    if(k==2){
        if(n%2==0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++) cout<<2<<" ";
            cout<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        if(n%2==0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++) cout<<2<<" ";
            cout<<endl;
            return;
        }
        else{
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            cout<<3<<" ";
            n-=3;
            while(n>0){
                cout<<2<<" ";
                n-=2;
            }
            cout<<endl;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
