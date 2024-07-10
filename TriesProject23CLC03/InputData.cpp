#include "InputData.h"








void buildTrieFromFile(Trie& trie, string& fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		fin.close();
		return;
	}
	string word;
	while (getline(fin, word))
	{
		trie.insertKey(word);
	}
	fin.close();
}