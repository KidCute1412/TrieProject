#include "Trie.h"
#include "InputData.h"

using namespace std;

void GetKeyWord(char *&p, int &n);
void findKeyWord(TrieNode *root, char *p, int n);

void checkKeyword(TrieNode* root, char *p, int n, bool *isUsed, int i, int cnt, string *word, string tmp);