#include"Trie.h"
#include "InputData.h"
#include "SearchKeyword.h"

int main()
{
	Trie trie;
	string fileName = "Dic.txt";
	ofstream fout;
	fout.open("output.txt");
	buildTrieFromFile(trie, fileName);
	printTrie(trie.root->children[0], "", fout);
	char *p; int n;
	GetKeyWord(p, n);
	findKeyWord(trie.root->children[0], p, n);
	fout.close();
	system("pause");
	return 0;
}
