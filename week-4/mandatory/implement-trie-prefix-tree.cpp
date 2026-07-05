struct Node {
    Node** alpha;
    bool isEnd;
    Node() {
        alpha = new Node*[26];
        for(int i=0; i<26; i++) {
            alpha[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    Node* root = new Node();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        int sz = word.size();
        word+= "#";
        Node* curr = root;
        int i = 0;
        char ch = word[i];
        while(i<sz&& curr->alpha[ch-'a'] != nullptr) {
            // ch = word[i++];
            curr = curr->alpha[ch-'a'];
            ch = word[++i];
        }

        while(i<sz) {
            // ch = word[i++];
            curr->alpha[ch-'a'] = new Node();
            curr = curr->alpha[ch-'a'];

            ch = word[++i];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        int sz = word.size();
        word+="#";
        
        int i=0;
        char ch = word[i];
        Node* curr = root;
        while(i<sz && curr->alpha[ch-'a'] != nullptr) {
            // ch = word[i++];
            curr = curr->alpha[ch-'a'];
            ch = word[++i];
        }

        if(i==sz && curr->isEnd == true) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int sz = prefix.size();
        prefix+="#";
        int i=0;
        char ch = prefix[i];
        Node* curr = root;
        while(i<sz && curr->alpha[ch-'a'] != nullptr) {
            // ch = prefix[i++];
            curr = curr->alpha[ch-'a'];
            ch = prefix[++i];
        }
        if(i==sz) {
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */