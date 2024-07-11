#pragma once
#include<iostream>
#include<string>
#include <queue>
#include<fstream>
using namespace std;



struct TrieNode
{
	char data;
	TrieNode* children[26];
	bool wordEnd;
	// Constructor
	TrieNode();

};
struct Trie {
	TrieNode* root = nullptr;
	Trie();
	// Insert a key into the trie
	void insertKey(string& word);

	//find key with same prefix
	void keyWithPrefix(TrieNode* root, string prefix);

	// Free the memory of the Trie
	~Trie();
};
void printTrie(TrieNode* root, string word, ofstream& fout); // For checking correction of the Trie




