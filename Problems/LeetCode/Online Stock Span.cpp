// Write a class StockSpanner which collects daily price quotes for some stock,
//  and returns the span of that stock's price for the current day.

// The span of the stock's price today is defined as
//  the maximum number of consecutive days (starting from today and going backwards)
//  for which the price of the stock was less than or equal to today's price.
#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<int> stock;
    stack<int> count;
    StockSpanner() {
    }
    int next(int price) {
        int returnValue=1;
        while(!stock.empty() && stock.top()<=price){
            returnValue+=count.top();
            stock.pop();
            count.pop();
        }
        stock.push(price);
        count.push(returnValue);
        return returnValue;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */