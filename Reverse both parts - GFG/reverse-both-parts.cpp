//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
    
    
    curr->next=prev;
    prev=curr;
    curr=next;
    next=curr->next;
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
       {

//Code for reversing the list and counting the number of nodes into a variable count

        Node* curr=head;

        Node* prev=NULL;

        int count=0;

        while(curr!=NULL){

            Node* next=curr->next;

            curr->next=prev;

            prev=curr;

            curr=next;

            count++;

        }

//Important thing to note that now the starting of the list has prev as the main pointer ans not the head

        Node* temp=prev;

        int i=count-k-1;

        while(i--){

            temp=temp->next;

        }

        head->next=prev;

//Now connect the last of the list to the front

        Node* ans=temp->next;

        temp->next=NULL;

//Breaking at the node-k point 

        return ans;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends