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
    node *tree1, *tree2, *tree3;
    void create(vector<int> items);
    void create1(vector<int> items);
    void create2(vector<int> items);
    void prettyPrintTree(node* node1, string prefix = "", bool isLeft = true);
    tree();
    void inorder(node *root);
    void inorderRec(node *);
    int getHeightRec(node *);
    int getHeightNonRec(node *);
    void insertNode(node *root, int data);
    void deleteNode(node* , int);
    void deleteDeepNode(node *root, node *tmp);
    bool checkLevel(node*, int, int *);
    bool check(node*);
    
    bin* mergeSumTrees(node *t1, node *t2)
    {
        if(t1 == NULL)
        {
            return t2;
        }
        if(t2 == NULL)
        {
            return t1;
        }
    
        //add both node
        t1->data += t2->data;
        t1->left = mergeSumTrees(t1->left, t2->left);
        t1->right = mergeSumTrees(t1->right, t2->right);
        return t1;
    }
};

tree::tree()
{
    root=NULL;
}

void tree::create(vector<int> items)
{
    if(items.empty())
    {
        cout<<"Empty data"<<endl;
        return;
    }
    queue<node*> NodeQ;
    temp = new node;
    temp->data = items[0];
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
    NodeQ.push(root);
    
    cout<<"Root Added"<<endl;
    for(int i = 1;i<items.size();i++)
    {
        node *node1 = NodeQ.front();
        NodeQ.pop(); //remove node from q
        if(i>= items.size())
        {
            break;
        }
        //Add left node
        temp = new node;
        temp->data = items[i++];
        temp->left = NULL;
        temp->right = NULL;
        node1->left = temp;
        NodeQ.push(temp);
        
        if(i>= items.size())
        {
            break;
        }
        //Add right node
        temp = new node;
        temp->data = items[i];
        temp->left = NULL;
        temp->right = NULL;
        node1->right = temp;
        NodeQ.push(temp);
    }
}

void tree::create1(vector<int> items)
{
    if(items.empty())
    {
        cout<<"Empty data"<<endl;
        return;
    }
    queue<node*> NodeQ;
    temp = new node;
    temp->data = items[0];
    temp->left = NULL;
    temp->right = NULL;
    tree1 = temp;
    NodeQ.push(tree1);
    
    cout<<"Root Added"<<endl;
    for(int i = 1;i<items.size();i++)
    {
        node *node1 = NodeQ.front();
        NodeQ.pop(); //remove node from q
        if(i>= items.size())
        {
            break;
        }
        //Add left node
        temp = new node;
        temp->data = items[i++];
        temp->left = NULL;
        temp->right = NULL;
        node1->left = temp;
        NodeQ.push(temp);
        
        if(i>= items.size())
        {
            break;
        }
        //Add right node
        temp = new node;
        temp->data = items[i];
        temp->left = NULL;
        temp->right = NULL;
        node1->right = temp;
        NodeQ.push(temp);
    }
}

void tree::create2(vector<int> items)
{
    if(items.empty())
    {
        cout<<"Empty data"<<endl;
        return;
    }
    queue<node*> NodeQ;
    temp = new node;
    temp->data = items[0];
    temp->left = NULL;
    temp->right = NULL;
    tree2 = temp;
    NodeQ.push(tree2);
    
    cout<<"Root Added"<<endl;
    for(int i = 1;i<items.size();i++)
    {
        node *node1 = NodeQ.front();
        NodeQ.pop(); //remove node from q
        if(i>= items.size())
        {
            break;
        }
        //Add left node
        temp = new node;
        temp->data = items[i++];
        temp->left = NULL;
        temp->right = NULL;
        node1->left = temp;
        NodeQ.push(temp);
        
        if(i>= items.size())
        {
            break;
        }
        //Add right node
        temp = new node;
        temp->data = items[i];
        temp->left = NULL;
        temp->right = NULL;
        node1->right = temp;
        NodeQ.push(temp);
    }
}

