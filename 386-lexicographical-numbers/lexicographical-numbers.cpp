class TrieNode{
    public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        children.resize(10);
        isTerminal = false;

        for(int i=0;i<10;i++){
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    void insert_func(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }
            char ch = word[0];
            int index = ch - '0';
            TrieNode* child;

            if(root->children[index] == NULL){
                //absent
                child = new TrieNode(ch);
                root->children[index] = child; 
            }
            else{
                //present
                child = root->children[index];
            }
            insert_func(child,word.substr(1));
    }
    void search(TrieNode* root,vector<int> &ans,string s){
        if(root->isTerminal == true){
            int d = stoi(s);
            ans.push_back(d);
            
        }
        for(int i=0;i<root->children.size();i++){
            if(root->children[i] != NULL){
                search(root->children[i],ans,s+root->children[i]->data);
            }
        }
    }
    vector<int> lexicalOrder(int n) {

        //my own code

        TrieNode* root = new TrieNode('\0');
        
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            insert_func(root,str);
        }

        vector<int> ans;
        search(root,ans,"");
        return ans;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
