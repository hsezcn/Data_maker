#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

const int MAX_NODE_NUM=1005;

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
	int node_num,cnt,edge_weight_max,father[MAX_NODE_NUM],link_limit[MAX_NODE_NUM],Link_num_Limit;
	bool w[MAX_NODE_NUM][MAX_NODE_NUM];
	inline int find(int x) {return father[x]=x==father[x]?x:find(father[x]);}
	public:
	//树
	void tree(int node_num,int edge_weight_max,int edge_num_limit) {
	//if edge_num_limit->1-->a chain ,if edge_num_limit->2-->a binary_tree,if edge_num_limit->0-->a normal tree
		srand((int)time(0));
		cout<<node_num<<endl;
		if(edge_num_limit==0) Link_num_Limit=node_num;
		else Link_num_Limit=edge_num_limit;
		for(register int i=1;i<=node_num;++i) father[i]=i;
		while(cnt<node_num-1) {
			register int u=rand()%node_num+1,v=rand()%node_num+1;
			while(find(u)==find(v)||link_limit[u]>Link_num_Limit||link_limit[v]>Link_num_Limit)
				u=rand()*rand()%node_num+1,v=rand()*rand()%node_num+1;
			register long long val=rand()*rand()%edge_weight_max+1;
			father[find(u)]=find(v);
			link_limit[u]++;link_limit[v]++;
			printf("%d %d %d\n",u,v,val);
			cnt++;
		}
	}
	//强连通图
	void diagram(int node_num,int edge_num,int edge_weight_max,bool directed) {//Must be strong connectivity
		srand((int)time(0));
		cout<<node_num<<" "<<edge_num<<endl;
		for(register int i=1;i<=node_num;++i) father[i]=i;
		while(cnt<node_num-1) {
			register int u=rand()%node_num+1,v=rand()%node_num+1;
			while(find(u)==find(v))
				u=rand()*rand()%node_num+1,v=rand()*rand()%node_num+1;
			register long long val=rand()*rand()%edge_weight_max+1;
			father[find(u)]=find(v);
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
			cnt++;
		}
		for(register int i=cnt;i<=edge_num;++i) {
			register int u=rand()%node_num+1,v=rand()%node_num+1;
			while(w[u][v]||u==v)
				u=rand()*rand()%node_num+1,v=rand()*rand()%node_num+1;
			register long long val=rand()*rand()%edge_weight_max+1;
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
		}
	}
	//图
	void graph(int node_num,int edge_num,int edge_weight_max,bool directed) {
		srand((int)time(0));
		cout<<node_num<<" "<<edge_num<<endl;
		for(register int i=1;i<=edge_num;++i)
		{
			register int u=rand()%node_num+1,v=rand()%node_num+1;
			while(w[u][v]||u==v)
				u=rand()*rand()%node_num+1,v=rand()*rand()%node_num+1;
			register long long val=rand()*rand()%edge_weight_max+1;
			w[u][v]=1;
			if(!directed) w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
		}
	}
	//菊花图
	void flower(int node_num,int edge_weigh_max,bool directed)
	{
		srand((int)time(0));
		register int edge_num=node_num-1;
		cout<<node_num<<" "<<edge_num<<endl;
		register int from=rand()%node_num+1;
		for(register int i=1;i<=edge_num;++i)
		{
			register int u=from,v=rand()%node_num+1;
			while(w[u][v]||u==v)v=rand()*rand()%node_num+1;
			register long long val=rand()*rand()%edge_weight_max+1;
			w[u][v]=1;
			if(!directed)w[v][u]=1;
			printf("%d %d %d\n",u,v,val);
		}
	}
	void hack_spfa(int node_num,int edge_num)
	{
	//	srand((int)time(0));
    	printf("%d %d\n",node_num,edge_num);
    	for(register int i=node_num;i>=2;--i)
        	printf("1 %d %d\n%d %d 1\n",i,(n-i+1)*2+1,i,i-1);
	}
};
