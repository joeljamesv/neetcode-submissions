class PrefixTree {
   public:
    struct Trie {
        std::array<Trie*, 26> chars;
        bool isEnd;
    };
    Trie* head;
    PrefixTree() {
        head = new Trie();
        for (int i = 0; i < 26; i++) {
            head->chars[i] = NULL;
        }
        head->isEnd = false;
    };

    void insert(string word) {
        Trie* tmpNode = head;
        for (int i = 0; i < word.size(); i++) {
            if (tmpNode->chars[word[i] - 97] == NULL) {
                Trie* node = new Trie();
                for (int i = 0; i < 26; i++) {
                    node->chars[i] = NULL;
                }
                tmpNode->chars[word[i] - 97] = node;
                tmpNode = node;
            } else {
                tmpNode = tmpNode->chars[word[i] - 97];
            }
        }
        tmpNode->isEnd = true;
    }

    bool search(string word) {
        Trie* tmpNode = head;
        for (int i = 0; i < word.size(); i++) {
            if (tmpNode->chars[word[i] - 97] == NULL) {
                return false;
            } else {
                tmpNode = tmpNode->chars[word[i] - 97];
            }
        }
        if (tmpNode->isEnd == true)
            return true;
        else
            return false;
    }

    bool startsWith(string prefix) {
        Trie* tmpNode = head;
        for (int i = 0; i < prefix.size(); i++) {
            if (tmpNode->chars[prefix[i] - 97] == NULL) {
                return false;
            } else {
                tmpNode = tmpNode->chars[prefix[i] - 97];
            }
        }
        return true;
    }
};
