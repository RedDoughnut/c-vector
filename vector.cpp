#include <vector>
#include <iostream>
using namespace std;

void v_print(vector<int> *v) {
    for(auto i : *v) {
        cout << i << ' '; 
    }
}

int main(){
    vector<int> *v = new vector<int>;

    v->reserve(4);
    
    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    v->push_back(4);
    v->at(0) = 20;
    v->pop_back();
    v_print(v); // Should print: 20 2 3
    
    v->clear();
    v->push_back(10);
    v->push_back(20);
    v_print(v); // Should print: 10 20

    delete v;
}
