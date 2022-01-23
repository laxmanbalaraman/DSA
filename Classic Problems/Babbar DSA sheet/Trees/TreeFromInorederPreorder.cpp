// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
unordered_map <int, int> m;
int j = 0;
class Solution{
    public:
    
    Node* solve(int in[], int pre[], int lb, int ub){
        if(lb > ub) return NULL;
        Node *node = new Node(pre[j++]);
        if(lb == ub) return node;
        int mid = m[node->data];
        
        node->left = solve(in, pre, lb, mid - 1);
        node->right = solve(in, pre, mid +1, ub );
        return node;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        j = 0;
        m.clear();
        for(int i = 0; i < n; i++) m[in[i]] = i;
        Node *root = solve(in, pre, 0, n-1);
        cout << root->data << endl;
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends