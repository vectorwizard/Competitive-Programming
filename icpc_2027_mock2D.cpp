#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll n = a+b+c;
    for(ll i=0;i<=(c/3);i++){
        ll rem3 = c - (i*3);
        if(((rem3*4)+(3*i))>2*n) continue;
        if(a>=rem3){
            ll rem1 = a - rem3;
            ll rem = 2*b + rem1;
            rem-=rem1;
            if(rem%4!=0){
                continue;
            }
            else{
                ll x = i;
                ll ind = 1;
                while(x--){
                    cout<<ind<<" "<<ind+3<<endl;
                    cout<<ind+1<<" "<<ind+4<<endl;
                    cout<<ind+2<<" "<<ind+5<<endl;
                    ind+=6;
                }
                while(rem3--){
                    cout<<ind<<" "<<ind+3<<endl;
                    cout<<ind+1<<" "<<ind+2<<endl;
                    ind+=4;
                }
                while(rem1--){
                    cout<<ind<<" "<<ind+1<<endl;
                    ind+=2;
                }
                for(ll j=ind;j<=2*n;j+=4){
                    cout<<j<<" "<<j+2<<endl;
                    cout<<j+1<<" "<<j+3<<endl;
                }
                return;
            }
        }
        else if((rem3==1 || rem3==2) && b>=2 && b%2==0){
            ll x = i;
            ll ind = 1;
            while(x--){
                cout<<ind<<" "<<ind+3<<endl;
                cout<<ind+1<<" "<<ind+4<<endl;
                cout<<ind+2<<" "<<ind+5<<endl;
                ind+=6;
            }
            if(rem3==1){
                cout<<ind+1<<" "<<ind+4<<endl;
                cout<<ind<<" "<<ind+2<<endl;
                cout<<ind+3<<" "<<ind+5<<endl;
                ind+=6;
                b-=2;
            }
            else if(rem3==2){
                cout<<ind+1<<" "<<ind+4<<endl;
                cout<<ind<<" "<<ind+2<<endl;
                cout<<ind+3<<" "<<ind+6<<endl;
                cout<<ind+5<<" "<<ind+7<<endl;
                ind+=8;
                b-=2;
            }
            while(b>0){
                cout<<ind<<" "<<ind+2<<endl;
                cout<<ind+1<<" "<<ind+3<<endl;
                ind+=4;
                b-=2;
            }
            while(a>0){
                cout<<ind<<" "<<ind+1<<endl;
                ind+=2;
                a-=1;
            }
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}