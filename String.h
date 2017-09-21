#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;

const int MAXSTRNUM=100005;

class String{
	
	public:
	void strrand(int length,string limitstr) {
		register int lent=limitstr.length();
		for(register int i=0;i<length;++i) {
			register int temp=rand()*rand()%lent;
			cout<<limitstr[temp];
		}
	}
	void sentencerand(int wordnum,int wordlength,string limitstr,string separator) {
		register int lent=separator.length();
		for(register int i=1;i<=wordnum;++i) {
			String STRING;STRING.strrand(wordlength,limitstr);
			register int temp=rand()*rand()%lent;
			if(i!=wordnum) cout<<separator[temp];
		}
	}
	void strrandom(int lengthfrom,int lengthto,string limitstr) {
		register int lent=limitstr.length();
		register int length=rand()*rand()%lengthto+1;
		while(length<lengthfrom) length=rand()*rand()%lengthto+1;
		for(register int i=0;i<length;++i) {
			register int temp=rand()*rand()%lent;
			cout<<limitstr[temp];
		}
	}
	void sentencerandom(int wordnum,int wordlengthfrom,int wordlengthto,string limitstr,string separator) {
		register int lent=separator.length();
		for(register int i=1;i<=wordnum;++i) {
			String STRING;STRING.strrandom(wordlengthfrom,wordlengthto,limitstr);
			register int temp=rand()*rand()%lent;
			if(i!=wordnum) cout<<separator[temp];
		}
	}
};

