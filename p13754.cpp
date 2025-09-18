#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 5000005;


int bit1[MAXN], bit2[MAXN];
int n;
int p[MAXN], H[MAXN];
int P[MAXN];

inline void fenw_clear(int *bit, int n){
   
    memset(bit+1, 0, sizeof(int)*n);
}


inline void fenw_upd(int *bit, int n, int pos){
    for(int x = pos; x <= n; x += x&-x)
        bit[x] ^= 1;
}

inline int fenw_qry(int *bit, int pos){
    int s = 0;
    for(int x = pos; x > 0; x -= x&-x)
        s ^= bit[x];
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }


        fenw_clear(bit1, n);
        int tot_par = 0;
        static int invL[MAXN];
        for(int i = 1; i <= n; i++){
    
            int c_le = fenw_qry(bit1, p[i]);
            invL[i] = tot_par ^ c_le;
       
            fenw_upd(bit1, n, p[i]);
            tot_par ^= 1;
        }

        fenw_clear(bit2, n);
        tot_par = 0;
        for(int i = n; i >= 1; i--){
     
            int c_lt = fenw_qry(bit2, p[i]-1);
            int invR = tot_par ^ c_lt;
            fenw_upd(bit2, n, p[i]);
            tot_par ^= 1;
            H[i] = (invL[i] ^ invR);
        }

    
        P[0] = 0;
        for(int i = 1; i <= n; i++)
            P[i] = P[i-1] + H[i];

        ll base = P[n]; 
        ll best = 0;
        const ll INF = (ll)1e18;
        ll bestA[2] = { -INF, -INF };

        for(int k = 1; k <= n; k++){
            if(k >= 2){
              
                ll D0 = (ll)k - 2LL*P[k-1];
                ll D1 = (ll)k + 1 - 2LL*P[k-1] - 2LL*H[k];
                int pk = k & 1;
              
                ll cand0 = bestA[pk]   + D0;
                ll cand1 = bestA[1-pk] + D1;
                best = max({best, cand0, cand1});
            }
           
            ll Ak = 2LL*P[k-1] - k;
            bestA[k&1] = max(bestA[k&1], Ak);
        }

     
        static int Hrev[MAXN], Prev[MAXN];
        for(int i = 1; i <= n; i++){
            Hrev[i] = H[n - i + 1];
        }
        Prev[0] = 0;
        for(int i = 1; i <= n; i++){
            Prev[i] = Prev[i-1] + Hrev[i];
        }
        bestA[0] = bestA[1] = -INF;
        for(int k = 1; k <= n; k++){
            if(k >= 2){
                ll D0 = (ll)k - 2LL*Prev[k-1];
                ll D1 = (ll)k + 1 - 2LL*Prev[k-1] - 2LL*Hrev[k];
                int pk = k & 1;
                ll cand0 = bestA[pk]   + D0;
                ll cand1 = bestA[1-pk] + D1;
                best = max({best, cand0, cand1});
            }
            ll Ak = 2LL*Prev[k-1] - k;
            bestA[k&1] = max(bestA[k&1], Ak);
        }

       
        if(best < 0) best = 0;
        cout << (base + best) << "\n";
    }
   
    return 0;
}