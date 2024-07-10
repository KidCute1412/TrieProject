#include "Trie.h"








TrieNode::TrieNode()
{

	data = '\0'; // '\0' is the null character
	// Initialize all children as nullptr
	wordEnd = false;
	for (int i = 0; i < 26; i++)
	{
		children[i] = nullptr;
	}
	
}
Trie::Trie()
{
	root = new TrieNode();
}
void Trie::insertKey(string& word)
{
	TrieNode* temp = root;
	int len = word.length();
	for (int i = 0; i < len; i++)
	{
		int idx = word[i] - 'a';
		if (temp->children[idx] == nullptr)
		{
			temp->children[idx] = new TrieNode();
			temp->children[idx]->data = word[i];
		}
		temp = temp->children[idx];
	}
	temp->wordEnd = true;
}



void printTrie(TrieNode* root, string word, ofstream& fout)
{
	if (!root)
	{
		return;
	}
	word += root->data;
	if (root->wordEnd)
	{
		fout << word << endl;
	}
	for (int i = 0; i < 26; i++)
	{
		printTrie(root->children[i], word, fout);
	}
}
Trie::~Trie()
{
	if (root == nullptr)
	{
		return;
	}
	queue<TrieNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TrieNode* temp = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			if (temp->children[i] != nullptr)
			{
				q.push(temp->children[i]);
			}
		}
		delete temp;
	}

}