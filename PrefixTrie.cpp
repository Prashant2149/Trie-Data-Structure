#include<bits/stdc++.h>
#define fr(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
using namespace std;
struct Trienode{
	char val;
	int count;
	int end;
	Trienode *child[26];
};
Trienode *root;


Trienode *getnode(int index){
	Trienode *newnode=new Trienode;
	newnode->val='a' + index;
	newnode->count=newnode->end=0;
	for(int i=0;i<26;i++){
		newnode->child[i]=NULL;
	}
	return newnode;
}
void insert(string s){
	Trienode *curr=root;
	int index;
	for(int i=0;i<s[i]!='\0';i++){
		//cout<<s[i]<<endl;
		index=s[i]-'a';
		if(curr->child[index]==NULL)
			curr->child[index]=getnode(index);
			//cout<<curr->child[index]->val<<endl;
			curr->child[index]->count+=1;
			curr=curr->child[index];
	}
	curr->end+=1;
}
bool search(string s){
	Trienode *curr=root;
	int index;
	for(int i=0;i<s.size();i++){
		index=s[i]-'a';
		if(curr->child[index]==NULL)
		return false;
		curr=curr->child[index];
	}
	if(curr->end>0)
	return true;
	else
	return false;
}
bool startwith(string p){
	Trienode *curr=root;
	
	for(int i=0;i<p.size();i++){
		int index=p[i]-'a';
		if(curr->child[index]==NULL)
		return false;
		curr=curr->child[index];
	}
	return (curr->count>0);
}
void init(){
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getnode('/'-'a');
}
int main(){
	init();
    insert("apple");
    insert("add");
   
   cout<<search("add")<<endl;
    insert("dfg");
    cout<<search("dfg")<<endl;
    cout<<startwith("a")<<endl;
     cout<<startwith("df")<<endl;
	cout<<startwith("add")<<endl;
}
