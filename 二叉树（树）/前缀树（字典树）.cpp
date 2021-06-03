#include<iostream>
#include<string>
using namespace std;
struct trie {
	trie *child[26];
	int pass;
	int end;
	trie() {
		memset(child, NULL, sizeof(child));
		pass = 0;
		end = 0;
	}
};
/*trie* trieCreate()
{
	trie *t = new trie();
	return t;
}*/

void trieinsert(trie* obj,string h){
	int l = h.length();
	for (int i = 0; i < l; i++)
	{
		if((obj->child)[h[i] - 'a'] ==NULL)
		(obj->child)[h[i] - 'a'] = new trie();
		obj = (obj->child)[h[i] - 'a'];
		obj->pass++;
		
	}
	obj->end++; 
}
int strcount(trie* obj, string h)
{
	int l = h.length();
	bool m = true;
	for (int i = 0; i < l; i++)
	{
		if ((obj->child)[h[i] - 'a'] == NULL) {
			m = false;
			break;
		}
		obj = (obj->child)[h[i] - 'a'];
	}
	if (m)return obj->end;
	return 0;
}

int precount(trie *obj, string h)
{
	int l = h.length();
	bool m = true;
	for (int i = 0; i < l; i++)
	{
		if ((obj->child)[h[i] - 'a'] == NULL) {
			m = false;
			break;
		}
		obj = (obj->child)[h[i] - 'a'];
	}
	if (m)return obj->pass;
	return 0;
}

int main() {
	string h = "az";
	string z = "acd";
	string t = "acd";
	trie *root=new trie();
	trieinsert(root, h);
	trieinsert(root, z);
	cout<<precount(root, z);
	return 0;
	
}