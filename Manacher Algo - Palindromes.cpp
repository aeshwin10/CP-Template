#include <bits/stdc++.h>
using namespace std;

struct manacher{
	vector<int> p;

	void run_manacher(string s){
		int n = s.size();
		p.assign(n, 1);
		int l=1, r=1;               //simply this values works in the start
		for(int i=1; i<n; i++){     //p[0] is always 1, since there is no left element for it.
			if(i<r) p[i] =  min((r-i), (p[l+r-i]));
            else{
                p[i] = 1;
            }
//Worst case value will be 1.
//Now, min(r-i) represents the right side bound, mainly when r = n.
//Now, p[l+r-i] simply represents the copy from the left side from the center.

			while(i - p[i] >= 0 && i + p[i] < n && s[i-p[i]] == s[i+p[i]]) {
                p[i]++;
            }
			if(i+p[i]>r){    //update the new limits. Note, we can update a value of an new p[i] 
				//with old center also, but simply it will increase the TC
				l = i-p[i];
				r = i+p[i];
			}
		}
	}

	void build(string s){
		string t;
		for(auto v : s){
			t+= string("#") + v;    //Do not do t = t + string("#") -> O(n)
		}
		run_manacher(t+"#");         //pre-processed string
	}

	int getLongest(int cen, bool odd){
		int pos = 2*cen+1+(!odd);
		return p[pos] - 1;
	}

	bool checkPalin(int l, int r){
		if((r-l+1) <= getLongest((l+r)/2, (l&1==r&1))){
			return 1;
		}
		return 0;
	}

}m;


void solve(){
	string s = "babbabbabc";
	m.build(s);

	if (s.empty()) cout << "" << "\n";

    int n = s.size();


    int maxLen = 0;
    int centerIdx = 0;

    for(int i=0; i<n; i++){
        for(bool odd : {true, false}){
            int curLen = m.getLongest(i, odd);
            if(curLen > maxLen){
                maxLen = curLen;
                centerIdx = i;
            }
        }
        
    }
    int start = centerIdx - (maxLen - 1) / 2;
    cout << s.substr(start, maxLen) << "\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
}

//Watch Vivek Gupta video for reference.