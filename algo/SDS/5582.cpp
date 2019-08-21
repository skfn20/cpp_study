#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int SIZE=26;

struct TrieNode
{
	struct TrieNode* children[SIZE];
	bool isEndOfWord;
};

struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
int insert(struct TrieNode *root, string key, bool comp=false) 
{ 
    struct TrieNode *pCrawl = root; 
  	
  	int count=0;
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]){
        	if(!comp) pCrawl->children[index] = getNode(); 
        	else return count;
		}
  		else count++;
        pCrawl = pCrawl->children[index]; 
    } 
  
    pCrawl->isEndOfWord = true;
    return count;
} 

bool search(struct TrieNode* root, string key)
{
	struct TrieNode * pCrawl =root;
	
	for(int i=0; i<key.length(); i++){
		int index=key[i]-'A';
		if(!pCrawl->children[index]) return false;
		
		pCrawl=pCrawl->children[index];
	}
	return pCrawl!=NULL && pCrawl->isEndOfWord;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	struct TrieNode* root = getNode();
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int s1_size = s1.length();
	
	
	insert(root, s1);
	string temp="";
	for(int k=1; k<s1_size; k++){
		temp="";
		for(int i=k; i<s1_size; i++){
			temp+=s1[i];
		}
		insert(root, temp);
	}
	
	int max=insert(root, s2, true);
	int s2_size= s2.length();
	for(int i=0; i<s2_size; i++){
		temp="";
		for(int j=i; j<s2_size; j++){
			temp+=s2[j];
		}
		int same_length = insert(root, temp, true);
		if(max < same_length) max= same_length;
	}
	
	cout << max << "\n";
	
	return 0;
}
