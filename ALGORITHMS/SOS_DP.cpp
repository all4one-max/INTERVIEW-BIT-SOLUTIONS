#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void solve() {
  cin >> n;
  vector<int> v(1 << n, 0);
  vector<vector<int>> dp(1 << n, vector<int> (n + 5, 0));
  vector<int> F(1 << n, 0);
  fo(i, 1 << n) cin >> v[i];
  fo(mask, 1 << n) {
    dp[mask][0] = v[mask];
    fo1(j, n + 1) {
      if (mask & (1 << (j - 1))) dp[mask][j] = dp[mask][j - 1] + dp[mask ^ (1 << (j - 1))][j - 1];
      else dp[mask][j] = dp[mask][j - 1];
    }
    F[mask] = dp[mask][n];
  }
  fo(mask, 1 << n) cout << F[mask] << " ";
  cout << endl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
  // for printing erros
  freopen("Errors.txt", "w", stderr);
# endif
  t = 1;
  fo(i, t) solve();
  return 0;
}
/*
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #
*/
/*
# ``````¶0````1¶1_```````````````````````````````````````
# ```````¶¶¶0_`_¶¶¶0011100¶¶¶¶¶¶¶001_````````````````````
# ````````¶¶¶¶¶00¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶0_````````````````
# `````1_``¶¶00¶0000000000000000000000¶¶¶¶0_`````````````
# `````_¶¶_`0¶000000000000000000000000000¶¶¶¶¶1``````````
# ```````¶¶¶00¶00000000000000000000000000000¶¶¶_`````````
# ````````_¶¶00000000000000000000¶¶00000000000¶¶`````````
# `````_0011¶¶¶¶¶000000000000¶¶00¶¶0¶¶00000000¶¶_````````
# ```````_¶¶¶¶¶¶¶00000000000¶¶¶¶0¶¶¶¶¶00000000¶¶1````````
# ``````````1¶¶¶¶¶000000¶¶0¶¶¶¶¶¶¶¶¶¶¶¶0000000¶¶¶````````
# ```````````¶¶¶0¶000¶00¶0¶¶`_____`__1¶0¶¶00¶00¶¶````````
# ```````````¶¶¶¶¶00¶00¶10¶0``_1111_`_¶¶0000¶0¶¶¶````````
# ``````````1¶¶¶¶¶00¶0¶¶_¶¶1`_¶_1_0_`1¶¶_0¶0¶¶0¶¶````````
# ````````1¶¶¶¶¶¶¶0¶¶0¶0_0¶``100111``_¶1_0¶0¶¶_1¶````````
# ```````1¶¶¶¶00¶¶¶¶¶¶¶010¶``1111111_0¶11¶¶¶¶¶_10````````
# ```````0¶¶¶¶__10¶¶¶¶¶100¶¶¶0111110¶¶¶1__¶¶¶¶`__````````
# ```````¶¶¶¶0`__0¶¶0¶¶_¶¶¶_11````_0¶¶0`_1¶¶¶¶```````````
# ```````¶¶¶00`__0¶¶_00`_0_``````````1_``¶0¶¶_```````````
# ``````1¶1``¶¶``1¶¶_11``````````````````¶`¶¶````````````
# ``````1_``¶0_¶1`0¶_`_``````````_``````1_`¶1````````````
# ``````````_`1¶00¶¶_````_````__`1`````__`_¶`````````````
# ````````````¶1`0¶¶_`````````_11_`````_``_``````````````
# `````````¶¶¶¶000¶¶_1```````_____```_1``````````````````
# `````````¶¶¶¶¶¶¶¶¶¶¶¶0_``````_````_1111__``````````````
# `````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶01_`````_11____1111_```````````
# `````````¶¶0¶0¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1101_______11¶_```````````
# ``````_¶¶¶0000000¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶0¶0¶¶¶1````````````
# `````0¶¶0000000¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1`````````````
# ````0¶0000000¶¶0_````_011_10¶110¶01_1¶¶¶0````_100¶001_`
# ```1¶0000000¶0_``__`````````_`````````0¶_``_00¶¶010¶001
# ```¶¶00000¶¶1``_01``_11____``1_``_`````¶¶0100¶1```_00¶1
# ``1¶¶00000¶_``_¶_`_101_``_`__````__````_0000001100¶¶¶0`
# ``¶¶¶0000¶1_`_¶``__0_``````_1````_1_````1¶¶¶0¶¶¶¶¶¶0```
# `_¶¶¶¶00¶0___01_10¶_``__````1`````11___`1¶¶¶01_````````
# `1¶¶¶¶¶0¶0`__01¶¶¶0````1_```11``___1_1__11¶000`````````
# `1¶¶¶¶¶¶¶1_1_01__`01```_1```_1__1_11___1_``00¶1````````
# ``¶¶¶¶¶¶¶0`__10__000````1____1____1___1_```10¶0_```````
# ``0¶¶¶¶¶¶¶1___0000000```11___1__`_0111_```000¶01```````
# ```¶¶¶00000¶¶¶¶¶¶¶¶¶01___1___00_1¶¶¶`_``1¶¶10¶¶0```````
# ```1010000¶000¶¶0100_11__1011000¶¶0¶1_10¶¶¶_0¶¶00``````
# 10¶000000000¶0________0¶000000¶¶0000¶¶¶¶000_0¶0¶00`````
# ¶¶¶¶¶¶0000¶¶¶¶_`___`_0¶¶¶¶¶¶¶00000000000000_0¶00¶01````
# ¶¶¶¶¶0¶¶¶¶¶¶¶¶¶_``_1¶¶¶00000000000000000000_0¶000¶01```
# 1__```1¶¶¶¶¶¶¶¶¶00¶¶¶¶00000000000000000000¶_0¶0000¶0_``
# ```````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶00000000000000000000010¶00000¶¶_`
# ```````0¶¶¶¶¶¶¶¶¶¶¶¶¶¶00000000000000000000¶10¶¶0¶¶¶¶¶0`
# ````````¶¶¶¶¶¶¶¶¶¶0¶¶¶00000000000000000000010¶¶¶0011```
# ````````1¶¶¶¶¶¶¶¶¶¶0¶¶¶0000000000000000000¶100__1_`````
# `````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶000000000000000000¶11``_1``````
# `````````1¶¶¶¶¶¶¶¶¶¶¶0¶¶¶00000000000000000¶11___1_`````
# ``````````¶¶¶¶¶¶0¶0¶¶¶¶¶¶¶0000000000000000¶11__``1_````
# ``````````¶¶¶¶¶¶¶0¶¶¶0¶¶¶¶¶000000000000000¶1__````__```
# ``````````¶¶¶¶¶¶¶¶0¶¶¶¶¶¶¶¶¶0000000000000000__`````11``
# `````````_¶¶¶¶¶¶¶¶¶000¶¶¶¶¶¶¶¶000000000000011_``_1¶¶¶0`
# `````````_¶¶¶¶¶¶0¶¶000000¶¶¶¶¶¶¶000000000000100¶¶¶¶0_`_
# `````````1¶¶¶¶¶0¶¶¶000000000¶¶¶¶¶¶000000000¶00¶¶01`````
# `````````¶¶¶¶¶0¶0¶¶¶0000000000000¶0¶00000000011_``````_
# ````````1¶¶0¶¶¶0¶¶¶¶¶¶¶000000000000000000000¶11___11111
# ````````¶¶¶¶0¶¶¶¶¶00¶¶¶¶¶¶000000000000000000¶011111111_
# ```````_¶¶¶¶¶¶¶¶¶0000000¶0¶00000000000000000¶01_1111111
# ```````0¶¶¶¶¶¶¶¶¶000000000000000000000000000¶01___`````
# ```````¶¶¶¶¶¶0¶¶¶000000000000000000000000000¶01___1````
# ``````_¶¶¶¶¶¶¶¶¶00000000000000000000000000000011_111```
# ``````0¶¶0¶¶¶0¶¶0000000000000000000000000000¶01`1_11_``
# ``````¶¶¶¶¶¶0¶¶¶0000000000000000000000000000001`_0_11_`
# ``````¶¶¶¶¶¶¶¶¶00000000000000000000000000000¶01``_0_11`
# ``````¶¶¶¶0¶¶¶¶00000000000000000000000000000001```_1_11
*/
