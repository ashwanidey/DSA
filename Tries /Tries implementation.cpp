
 class TrieNode{
     public:
     char data;
     TrieNode* children[26];
     bool isTerminal;

     TrieNode(char d){
         data= d;
         for(int i = 0;i<26;i++){
             children[i] = NULL;
         }
         isTerminal = false;
     }
 };


class Trie {

public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;

        }
        TrieNode* child;
        char ch = word[0];
        if(root->children[ch - 'a'] != NULL){
            child = root->children[ch - 'a'];
        }
        else{
            child = new TrieNode(ch);
            root->children[ch - 'a'] = child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0) return root->isTerminal;

        char ch = word[0];
        TrieNode* child;
        if(root->children[ch - 'a'] == NULL) return false;
        else{
            child = root->children[ch-'a'];
        }
        return searchUtil(child,word.substr(1));

    }

    bool search(string word) {
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool pre(TrieNode* root,string prefix){
        if(prefix.length() == 0) return true;
        int index = prefix[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) child = root->children[index];
        else{
            return false;
        }
        return pre(child,prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return pre(root,prefix);
    }
};
