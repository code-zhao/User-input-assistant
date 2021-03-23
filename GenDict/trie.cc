 ///
 /// @file    trie.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-17 14:36:08
 ///

#include "trie.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::endl;

Node* CreateNode()
{
	Node *root = new Node();
	for(int i = 0; i < MAX; ++i)
		root->next[i] = NULL;
	root->num = 0;
	return root;
}

void Trie::read(const string &filename)
{
	ifstream ifs(filename);
	string read_str;
	while(ifs >> read_str)
	{
		string word;
		for(auto &i : read_str)
		{
			if(!isalpha(i))
				continue;
			i = tolower(i);
			word += i;
		}
		if(word.size() < 2)
		{
			continue;
		}
		Node *t, *p = root;
		for(auto &c : word)
		{
			int idx = c - 'a';
			if(p->next[idx] == NULL)
			{
				t = CreateNode();
				p->next[idx] = t;
				p = p->next[idx];
			}
			else
			{
				p = p->next[idx];
			}
		}
		++p->num;
	}
	ifs.close();
}

void PreOrderList(Node *head, string pre, const string &filename)
{
	if(head == nullptr)
	{
		return;
	}
	ofstream ofs(filename, ofstream::app);
	if(head->num != 0)
	{
		ofs << pre << " " << head->num << endl;
	}
	string cur = pre;
	//Node *t;
	for(int i=0; i < MAX; ++i)
	{
		if(head->next[i] != NULL)
		{
	//		t = head->next[i];
			string nextcur = cur + (char)(i + 'a');
			PreOrderList(head->next[i], nextcur, filename);
		}
	}
	ofs.close();
}

void Trie::list(const string &filename)
{
	string sin;
	PreOrderList(root, sin, filename);
}
