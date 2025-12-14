#include<bits/stdc++.h>
using namespace std;

// Tokenizer
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    string token;
    tokens.push_back("(");
    for (int i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (isdigit(c)) { // integer float
            token = "";
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                token += expr[i++];
            }
            --i;
            tokens.push_back(token);
        }
        // max(2, 3) --> max 2 3
        else if (isalpha(c)) { // var
            token = "";
            while (i < expr.size() && (isalnum(expr[i]) || expr[i] == '_')) {
                token += expr[i++];
            }
            --i;
            tokens.push_back(token);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '@') { // operand
            tokens.push_back(string(1, c));
        }
        else {
            throw runtime_error("Invalid character: " + string(1, c)); // error for invalid char like # @
        }
    }
    tokens.push_back(")");
    return tokens; // return a vector for use in tree  
}