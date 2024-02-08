#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define sum(v) accumulate(all(v), 0LL)
#define maxi(v) *max_element(all(v))
#define mini(v) *min_element(all(v))
#define sort(v) sort(all(v))
#define minpq priority_queue<ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<ll, ll> umap_ll;
typedef unordered_map<string, int> umap_si;

class seg_tree
{
    int n;
    vector<pll> tree;

public:
    seg_tree(vector<ll> arr)
    {
        n = arr.size();
        tree.resize(4 * n, {LLONG_MIN, -1});
        for (int i = 0; i < n; i++)
        {
            update(i, arr[i]);
        }
    }
    void update(int i, ll val, int s = 0, int e = -1, int ind = 0)
    {
        if (e == -1)
            e = n - 1;
        if (i < s || e < i)
            return;
        else if (s == e)
        {
            tree[ind] = {val, i};
            return;
        }
        int mid = (s + e) >> 1;
        update(i, val, s, mid, 2 * ind + 1);
        update(i, val, mid + 1, e, 2 * ind + 2);

        if (tree[2 * ind + 1].first > tree[2 * ind + 2].first)
            tree[ind] = tree[2 * ind + 1];
        else
            tree[ind] = tree[2 * ind + 2];
    }
    pll get(int qs, int qe, int s = 0, int e = -1, int ind = 0){
        if(e == -1) 
            e = n-1;
        if(qe < s || e < qs)
            return {LLONG_MIN,-1};
        else if(qs<=s && e<=qe)
            return tree[ind];
        
        int mid = (s+e)>>1;
        pll q1 = get(qs, qe, s, mid, 2*ind+1);
        pll q2 = get(qs, qe, mid+1, e, 2*ind+2);

        if(q1.first > q2.first)
            return q1;
        else 
            return q2;
    }
};