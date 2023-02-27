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
};
*/


class Solution
{
public:

    Node *reverse(Node *head, int k)
    {
        if(head->next==NULL)
            return head;
        // code here
        
        
        Node* first=head,*second=NULL;
        Node* temp=head;
        int count=k-1;
        
        while(count--)
        {
            temp=temp->next;
        }
        second=temp->next;
        temp->next=NULL;
        
        Node* curr=first,*prev=NULL,*next=first->next;
        
        while(next)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=curr->next;
        }
        curr->next=prev;
        first=curr;
        if(second==NULL)
            return first;
        Node* res=first;
        while(first->next)
        {
            first=first->next;
        }
        curr=second,prev=NULL,next=second->next;
        
        while(next)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=curr->next;
        }
        curr->next=prev;
        second=curr;
//      
        first->next=second;
        
        return res;
        
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