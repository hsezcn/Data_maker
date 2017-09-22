#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;

const int MAX_STR_NUM=100005;

class String{
	
	public:
	void word_rand(int length,string limit_string) {
		register int lent=limit_string.length();
		for(register int i=0;i<length;++i) {
			register int temp=rand()*rand()%lent;
			cout<<limit_string[temp];
		}
	}
	void sentence_rand(int word_num,int word_length,string limit_string,string separator) {
		register int lent=separator.length();
		for(register int i=1;i<=word_num;++i) {
			String STRING;STRING.word_rand(word_length,limit_string);
			register int temp=rand()*rand()%lent;
			if(i!=word_num) cout<<separator[temp];
		}
	}
	void word_random(int length_from,int length_to,string limit_string) {
		register int lent=limit_string.length();
		register int length=rand()*rand()%length_to+1;
		while(length<length_from) length=rand()*rand()%length_to+1;
		for(register int i=0;i<length;++i) {
			register int temp=rand()*rand()%lent;
			cout<<limit_string[temp];
		}
	}
	void sentence_random(int word_num,int word_length_from,int word_length_to,string limit_string,string separator) {
		register int lent=separator.length();
		for(register int i=1;i<=word_num;++i) {
			String STRING;STRING.word_random(word_length_from,word_length_to,limit_string);
			register int temp=rand()*rand()%lent;
			if(i!=word_num) cout<<separator[temp];
		}
	}
};

