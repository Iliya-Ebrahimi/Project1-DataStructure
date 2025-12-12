#include<bits/stdc++.h>
#include "buildTree.cpp"
using namespace std;

double calculate_tree(TreeNode* node) {
    if(!node->right && !node->left) { return stod(node->value); }
    
    double x = calculate_tree(node -> right); //right tree ans
    double y = calculate_tree (node -> left); //left tree ans

    //calculate the ans from right and left
    if(node->value == "+") return x + y;
    if(node->value == "-") return y - x;
    if(node->value == "*") return x * y;
    if(node->value == "/") {
        if(x == 0) { throw runtime_error("Cannot devide to zero"); }
        
        else { return y / x; }
    }
    if(node->value == "^") return pow(y, x);
    if(node->value == "√") return pow(y, 0.5);
}