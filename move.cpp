// A re-implementation of the Linux mv command

#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
using namespace std;
void print_error(char* th, char* filename1, char* filename2){
    fprintf(stderr, "%s cannot move %s to %s\n%s\n", th, filename1, filename2, strerror(errno));
    exit(EXIT_FAILURE);
}

void print_usage(char* th){
    fprintf(stderr, "SYNTAX ERROR:\nUsage: %s [old filename] [new filename]\n", th);
    exit(EXIT_FAILURE);
}

int main(int argc,char* argv[]){

	if(argc != 3){
		print_usage(argv[0]);
	}
	else
	{
		string src(argv[1]);
		string des(argv[2]);
		if(src.substr(0,2)!="./")
			src="./"+src;
		if(des.substr(0,2)!="./")
			des="./"+des;
		string x,y,z,t;
		int i=src.size()-1,j=des.size()-1;
		while(i>=0)
		{
			if(src[i]=='/')
				break;
			x=src[i]+x;
			i--;
		}
		while(j>=0)
		{
			if(des[j]=='.' && j==0)
			{
				t.clear();
				break;
			}
			t=des[j]+t;
			j--;
		}
		//cout<<"t"<<t<<endl;
		if(t.size()!=0)
			print_error(argv[0], argv[1], argv[2]);
    	else
    	{
    		//cout<<src<<" "<<des<<endl;
    		//cout<<a<<" "<<b<<endl;		
    		//cout<<"argv[1]"<<argv[1]<<endl;
    		//cout<<"argv[1]"<<argv[1]<<"ss"<<endl;
    		// cout<<argv[1]<<" "<<argv[2]<<endl;
    		if(des[des.size()-1]!='/')
    		{
    			//cout<<"x"<<" "<<x;
    			x='/' + x;
    		}
    		des+=x;
    		const char *a=src.c_str();
    		const char *b=des.c_str();
    		if(rename(a,b)==-1)
    		{
    			print_error(argv[0], argv[1], argv[2]);	
    		}
    	}
	}
    return 0;
}