class BrowserHistory {         
    
    struct History{
      
        string val;
        History* next=NULL;
        History* prev=NULL ;
        
    };
    History* curr;
    
public:
    BrowserHistory(string homepage) {
        History* temp=new History();
        temp->val= homepage;
        // cout<<"Current homepage: "<<temp->val<<" next: "<<temp->next<<" prev: "<<temp->prev<<endl;
        curr=temp;
    }
    
    void visit(string url) {
        History* temp=new History();
        temp -> val = url;
        curr->next=temp;
        temp->prev=curr;
        curr=temp;
    }
    
    string back(int steps) {
        
        int count=steps;
        while(curr && curr->prev && count--)
        {
            curr=curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        int count=steps;
        while(curr && curr->next && count--)
        {
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */