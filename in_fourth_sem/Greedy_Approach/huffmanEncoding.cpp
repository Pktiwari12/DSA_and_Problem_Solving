#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>
#include<queue>

using namespace std;

struct Node{
    char ch;
    int freq;
    Node * left;
    Node * right;
};


Node* createNode(char ch, int freq, Node* left, Node* right){
    Node* newNode = new Node();
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

bool cmp(Node * n1 , Node *n2){
    return n1->freq > n2->freq;
}

class Huffman{
    public:
        void encode(string message){
            unordered_map<char, int>freq_table = freqTable(message);

            // // printing the frequency table

            // for(auto pair : freq_table){
            //     cout << pair.first << "\t" << pair.second << endl;
            // }
            
            // making the character as a leafnode of huffman tree
            priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> pq(cmp);
            for(auto pair : freq_table){
                // leaf node
                pq.push(createNode(pair.first, pair.second, NULL, NULL));
            }
            // cout << pq.top()->freq;
            // meargin the nodes According to  optimal mearge pattern 
            while(pq.size() > 1){
                Node* l_child = pq.top();
                pq.pop();
                Node* r_child = pq.top();
                pq.pop();
                // make a parent node and push into priority queue
                pq.push(createNode('$', l_child->freq + r_child->freq, l_child, r_child));
            }
            // Now priority queue has one node which is called root_node
            Node * root = pq.top();
            pq.pop();
            // cout << root->freq;
            unordered_map<char, string> hf_table;
            assignCode(root, "", hf_table);
            for(auto pair :hf_table){
                cout << pair.first << "\t" << pair.second << endl;
            }

            // cout << "\nTree Traversal preorder" << endl;
            // preOrder(root);
            // cout << "\n inorder" << endl;
            // inOrder(root);

            // Scan the string and replace with Huffman_code
            string encoded_str = "";
            for(char ch : message){
                encoded_str = encoded_str + hf_table[ch];
            }
            cout << "\n" << "Encoded message " << endl;
            cout << "\n\n" << encoded_str << endl << endl;
            cout << "\n" << "size of encoded message " << encoded_str.size() <<  endl;

        }

    private:
        // to count the frequencies of the character in the table
        unordered_map<char, int> freqTable(string message)
        {
            unordered_map<char, int> freq;
            for(char ch : message){
                freq[ch]++;
            }
            return freq;
        }

        void assignCode(Node* temp , string code, unordered_map<char, string>& hf_table){
            // if root is NULL
            if(temp == NULL){
                return;
            }
            // if leaf node is found
            if(temp->left == NULL && temp->right == NULL){
                hf_table[temp->ch] = code;
            }
            // Do in left 
            assignCode(temp->left, code + "0", hf_table);
            // backtrack and do in right
            assignCode(temp->right, code + "1", hf_table);
        }

        
};

int main(){
    string message = "BCCABBDDAECCBBAEDDCC";
    // string message = "Hello";
    Huffman h;
    h.encode(message);
}



// not very useful methods . this is just used for debugging the result
void inOrder(Node * root){
    if(root == nullptr){
        return ;

    }
    inOrder(root->left);
    cout << root->freq<< "\t";
    inOrder(root->right);
}

void preOrder(Node * root){
    if(root == nullptr){
        return ;

    }
    cout << root->freq<< "\t";
    preOrder(root->left);
    preOrder(root->right);
}