void tree::prettyPrintTree(node *node1, string prefix, bool isLeft)
{
    if(node1 == nullptr)
    {
        cout<<"Empty Tree";
        return;
    }
    if(node1->right)
    {
        prettyPrintTree(node1->right, prefix + (isLeft ? "│   " : "    "), false);
    }
    
    cout<<prefix + (isLeft ? "└── " : "┌── ") + to_string(node1->data) + "\n";
    
    if(node1->left)
    {
        prettyPrintTree(node1->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

void tree::inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}

int tree::getHeightRec(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = getHeightRec(root->left);
    int rh = getHeightRec(root->right);
    
    if (lh > rh)
    {
        return (lh+1);
    }
    else
    {
        return (rh+1);
    }
}

int tree :: getHeightNonRec(node *root)
{
    //Base case
    if (root == NULL)
        return 0;
    //create q
    queue<node *> NodeQ;
    int height = 0; // initialize q height to 0
    //add root to queue
    NodeQ.push(root);
    
    while (1)
    {
        //get size of q
        int nodeCount = NodeQ.size();
        
        if (nodeCount == 0)
        {
            return height;
        }
        //increment height
        height++;
        //remove node from front and add its child to queue
        while(nodeCount > 0)
        {
            temp = NodeQ.front();
            NodeQ.pop();
            if(temp->left != NULL)
            {
                NodeQ.push(temp->left);
            }
            if (temp->right != NULL)
            {
                NodeQ.push(temp->right);
            }
            nodeCount--;
        }
    }
}

void tree::insertNode(node *root, int data)
{
    if (root == NULL)
    {
        temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return;
    }
    
    queue<node*> NodeQ;
    NodeQ.push(root); //push root on q
    
    //do lvele order traversal
    while(NodeQ.size() != 0)
    {
        node * node1 = NodeQ.front();
        NodeQ.pop();
        
        if(node1->left == NULL)
        {
            //insert node here
            temp = new node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            node1->left = temp;
            return;
        }
        else
        {
            NodeQ.push(node1->left);
        }
        
        if(node1->right == NULL)
        {
            //Insert node here
            temp = new node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            node1->right = temp;
            return;
        }
        else
        {
            NodeQ.push(node1->right);
        }
    }
}

void tree::deleteNode(node *root, int key)
{
    if(root == NULL)
    {
        return;
    }
    //check if root node is to delete
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
        {
            // Delete root node
            root = NULL;
            return;
        }
        else
        {
            //No data to delete
            return;
        }
    }
    
    // Find deepest node(temp) to replace with deleted node(d_node)
    queue<node *> NodeQ;
    node *d_node;
    NodeQ.push(root);
    while(NodeQ.size()>0)
    {
        temp = NodeQ.front();
        NodeQ.pop();
        
        if(temp->data == key)
        {
            d_node = temp;
        }
        if(temp->left != NULL)
        {
            NodeQ.push(temp->left);
        }
        if(temp->right != NULL)
        {
            NodeQ.push(temp->right);
        }
    }
    
    if(d_node != NULL)
    {
        int x = temp->data;
        deleteDeepNode(root, temp);
        d_node->data = x;
    }
    
}

void tree::deleteDeepNode(node *root, node *tmp)
{
    queue<node*> NodeQ;
    NodeQ.push(root);
    
    while(NodeQ.size()>0)
    {
        temp = NodeQ.front();
        NodeQ.pop();
        
        if(temp == tmp)
        {
            temp = NULL;
            delete(temp);
            return;
        }
        
        if(temp->left == tmp)
        {
            temp->left = NULL;
            delete(temp->left);
            return;
        }
        else
        {
            NodeQ.push(temp->left);
        }
        
        if(temp->right == tmp)
        {
            temp->right = NULL;
            delete(temp->right);
            return;
        }
        else
        {
            NodeQ.push(temp->right);
        }
    }
}

void tree::inorderRec(node *root)
{
    if(root == NULL)
    {
        return;
    }
    //Set temp as root and push it on stack.
    // Push all left child to Stack until you reach Temp as NULL
    stack<node *> NodeS;
    temp = root;
    while(temp != NULL || NodeS.empty() == false)
    {
        //Push all left child to Stack
        while(temp != NULL)
        {
            NodeS.push(temp);
            temp = temp->left;           
        }
        // Now temp is NULL
        // Pop element from top and print it
        temp = NodeS.top();
        NodeS.pop();
        
        cout<<" "<<temp->data;
        // Set temp as popped item's right node
        temp = temp->right;
    }
}

bool tree::checkLevel(node *root, int level, int *leafLevel)
{
    if(root == NULL)
    {
        return true;
    }
    
    //if leaf node found
    if(root->left == NULL && root->right == NULL)
    {
        //check if this if first time
        if(*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }
        //if not first found then compare level and leafLevel
        return(level == *leafLevel);
    }
    //if not leaf node then recursively check leaf nodes
    return(checkLevel(root->left, level+1, leafLevel) &&
           checkLevel(root->right, level+1, leafLevel));
}

bool tree:: check(node *root)
{
    int level = 0;
    int leafLevel = 0;
    return(checkLevel(root, level, &leafLevel));
}

int main()
{
    tree obj;
    vector<int> items, items1;
    
    //get data from stdin
    stringstream ss,ss1;
    string input;
    getline(cin, input);
    ss.str(input);
    char dlm = ',';
    string item;
    while(getline(ss, item, dlm))
    {
        items.push_back(stoi(item));
    }
    /*
    obj.create1(items);
    obj.prettyPrintTree(obj.tree1);
    cout<<endl;
    
    getline(cin, input);
    ss1.str(input);
    while(getline(ss1, item, dlm))
    {
        items1.push_back(stoi(item));
    }
    obj.create2(items1);
    obj.prettyPrintTree(obj.tree2);
    obj.tree3 = obj.mergeSumTrees(obj.tree1, obj.tree2);
    obj.prettyPrintTree(obj.tree3);
    */
    obj.create(items);
    obj.prettyPrintTree(obj.root);
    cout<<"Inorder Traversal : ";
    obj.inorder(obj.root);
    cout<<endl;
    if(obj.check(obj.root))
    {
        cout<<"All Leafs are at same level"<<endl;
    }
    else
    {
        cout<<"All Leafs are not at same level"<<endl;
    }
    /*
    cout<<"Height of tree : "<<obj.getHeightNonRec(obj.root)<<endl;
    cout<<"Insert Node 9"<<endl;
    obj.insertNode(obj.root, 9);
    obj.prettyPrintTree(obj.root);
    //cout<<"Delete Node 2 "<<endl;
    //obj.deleteNode(obj.root, 2);
    //obj.prettyPrintTree(obj.root);
    cout<<"Inorder Traversal : "<<endl;
    obj.inorderRec(obj.root);
    cout<<endl;
    obj.inorder(obj.root);
    cout<<endl;
    */
    return 0;    
}