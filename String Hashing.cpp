#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Hash{
	const int MOD = 1e9 + 7;
	const int BASE1 = 5689;
	const int BASE2 = 8861;

	vector<pair<int,int>> hashes, Pow;

	//We are maaintaining 1-based indexing

	Hash(string s){
		hashes.assign(s.size()+1, {0,0});   //both are prefix sum values, not individual index values.
		Pow.assign(s.size()+1, {1,1});

		for(int i=0; i<s.size(); i++){
			hashes[i+1] = { (1ll * hashes[i].first * BASE1 + (s[i]-'a' + 1)) % MOD,
						    (1ll * hashes[i].second * BASE2 + (s[i]-'a' + 1)) % MOD};

			Pow[i+1] = { (1ll * Pow[i].first * BASE1) % MOD,
						  (1ll * Pow[i].second * BASE2) % MOD};
		}
	}

	//0 based indexing input

	pair<int,int> get(int l, int r){
		l++, r++;

		int hash1 = (hashes[r].first - (1ll * hashes[l-1].first * Pow[r-l+1].first) % MOD + MOD) % MOD;
		int hash2 = (hashes[r].second - (1ll * hashes[l-1].second * Pow[r-l+1].second) % MOD + MOD ) % MOD;

		return {hash1, hash2};
	}

};


struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;  
    }
};



signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s = "abcd";
	Hash a(s);

	int l, r;
	pair<int,int> hash = a.get(l,r);

	unordered_map<pair<int,int>, int, pair_hash> mp;
}
