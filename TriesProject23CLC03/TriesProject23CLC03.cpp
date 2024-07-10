#include"Trie.h"
#include "InputData.h"







int main()
{
	Trie trie;
	string fileName = "Dic.txt";
	ofstream fout;
	fout.open("output.txt");
	buildTrieFromFile(trie, fileName);
	printTrie(trie.root->children[0], "", fout);
	fout.close();
	return 0;
}