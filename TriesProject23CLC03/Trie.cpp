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

// Function for inserting a key into the trie
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



// Function for searching a key in the trie
void Trie::searchKey(string& word)
{
	TrieNode* temp = root;
	int len = word.length();
	for (int i = 0; i < len; i++)
	{
		int idx = word[i] - 'a';
		if (temp->children[idx] == nullptr)
		{
			cout << "Key not found" << endl;
			return;
		}
		temp = temp->children[idx];
	}
	if (temp->wordEnd)
	{
		cout << "Key found" << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}
}


// Function for finding all possible words with the same prefix
void searchPrefix(TrieNode *root, string prefix)
{
    if (!root)
    {
        return;
    }
    if (root->wordEnd)
    {
        cout << prefix << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != nullptr)
        {
            searchPrefix(root->children[i], prefix + char('a' + i));
        }
    }
}



void Trie::searchKeyWithPrefix(string& prefix)
{
	TrieNode* temp = root;
	// Normalize the prefix
	int pos = 0;
	for (int i = 0; i < prefix.length(); i++)
	{
		if (prefix[i] != ' ')
		{
			prefix[pos++] = prefix[i];
		}
	}
	// Start searching the prefix
	prefix = prefix.substr(0, pos);
	int len = prefix.length();
	for (int i = 0; i < len; i++)
	{
		int idx = prefix[i] - 'a';
		if (temp->children[idx] == nullptr)
		{
			cout << "Prefix not found" << endl;
			return;
		}
		temp = temp->children[idx];
	}
	searchPrefix(temp, prefix);
}








// Function for removing a key in the trie
bool hasNoChildren(TrieNode* node)
{
	for (int i = 0; i < 26; i++)
	{
		if (node->children[i])
		{
			return false;
		}
	}
	return true;
}


TrieNode* remove(TrieNode* root, string key, int level)
{
	if (!root)
	{
		return nullptr;
	}
	if (level == key.length())
	{
		if (root->wordEnd)
		{
			root->wordEnd = false;
		}
		if (hasNoChildren(root))
		{
			delete root;
			return nullptr;
		}
		return root;
	}
	int idx = key[level] - 'a';
	root->children[idx] = remove(root->children[idx], key, level + 1);
	if (hasNoChildren(root) && !root->wordEnd)
	{
		delete root;
		return nullptr;
	}
	return root;
}

void Trie::removeKey(string& word)
{
	// Normalize the word
	int pos = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] != ' ')
		{
			word[pos++] = word[i];
		}
	}
	word = word.substr(0, pos);
	if (word.length() == 0)
	{
		return;
	}
	// Start remove the word
	remove(root, word, 0);
}

// Function for searching all possible words that can be formed by at least 3 characters in the given string in the Trie
vector<string> Trie::searchAllWords(const string& characters) {
	int charCount[26] = { 0 };
	for (char c : characters) {
		charCount[c - 'a']++;
	}

	vector<string> result;
	string currentWord = "";
	findAllValidVocabs(root, currentWord, charCount, result);
	return result;
}

void findAllValidVocabs(TrieNode* node, string& currentWord, int* charCount, vector<string>& result) {
	if (node->wordEnd && currentWord.length() >= 3) {
		result.push_back(currentWord);
	}

	for (int i = 0; i < 26; i++) {
		if (node->children[i] != nullptr && charCount[i] > 0) {
			charCount[i]--;
			currentWord.push_back('a' + i);
			findAllValidVocabs(node->children[i], currentWord, charCount, result);
			currentWord.pop_back();
			charCount[i]++;
		}
	}
}


// Function for printing the Trie
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
// Destructor
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
