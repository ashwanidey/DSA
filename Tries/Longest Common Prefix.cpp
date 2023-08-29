// Approach 1 Brute force
string longestCommonPrefix(vector<string> &arr, int n)
{   string first = arr[0];
    string ans = "";
    
    for(int j = 0;j < first.length();j++){
        bool equal = true;
        for(int i = 1;i<n;i++){
            if(first[j] != arr[i][j]){
                equal = false;
                break;
            }    
        }
        if(equal) ans += first[j];
        else break;
    }
    return ans;
}

// Will give TLE using Tries
#include <bits/stdc++.h>

class Node{
    public:
        char data;
        Node* children[26];
        bool isTerminal;
    public:
        Node(){
            data = '#';
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        } 
        Node(char val){
            data = val;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie: public Node {
    public: 
        Node* root;
    public:
        Trie(){
            root = NULL;
        }
        Trie(Node* node){
            root = node;
        }
        void insert(string val){
            if(root == NULL){
                root = new Node();
            }
            Node* curr = root;
            int n = val.size();
            for(int i = 0; i < n; i++){
                if(curr->children[val[i] - 'a'] == NULL){
                    curr->children[val[i] - 'a'] = new Node(val[i]);
                }
                curr = curr->children[val[i] - 'a'];
            }
            curr->isTerminal = true;
        }
        string lcp(int refMinSize){
            // Normal Logic: Util Diverge 
            Node* curr = root;
            string ans;
            for(int i = 0; i <= refMinSize; i++){
                if(i != 0)
                    ans.push_back(curr->data);
                int count = 0;
                Node* next = NULL;
                for(int j = 0; j < 26; j++){
                    if(curr->children[j] != NULL){
                        count++;
                        next = curr->children[j];
                    }
                }
                if(count != 1) return ans;
                
                curr = next;
            }
            return ans;

        }
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    // Approach Using Trie Data Structure
    // Using a refference string
    Trie ds;
    int refMinSize = INT_MAX;
    for(string i : arr){
        ds.insert(i);
        int m = i.size();
        refMinSize = min(refMinSize, m);
    }

    return ds.lcp(refMinSize);
}
