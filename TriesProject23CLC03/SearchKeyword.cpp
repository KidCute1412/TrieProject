#include "Trie.h"
#include "SearchKeyword.h"
#include <cstring>
#include <string>
using namespace std;

void GetKeyWord(char *&p, int &n){
    string tmp;
    getline(cin, tmp);
    n = 0;
    int len = tmp.length();
    for (int i = 0; i < len; i++){
        if (tmp[i] != ' '){
            n++;
        }
    }
    p = new char[n];
    int j = 0;
    for (int i = 0; i < len; i++){
        if (tmp[i] != ' '){
            p[j] = tmp[i];
            j++;
        }
    }
}


void findKeyWord(TrieNode *root, char *p, int n){
    bool *isUsed = new bool[n];
    for (int i = 0; i < n; i++){
        isUsed[i] = false;
    }
    ofstream fout;
    fout.open("keywordfound.txt");
    int cnt = 0;
    string *word = new string[100000], tmp = "";
    checkKeyword(root, p, n, isUsed, 0, cnt, word, tmp);
    for (int i = 0; i < cnt; i++){
        fout << word[i] << endl;
        cout << word[i] << endl;
    }
    fout.close();
}

void checkKeyword(TrieNode* root, char *p, int n, bool *isUsed, int i, int cnt, string *word, string tmp){
    for(int i = 0; i < n; i++){
        if(isUsed[i] == false)
        {
            isUsed[i] = true;
            int idx = p[i] - 'a';
            TrieNode* temp = root->children[idx];
            if(temp == nullptr)
            {
                return;
            }
            tmp += temp->data;
            if(temp->wordEnd)
            {
                word[cnt] = tmp;
                cnt++;
            }
            if(i == n) return;

            checkKeyword(temp, p, n, isUsed, i + 1, cnt, word, tmp);
            tmp.pop_back();
            isUsed[i] = false;
        }
    }
}