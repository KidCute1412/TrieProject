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



void getKeyWord(string& data)
{
	cout << "Enter key words: ";
	getline(cin, data);
	int pos = 0;
	int len = data.length();
	for (int i = 0; i < len; i++)
	{
		if (data[i] != ' ')
		{
			data[pos++] = data[i];

		}
	}
	data = data.substr(0, pos);
	//cout << data << endl;
}