//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
   public:
    Node* reverse(Node *head)//1221
    {
        Node* prev=NULL;
        Node* next=NULL;
        Node* current=head;
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1,Node* num2)
    {
        num1=reverse(num1);
        num2=reverse(num2);
        Node* head=nullptr;
        int sum=0,carry=0;
        while(num1!=nullptr and num2!=nullptr)
        {
            sum=num1->data+num2->data+carry;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;//changing the head
            carry=sum/10;
            num1=num1->next;
            num2=num2->next;
        }
        while(num2!=nullptr)
        {
            sum=num2->data+carry;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
            num2=num2->next;
        }
        while(num1!=NULL)
        {
            sum=num1->data+carry;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
            num1=num1->next;
        }
        if(carry>0)
        {
            Node* temp=new Node(carry);
            temp->next=head;
            head=temp;
        }
        while(head->data==0 and head->next!=NULL)
        {
            head=head->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends