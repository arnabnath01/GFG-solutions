//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    int getLength(Node* head){
        int count = 0;
        
        Node* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        
        return count;
    }
    Node* deleteMid(Node* head)
    {
        int middle = getLength(head);
        if(middle == 1){
            return NULL;
        }
    
        middle = (middle / 2)  + 1;
        
        Node* prev = NULL;
        Node* curr = head;
    
        int count = 1;
        
        while(count < middle){
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends