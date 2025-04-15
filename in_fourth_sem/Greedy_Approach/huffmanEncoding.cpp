#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Huffman{
    string message;
    public:
        Huffman(string message){
            this->message = message;
        }
        void encode(){
            unordered_map<char, int>freq = freqTable();

            // printing the frequency table
            for(auto pair : freq){
                cout << pair.first << "\t" << pair.second << endl;
            }
        }

    private:
        // to count the frequencies of the character in the table
        unordered_map<char, int> freqTable(){
            unordered_map<char, int> freq;
            for(char ch : message){
                freq[ch]++;
            }
            return freq;
        }

        
};

int main(){
    string messages = "Pradeep Kumar Tiwari";
    Huffman h(messages);
    h.encode();
}