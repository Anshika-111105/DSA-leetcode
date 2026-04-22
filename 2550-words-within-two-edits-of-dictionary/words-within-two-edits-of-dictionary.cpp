struct TrieNode {
    TrieNode* links[26]; // 'a'-'z'
    bool isEnd=0;
};
static constexpr int N=10000;  
static TrieNode pool[N];
static int ptr=0;   // node counter

class Trie {
    TrieNode* newNode() {
        TrieNode* node=&pool[ptr++];
        memset(node->links, 0, sizeof(node->links));
        node->isEnd=0;
        return node;
    }
public:
    TrieNode* root;
    Trie(){
        ptr=0; // reset the counter
        root=newNode();
    }
    void insert(const string& word) {
        TrieNode* Node=root;
        for(char c: word) {
            int i=c-'a';
            if(Node->links[i]==NULL)
                Node->links[i]=newNode();
            Node=Node->links[i];
        }
        Node->isEnd=1;
    }
    // crucial method for this problem, it takes O(wz^2 26^2) time
    bool search(const string& word, int wz, int idx, TrieNode* Node, int diff)
    {
        if (diff>2) return 0;
        if (idx==wz) return Node->isEnd;
        for(int i=0; i<26; i++){
            if (Node->links[i])
                if (search(word, wz, idx+1, Node->links[i], diff+1-(word[idx]-'a'==i))) return 1;
        }
        return 0;
    }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        ptr=0;
        Trie trie;
        for(auto& s: dictionary) trie.insert(s);
        const int qz=queries[0].size();
        vector<string> ans;
        for(auto& q: queries){
            TrieNode* Node=trie.root;
            if (trie.search(q, qz, 0, Node,0))
                ans.push_back(q);
        }
        return ans;
    }
};