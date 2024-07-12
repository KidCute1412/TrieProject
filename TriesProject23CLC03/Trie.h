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

	// Search a key in the trie
	void searchKey(string& word);

	// Find key with same prefix
	void searchKeyWithPrefix(string &prefix);

	// Remove a key in the trie
	void removeKey(string& word);

	// Search all possible words that can be formed by at least 3 characters in the given string in the Trie
	vector<string> searchAllWords(const string& characters);

	// Free the memory of the Trie
	~Trie();
};

// This function helps to find all possible words that can be formed by at least 3 characters in the given string in the Trie
void findAllValidVocabs(TrieNode* node, string& currentWord, int* charCount, vector<string>& result);

// This help to function searchKeyWithPrefix
void searchPrefix(TrieNode* root, string prefix);

// This helps to function removeKey
bool hasNoChildren(TrieNode* node);
TrieNode* remove(TrieNode* root, string key, int level);

void printTrie(TrieNode* root, string word, ofstream& fout); // For checking correction of the Trie




