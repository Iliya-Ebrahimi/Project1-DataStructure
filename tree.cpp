// #include<bits/stdc++.h>
// using namespace std;

// // Tree Nodes
// // struct TreeNode {
// //     string value;
// //     TreeNode* left;
// //     TreeNode* right;
// //     TreeNode* next = NULL;
// //     TreeNode(const string& v) : value(v), left(NULL), right(NULL) {}
// //     TreeNode() : left(NULL) , right(NULL){}
// //     ~TreeNode() {
// //         delete left;
// //         delete right;
// //     }
// // };

// struct Stack
// {
//     private:
//     TreeNode* head = NULL;
//     public:
//     void push(TreeNode* x){
//         if(head == NULL){
//             x = head;
//         }
//         else{
//             x->next = head;
//             head = x;
//         }
//     }

//     TreeNode* pop(){
//         TreeNode* p  = head;
//         head = p->next;
//         return p;
//     }
// };

// struct Expression_tree{
//     void postorder(TreeNode* x){

//     }
// };