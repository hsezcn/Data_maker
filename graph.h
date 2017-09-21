#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

const int MAXNODENUM=1005;

struct Edge {
	int start,end,weight;
};

class EDGE{
	public:
	void _init_(Edge self,int u,int v,int w) {
		self.start=u;
		self.end=v;
		self.weight=w;
	}
	void _str_(Edge self) {
		printf("%d %d %d\n",self.start,self.end,self.weight);
	}
};

class Graph{
	int nodenum,cnt,edgeweightmax,father[MAXNODENUM],linklimit[MAXNODENUM],LLimit;
	bool w[MAXNODENUM][MAXNODENUM];
	inline int find(int x) {return father[x]=x==father[x]?x:find(father[x]);}
	public:
	void maketree(int nodenum,int edgeweightmax,int edgenumlimit) {
	//if edgenumlimit->1-->a chain ,if edgenumlimit->2-->a binary_tree,if edgenumlimit->0-->a normal tree 
		srand((int)time(0));
		cout<<nodenum<<endl;
		if(edgenumlimit==0) LLimit=nodenum;
		else LLimit=edgenumlimit;
		for(register int i=1;i<=nodenum;++i) father[i]=i;
		while(cnt<nodenum-1) {
			register int u=rand()%nodenum+1,v=rand()%nodenum+1;
			while(find(u)==find(v)||linklimit[u]>LLimit||linklimit[v]>LLimit) u=rand()*rand()%nodenum+1,v=rand()*rand()%nodenum+1;
			register long long val=rand()*rand()%edgeweightmax+1;
			father[find(u)]=find(v);
			linklimit[u]++;linklimit[v]++;
			printf("%d %d %d\n",u,v,val);
			cnt++;
		}
	}
	void makediagram(int nodenum,int edgenum,int edgeweightmax,bool directed) {
		srand((int)time(0));
		cout<<nodenum<<" "<<edgenum<<endl;
		for(register int i=1;i<=nodenum;++i) father[i]=i;
		while(cnt<nodenum-1) {
			register int u=rand()%nodenum+1,v=rand()%nodenum+1;
			while(find(u)==find(v)) u=rand()*rand()%nodenum+1,v=rand()*rand()%nodenum+1;
			register long long val=rand()*rand()%edgeweightmax+1;
			father[find(u)]=find(v);
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
			cnt++;
		}
		for(register int i=cnt;i<=edgenum;++i) {
			register int u=rand()%nodenum+1,v=rand()%nodenum+1;
			while(w[u][v]||u==v) u=rand()*rand()%nodenum+1,v=rand()*rand()%nodenum+1;
			register long long val=rand()*rand()%edgeweightmax+1;
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
		}
	}
	void makegraph(int nodenum,int edgenum,int edgeweightmax,bool directed) {
		srand((int)time(0));
		cout<<nodenum<<" "<<edgenum<<endl;
		for(register int i=1;i<=edgenum;++i) {
			register int u=rand()%nodenum+1,v=rand()%nodenum+1;
			while(w[u][v]||u==v) u=rand()*rand()%nodenum+1,v=rand()*rand()%nodenum+1;
			register long long val=rand()*rand()%edgeweightmax+1;
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
		}
	}
};



