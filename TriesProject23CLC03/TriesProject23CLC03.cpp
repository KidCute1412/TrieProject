#include"Trie.h"
#include "InputData.h"


int main()
{
	Trie trie;
	string fileName = "Dic.txt";

	// Build trie from Dic.txt file
	buildTrieFromFile(trie, fileName); // from InputData.cpp

	// Get key words from user
	string data;
	getKeyWord(data); // from InputData.cpp

	// Search all possible words from the key words
	vector<string> allPossibleVocabs = trie.searchAllWords(data); // from Trie.h

	// Print all possible words
	cout << allPossibleVocabs.size() << endl;
	for (int i = 0; i < allPossibleVocabs.size(); i++)
	{
		cout << allPossibleVocabs[i] << endl;
	}
	return 0;
}
