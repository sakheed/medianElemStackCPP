#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> low;
priority_queue<int, vector<int>, greater<int> > high; 
int median = 0;

int insert(int x){
    if(high.size() > low.size()){
        if(x > median){
            low.push(high.top());
            high.pop();
            high.push(x);
        }
        else low.push(x);
        median = low.top();
    }
    else if(high.size() < low.size()){
        if(x < median){
            high.push(low.top());
            low.pop();
            low.push(x);
        }
        else high.push(x);
        median = low.top();
    }
    else{
        if(x < median){
            low.push(x);
            median = low.top();
        }
        else{
            high.push(x);
            median = high.top();
        }
    }
}

int main(){
    int input = -1;
    while(input != 2){
        cout << "Choose your desired action:" << endl;
        cout << "1: Insert an element" << endl;
        cout << "2: Exit the program" << endl;
        cin >> input;
        switch(input){
            case 1:
                int x;
                cout << "Enter your desired integer element:\n";
                cin >> x; 
                insert(x);
                cout << "The median element is: " << median << endl;
                break;
            case 2:
                cout << "Exiting program. \n";
                return 0;


        }
    }
}