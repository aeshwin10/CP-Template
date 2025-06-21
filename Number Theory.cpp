//Number Theory Template:
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<long long> getPrimeDivisors(long long n){   //Time Complexity - O(sqrtN + x) x-> summation of all the power of factors
	vector<long long> factorization;               //Worst case it will be O(sqrtN + log2N)
	    for(long long i = 2; i*i<=n; i++){
	        if(n%i==0){
	            factorization.push_back(i);
	            while(n%i==0){
	                n/=i;
	            }
	        }
	    }
	    if (n!=1){                            //If p1^a * p2^b are factors and p?sqrt(n), it will contradict. 
	        factorization.push_back(n);       //So only one element p>sqrt(n) exist and that will be n itself.
	    }
	    return factorization;
}


vector<long long> getDivisors(long long n){    //Time Complexity - O(sqrtN)
    vector<long long> factors;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            factors.push_back(i);
            if((n/i)!=i){
                factors.push_back(n/i);
            }
        }
    }
    sort(factors.begin(), factors.end());        //Comment it if not necessary
    return factors;
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




long long modInverse(long long A, long long M){    //Time Complexity - O(logN)
    long long m0 = M;
    long long y = 0, x=1;
    if(M==1){
        return 0;
    }
    while(A>1){
        long long q = A/M;
        long long t = M;
        M = A%M, A=t;
        t = y;
        y = x-q*y;
        x=t;
    }
    if(x<0){
        x+=m0;
    }
    return x;
}

long double ncr(long long n, long long r){       //Time Complexity - O(min(r, n-r))
    int i;
    long double p=1.0, q=1.0, ans=1.0;

    if(r>n){
        return 0.0;
    }

    if(r==0){
        return 1;
    }

    for(int i=0; i<r; i++){
        p=n-i;
        q=i+1;
        ans*=(p/q);
    }
    return ans;

}

long long power(long long a, long long b){       //Time Complexity -> O(logb)
    long long res = 1;
    a = a % MOD;
    

    if(a==0){
        return 0;
    }
    while(b>0){
        if(b&1){
            res = (res * a) % MOD;
        }
        b = b >> 1;
        a = (a*a) % MOD;
    }
    return res;

}

long long modInverse(long long n, int p){
    return power(n, p-2, p);                  //Little Fermat Theorem
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}