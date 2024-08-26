//Number Theory Template:
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeDivisors(int n){   //Time Complexity - O(sqrtN * log N)
	vector<int> ans;
	    for(int i = 2; i*i<=n; i++){
	        if(n%i==0){
	            ans.push_back(i);
	            while(n%i==0){
	                n/=i;
	            }
	        }
	    }
	    if (n!=1){
	        ans.push_back(n);
	    }
	    return ans;
}


vector<int> getDivisors(int n){        //Time Complexity - O(sqrtN)
     vector<int> ans;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            if((n/i)!=i){
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


vector<int> getPrimes(int n) {          //Time Complexity - O(N*log(log(N))), Space Complexity - O(N)
    int count = 0;
    vector<int> primes(n+1, 1);
    vector<int> ans;
    for(int i = 2; i<n; i++){
        if(!primes[i]){
            continue;
        }
        ans.push_back(i);
        for(long j = (long)i*i; j<n; j+=i){
            primes[j]=0;
        }
    }
    return ans;
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}