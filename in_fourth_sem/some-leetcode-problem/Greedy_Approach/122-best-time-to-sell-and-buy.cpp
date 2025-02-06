#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices);
void printVector(vector<int>&num);
vector<int> take_input_vector();
int main(){
    cout << "Enter the day wise prices of stock"<< endl << endl;
    vector<int>prices = take_input_vector();
    cout << "the prices vector is " << endl << endl;
    printVector(prices);
    int profit = maxProfit(prices);
    cout << "The max profit is " << profit << endl << endl;
    
}

int maxProfit(vector<int>& prices) {
        int think_to_buy = -1;
        int buy = -1;
        int think_to_sell = -1;
        int sell = -1;
        int profit = 0;
        int i = 0;

        // for checking 
        vector<int> tb,b,s,ts;
        while(i < prices.size()-1){
            if(think_to_buy == -1 || buy == -1){
                think_to_buy = prices[i];
                tb.push_back(think_to_buy);
            }
            if((think_to_buy < prices[i + 1]) && buy == -1 ){
                buy = think_to_buy;
                // think_to_buy = -1;
                b.push_back(buy);
                think_to_sell = -1;
            }
            if((buy != -1) && (think_to_sell == -1 || think_to_sell < prices[i]) ){
                think_to_sell = prices[i];
                ts.push_back(think_to_sell);
            }
            if(buy != -1 && think_to_sell > prices[i+1]){
                sell = think_to_sell;
                profit =profit + sell - buy;
                buy = -1;
                s.push_back(sell);
            }
            i++;
        }
        // At last Day
        if(buy != -1){
            sell = prices[i];
            profit = profit +  sell - buy;
            buy = -1;
            s.push_back(sell);
        }


        // Printing all check vector
        cout << endl << endl;
        cout << "The think to buy vector " << endl;
        printVector(tb);
        cout << "The buy vector" << endl;
        printVector(b);
        cout << "The think to sell vector" << endl;
        printVector(ts);
        cout << "The sell Vector "<< endl;
        printVector(s);
        return profit;
        
}

// function to take vector as input
vector<int> take_input_vector(){
    vector<int > num;
    int inp;
    while(true){
        cout << "Enter the number to insert into vector otherwise enter -1" << endl;
        cin >> inp ;
        if(inp == -1){
            break;
        }
        num.push_back(inp);
    }
    return num;
}


// function to print vector
void printVector(vector<int>&num){
    for(const int&i :  num){
        cout << i << "\t";
    }
    cout << endl << endl;
}