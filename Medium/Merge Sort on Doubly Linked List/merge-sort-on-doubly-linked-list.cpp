//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    // function for merging two half of linked list
Node * merge(Node *h1,Node *h2)
{   if(h1 == NULL)return h2;  // if first linked list is empty return second head
    if(h2 == NULL)return h1;  // if second is empty return firsts head
    Node *c1= h1,*c2 = h2;    // c1 curr node for traversing first linkedlist
                              // c2 curr node for traversing second linkedlist
    h1 = (c1->data<=c2->data)?c1:c2; // return head of final sorted ll
    while(c1 != NULL && c2!= NULL)
    {
        if(c1->data <= c2->data)
        {
            while(c1->next != NULL &&c1->next->data <= c2->data)
            {
                c1 = c1->next;    // travese until c1->next->data is smaller
            }
            Node * next = c1->next;    // connecting the joints among
            c1->next = c2;             // the two linked lists to 
            c2->prev = c1;            // sort them
            c1 = next;
        }
        else 
        {
            while(c2->next != NULL && c2->next->data <= c1->data)
            {
                c2 = c2->next;
            }
            Node * next = c2->next;
            c2->next = c1;
            c1->prev = c2;
            c2 = next;
        }
    }
    return h1;// return head of final sorted linked list
}
struct Node *sortDoubly(struct Node *head)
{
    // Your code here
    // If there is only one node present then return it as head
    if(head->next == NULL)
    return head;
    
    // intialized slow and fast node to find the middle element in linkedlist
    Node *slow = head,*fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // h2 is head of other half of linked list
    Node * h2 = slow->next;
    slow->next = NULL;             // dividing linked list into two 
    h2->prev = NULL;               // parts from middle
    Node *h1 = sortDoubly(head);   // recursively calling for first half
    h2 = sortDoubly(h2);           // for second half of linked list
    
    return merge(h1,h2);           // merging the two half parts as sorted
}
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends