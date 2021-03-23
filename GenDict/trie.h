 ///
 /// @file    trie.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-17 14:08:20
 ///

#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#define MAX 26

using std::string;
typedef struct node
{
	struct node *next[MAX];
	int num;
}Node;

class Trie
{
public:
	Trie()
	:root(new Node)
	{
		for(int i = 0; i < MAX; ++i)
		{
			root->next[i] = NULL;
		}
		root->num = 0;
	}

	void read(const string &filename);

	void list(const string &filename);

private:
	Node *root;
};

#endif
