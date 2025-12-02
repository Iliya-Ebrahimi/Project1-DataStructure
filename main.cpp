#include<bits/stdc++.h>
#include "helper.h"
using namespace std;

int main(){
    string user_input;
    getline(cin, user_input);
    user_input = normalizer(user_input);
    vector<string>tokens = tokenize(user_input);
    cout << user_input << endl;
    for (int i = 0; i < tokens.size(); i++) cout << tokens[i] << " ";
}
