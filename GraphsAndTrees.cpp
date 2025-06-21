#include <bits/stdc++.h>
using namespace std;

//This template is for trees and graphs


//--------------------------------------------------------------------------

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& level, vector<vector<int>>& parents){
	parents[node][0] = parent;
	if(parent!=-1){
		level[node] = 1 + level[parent];
	}

	for(int child : adj[node]){
		if(child!=parent){
			dfs(child, node, adj, level, parents);
			
		}
	}
}

int kthParent(int x, int k, vector<vector<int>>& parents){
	int maxParents = parents[0].size();
	for(int i=0; i<maxParents; i++){
		if((k>>i)&1){
			x = parents[x][i];
		}
	}
	return x;
}

int lca(int a, int b, vector<vector<int>>& parents, vector<int>& level){
	if(level[a]>level[b]){
		swap(a, b);
	}

	int diffOfLevel = level[b] - level[a];

	b = kthParent(b, diffOfLevel, parents);
	
	if(b==a){
		return b;
	}
	int maxParents = parents[0].size();
	for(int i=maxParents-1; i>=0; i--){
		int parentOfA = parents[a][i];
		int parentOfB = parents[b][i];

		if(parentOfA != parentOfB){
			a = parentOfA;
			b = parentOfB;
		}
	}
	return parents[a][0];
}

	// dfs(0, -1, adj, level, parents);

	// for(int j=1; j<maxParents; j++){
	// 	for(int i=0; i<n; i++){
	// 		int midNode = parents[i][j-1];
	// 		if(midNode!=-1){
	// 			parents[i][j] = parents[midNode][j-1];
	// 		}
	// 	}
	// }

//------------------------------------------------------------------------

void dfsForRerooting(int node, int parent, vector<vector<int>>& adj, vector<int>& cnt, vector<long long>& sum){
	cnt[node] = 1;
	//sum[node] = 0;

	for(int child : adj[node]){
		if(child!=parent){
			dfsForRerooting(child, node, adj, cnt, sum);
			cnt[node] += cnt[child];
			sum[node] += sum[child] + cnt[child];
		}
	}
}

void changeRoot(int currRoot, int nextRoot, vector<int>& cnt, vector<long long>& sum){
	cnt[currRoot] -= cnt[nextRoot];
	sum[currRoot] -= sum[nextRoot] + cnt[nextRoot];

	cnt[nextRoot] += cnt[currRoot];
	sum[nextRoot] += sum[currRoot] + cnt[currRoot];
}

void reroot(int node, int parent, vector<vector<int>>& adj, vector<long long>& ans, vector<int>& cnt, vector<long long>& sum){
	ans[node] = sum[node];
	for(int child : adj[node]){
		if(child!=parent){
			changeRoot(node, child, cnt, sum);
			reroot(child, node, adj, ans, cnt, sum);
			changeRoot(child, node, cnt, sum);
		}
	}
}

//-------------------------------------------------------------------------

void Dijkistra(int source, vector<vector<pair<int,int>>>& adj, vector<long long>& dist){
	dist[source] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>> pq; //<edge, node>
	pq.push({0,source});

	while(!pq.empty()){
		int node = pq.top().second;
		long long currWeight = pq.top().first;
		pq.pop();

		if(currWeight>dist[node]) continue;

		for(auto &neighbour : adj[node]){
			long long newDist = currWeight+neighbour.second;
			int neighbourNode = neighbour.first;

			if(dist[neighbourNode]>newDist){
				dist[neighbourNode] = newDist;
				pq.push({newDist, neighbourNode});
			}
		}
	}
}

//-------------------------------------------------------------------------

class UnionFind{
	private: vector<int> parents, rank;
	public:
		UnionFind(int n){
			rank.assign(n, 0);
			parents.assign(n, 0);
			iota(parents.begin(), parents.end(), 0);
		}
	
	int findSet(int i){
		if(parents[i]==i){
			return i;
		}
		return parents[i] = findSet(parents[i]);
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x]>rank[y]){
				parents[y] = x;
			}
			else{
				parents[x] = y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
};

//-------------------------------------------------------------------------

void solve(){
	return;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();	
}

