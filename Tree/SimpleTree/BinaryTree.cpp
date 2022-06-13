#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class tree
{
    typedef struct bin
    {
        int data;
        struct bin *left;
        struct bin *right;
    }node;
    public:
    node *root, *temp;
    tree();
    void create(vector <int>);
    void insert(node *, node *);
    void prettyPrintTree(node* node1, string prefix = "", bool isLeft = true);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
};

tree:: tree()
{
    root = NULL;
}

void tree::create(vector<int> items)
{
    if(items.size() == 0)
        return;
    queue<node*> NodeQ;
    temp = new node;
    temp->data = items[0];
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
    NodeQ.push(root);
    
    for(int i = 1; i<items.size();i++)
    {
        //add left node
        node *lnode = NodeQ.front();
        NodeQ.pop(); //remove node
        if(i>=items.size())
        {
            break;
        }
        temp = new node;
        temp->data = items[i++];
        temp->left = NULL;
        temp->right = NULL;
        lnode->left = temp;
        NodeQ.push(temp);
        
        //add right node
        if(i>=items.size())
        {
            break;
        }
        temp = new node;
        temp->data = items[i];
        temp->left = NULL;
        temp->right = NULL;
        lnode->right = temp;
        NodeQ.push(temp);
    }
}

void tree::insert(node * root, node *temp)
{
    string ch;
    getline(cin,ch);
    if(ch == "r" || ch == "R")
    {
        if(root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
    else
    {
        if(root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
}

void tree::inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        std::cout<<" "<<root->data;
        inorder(root->right);
    }
}



void tree::preorder(node *root)
{
    if(root != NULL)
    {
        std::cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout<<" "<<root->data;
    }
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}
void tree::prettyPrintTree(node* node1, string prefix, bool isLeft) {
    if (node1 == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node1->right) {
        prettyPrintTree(node1->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node1->data) + "\n";

    if (node1->left) {
        prettyPrintTree(node1->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

int main()
{
    tree obj;
    vector<int> items;
    string line;
    getline(cin, line);
    items = stringToIntegerVector(line);        
    obj.create(items);
    obj.prettyPrintTree(obj.root);
    std::cout<<endl<<"Inorder traversal : "<<endl;
    obj.inorder(obj.root);
    std::cout<<endl<<"Preorder traversal : "<<endl;
    obj.preorder(obj.root);
    std::cout<<endl<<"Postorder traversal : "<<endl;
    obj.postorder(obj.root);
    return 0;
}