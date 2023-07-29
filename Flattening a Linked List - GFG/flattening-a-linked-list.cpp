//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* root1,Node* root2)
{
    Node* head=new Node(-1);
    Node* node=head;
    Node* p=root1,*q=root2;
    
    while(p && q)
    {
        if(p->data<q->data)
        {
            node->bottom=p;
            node=node->bottom;
            p=p->bottom;
        }
        else
        {
            node->bottom=q;
            node=node->bottom;
            q=q->bottom;
        }
    }
    if(p)
    {
        node->bottom=p;
    }
    
    if(q)
    {
        node->bottom=q;
    }
    
    head->bottom->next=nullptr;
    return head->bottom;
    
}

Node *flatten(Node *root)
{
    if(!root || !root->next)
    return root;
    
    Node* prev=nullptr;
    Node* root1=nullptr;
    Node* root2=root;
    while(root2->next)
    {
        prev=root1;
        root1=root2;
        root2=root2->next;
    }
    
    Node* newNode=merge(root1,root2);
    
    if(prev)
    {
        prev->next=newNode;
        return flatten(root);
    }
    
    else
    return newNode;
}

