//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        map<int,vector<Node*>> mp;
        
        
        while(head)
        {
            if(head->data == 0)
                mp[0].push_back(head);
            else if(head->data == 1)
                mp[1].push_back(head);
            else
                mp[2].push_back(head);
            head = head->next;
        }
        
        bool flag = false;
        Node *result, *answerhead;
        for(auto it: mp)
        {
            int count = 0;
            int total = it.second.size();
            if(flag == false)
            {
                result = it.second[0];
                answerhead = result;
                flag = true;
                count = 1;
            }
            
            while(count != total)
            {
                result->next = it.second[count];
                result = result->next;
                count++;
            }
        }
        result->next = NULL;
        return answerhead;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, dataue, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &dataue);

        if (i == 0) {
            start = new Node(dataue);
            temp = start;
            continue;
        } else {
            temp->next = new Node(dataue);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends