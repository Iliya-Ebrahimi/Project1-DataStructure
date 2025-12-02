#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cctype>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

// Normalizer --> Correct user input
string normalizer(string expr) {
    auto isSign = [](char c) {
        return ( c == '+' || c == '-');
    };
    auto isMul = [] (char c){
        return (c == '*' || c == '/' || c == '^');
    };
    string out = "";
    string ans = "";

    // this part removes every extra operands in a cluster of '+'s and '-'s
    for(int i = 0; i < expr.size();) {
        if(isSign(expr[i])) {
            int j = i;
            while(j < expr.size() && isSign(expr[j])) j++;

            bool bol = false;
            int p = out.size() - 1;

            while(p >= 0 && out[p] == ' ') p--;

            if(p < 0 || out[p] == '(') bol = true;

            int c = 0;
            for(int k = i; k < j; k++)
                if(expr[k] == '-') c++;

            if(bol) {
                if(c%2==1) out.push_back('-');
            } 
            else {
                if(c%2==1) out.push_back('-');
                else out.push_back('+');
            }

            i = j;
        }
        else {
            out.push_back(expr[i]);
            i++;
        }
    }
    
    // this part removes every spaces in the input " "
    for (int i = 0;i < out.size(); i++){
        if (out[i] != ' ')
            ans += out[i];
    }
    
    out = ans;
    ans = "";

    // this part adds '*' behind '(' that do not have an operand behind them and after ')' that doesn't have an operand after them
    for (int i = 0;i < out.size();i++){
        
        if (out[i] == '('){
            if (i > 0 && !isSign(out[i-1]) && !isMul(out[i-1]) && out[i-1] != '(' && out[i-1] != ')')
                ans += '*';
            ans += '(';
        }

        else if (out[i] == ')' && i != out.size()-1){
            ans += ')';
            if (!isSign(out[i+1]) && !isMul(out[i+1]) && out[i+1] != ')')
                ans += '*';
        }

        else{
            ans += out[i];
        }
    }

    return ans;
}

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
        else if (isalpha(c)) { // var
            token = "";
            while (i < expr.size() && (isalnum(expr[i]) || expr[i] == '_')) {
                token += expr[i++];
            }
            --i;
            tokens.push_back(token);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '√') { // operand
            tokens.push_back(string(1, c));
        }
        else {
            throw runtime_error("Invalid character: " + string(1, c)); // error for invalid char like # @
        }
    }
    tokens.push_back(")");
    return tokens; // return a vector for use in tree  
}

//////////////// Functions for build tree /////////////////

// function for: "This token is operator?" 
bool isOperator (const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "√");
}

// Prioritizing operators
int prioritizing_operators (const string& s) {
    if (s == "+" || s == "-") return 1;
    if (s == "*" || s == "/") return 2;
    if (s == "^") return 3;
    return 0;
}

// Right-effect operator detection
bool right_operator_effect (const string& s) {
    return (s == "^" || s == "√");
}

// throw an error if the number under a sqrt is negatave !( does not work if the answer under it is negative --> √5-6 )!
void NegativeSqrt(string s){
    for (int i = 0; i< s.size()-1;i++){
        if (s[i] == '√' and s[i+1] == '-'){
            throw runtime_error("No negative sqrts");
        }
    }
}


// Tree Nodes
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& v) : value(v), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};


TreeNode* parser_add_sub (const vector<string>& tokens, int& index){
    // parser add Or sub and numbers of tokens
}

TreeNode* parser_mult_div (const vector<string>& tokens, int& index){
    // parser mult Or div and numbers of tokens
}

TreeNode* parser_power_Radikal (const vector<string>& tokens, int& index){
    // parser power Or Radikal and number of tokens
}

TreeNode* var_OR_bracket (const vector<string>& tokens, int& index) {
    string tok = tokens[index];
    if (isdigit(tok[0])) {
        // ...
    }
    else if (isalpha(tok[0])) {
        // ...
    }
    else if (tok == "(") {
        // ...
    }
    else {
        // for operators...
    }
}

TreeNode* build_tree (const vector<string>& tokens, int& index) {
    int index = 0;
    TreeNode* root = var_OR_bracket(tokens, index);
    if (index != tokens.size()) {
        throw runtime_error("Unexpected token after parsing expression");
    }
    return root;
}


int main(){
    string user_input;
    getline(cin, user_input);
    user_input = normalizer(user_input);
    vector<string>tokens = tokenize(user_input);
    cout << user_input << endl;
    for (int i = 0; i < tokens.size(); i++) cout << tokens[i] << " ";
}
