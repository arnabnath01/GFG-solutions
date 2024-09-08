//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow) {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* detectCycle(Node *head)
    {
        if(head==NULL)return NULL;
    
        Node*fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
         fast=fast->next->next;
         slow=slow->next;
    
         if(slow==fast)return slow;
        }
        return NULL;
     }
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        
          Node* meetingNode = detectCycle(head);
    
    // If there is no cycle, return as there's no loop to remove
    if(meetingNode == NULL) return;

    // To find the start of the loop:
    Node* start = head;
    
    // Move both pointers one step at a time until they meet at the start of the loop
    while(start != meetingNode) {
        start = start->next;
        meetingNode = meetingNode->next;
    }

    // Now, 'start' and 'meetingNode' both point to the start of the loop
    // We need to find the last node in the loop to break the loop
    Node* temp = start;
    while(temp->next != start) {
        temp = temp->next;
    }

    // Break the loop by setting the last node's next pointer to NULL
    temp->next = NULL;
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
    }
    return 0;
}

// } Driver Code Ends