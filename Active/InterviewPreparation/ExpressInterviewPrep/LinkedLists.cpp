#include <bits/stdc++.h>
using namespace std;



class node{
    public:
    int val;
    node* nxt;  

    node(){
        this->nxt = NULL;
    }

    node(int x){
        this->val =x;
        this->nxt = NULL;
    }
};

class deepnode{
    public:
    int val;
    deepnode* nxt;
    deepnode* random;

    deepnode(int x){
        val = x;
        nxt = random = NULL;
    }
};

class SinglyLinkedList{
    public:
    node *head;
    SinglyLinkedList(){
        head = NULL;
    }
    node *GetHead(){
        return this->head;
    }
    node* Insert(int x){
        if(head==NULL){
            head = new node(x);
            return head;
        }
        node *tmp = head;
        while(tmp->nxt!=NULL){
            tmp = tmp->nxt;
        }
        tmp->nxt = new node(x);
        return tmp->nxt;
    }
    void Show(node *root){
        while(root!=NULL){
            cout<<root->val<<' ';
            root = root->nxt;
        }
    }
    
    void PrintReverse(node *root){
        if(root==NULL) return;
        PrintReverse(root->nxt);
        cout<<root->val<<" ";
    }

    void AddNodeAtIndx(int x,int indx,node *&root){
        if(root==NULL){
            root = new node(x);
            return;
        }
        if(indx==0){
            node *newnode = new node(x);
            newnode->nxt = root;
            root = newnode;
            return;
        }
        int v =0;
        node *tmp = root;
        while(++v<indx and tmp->nxt!=NULL) tmp = tmp->nxt;
        if(tmp->nxt==NULL){
            tmp->nxt = new node(x);
            return;
        }
        node *tmp2 = tmp->nxt;
        node *newnode = new node(x);
        tmp->nxt = newnode;
        newnode->nxt = tmp2;
    }

    void ReverseLinkedList(node *&root){
        node *dummy = NULL;
        node *successor = head->nxt;
        if(successor==NULL or head==NULL) return;
        node*head = root;
        while(successor!=NULL){
            head->nxt = dummy;
            dummy = head;
            head = successor;
            successor = successor->nxt;
        }
        head->nxt = dummy;
        root = head;
    }

    void ReverseLinkedListRecursivlyUtil(node *curr,node *&root){
        if(curr->nxt==NULL){
            root = curr;
            return;
        }
        ReverseLinkedListRecursivlyUtil(curr->nxt,root);
        node *tmp = curr->nxt;
        tmp->nxt = curr;
        curr->nxt = NULL;
    }   

    node* MiddleOfLinkedList(node *root){
        if(root==NULL) return root;
        node *slow = root;
        node *fast = root;
        while(fast!=nullptr and fast->nxt!=nullptr){
            slow = slow->nxt;
            fast = fast->nxt->nxt;
        }
        return slow;
    }

    void RemoveKthFromEnd(node *&root,int k){
        if(root==NULL or k==0) return;
        int len = 0;
        node *it = root;
        while(it!=NULL){
            len++;
            it = it->nxt;
        }
        int v = 0;
        it = root;
        int save = len-k;
        if(save==0){
            root = root->nxt;
            it->nxt = NULL;
            return;
        }
        while(++v<(save)) it = it->nxt;
        node *tmp = it->nxt;
        it->nxt = tmp->nxt;
        tmp->nxt = NULL;
    }
     
    bool IsPalindromeWitStack(node *head){
        if(head==NULL or head->nxt==NULL) return 1;
        stack<int>process;
        node *slow = head;
        node *fast = head;
        while(fast!=NULL and fast->nxt!=NULL){
            fast = fast->nxt->nxt;
            process.push(slow->val);
            slow = slow->nxt;
        }
        if(fast!=NULL) slow = slow->nxt;
        while(slow!=NULL){
            if(slow->val==process.top()){
                process.pop();
                slow = slow->nxt;
                continue;
            }
            return 0;
        }
        return 1;
    }
    
    void IsPalindromeOptimizedReverseUtil(node *&root){
        node *dummy = NULL;
        node *next = root->nxt;
        node *curr = root;
        while(next!=NULL){
            curr->nxt = dummy;
            dummy = curr;
            curr = next;
            next = next->nxt;
        }
        curr->nxt = dummy;
        root = curr;   
    }

    bool IsPalindromeOptimized(node *head){
        if(head==NULL or head->nxt==NULL) return 1;
        node *slow = head;
        node *fast = head;
        while(fast->nxt!=NULL and fast->nxt->nxt!=NULL){
            fast = fast->nxt->nxt;
            slow = slow->nxt;
        }
        IsPalindromeOptimizedReverseUtil(slow->nxt);
        slow = slow->nxt;
        node *slow2 = head;
        while(slow!=NULL){
            if(slow->val!=slow2->val) return 0;
            slow = slow->nxt;
            slow2 = slow2->nxt;
        }
        return 1;
    }
    
    bool DetectCycle(node *head){
        node *slow = head;
        node *fast = head;
        while(fast!=NULL and fast->nxt!=NULL){
            fast = fast->nxt->nxt;
            slow = slow->nxt;
            if(fast==slow) return 1;
        }
        return 0;
    }

    node *AddNumbersInLinkedList(node *num1,node *num2){
        if(num1==NULL) return num2;
        if(num2==NULL) return num1;
        node *res = NULL;
        node *tmp = NULL;
        int carry =0;
        while(carry or num1!=NULL or num2!=NULL){
            int sum =0;
            if(num1!=NULL){
                sum+=num1->val;
                num1 = num1->nxt; 
            }
            if(num2!=NULL){
                sum+=num2->val;
                num2 = num2->nxt;
            }
            sum+=carry;
            carry = sum/10;
            node *nn = new node(sum%10);
            if(res==NULL){
                res = nn;
                tmp = res;
                continue;
            }
            tmp->nxt = nn;
            tmp = tmp->nxt;
        }
        return res;
    }

    node *StaringPointOfCycle(node *head){
        if(head==NULL) return NULL;
        node *slow = head;
        node *fast = head;
        do{
            slow = slow->nxt;
            fast = fast->nxt->nxt;
        }while(slow!=fast);
        node *dummy = head;
        while(dummy!=slow){
            dummy = dummy->nxt;
            slow = slow->nxt;
        }
        return dummy;
    }

    node *MergeSortedLinkedLists(node *l1,node *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val>l2->val) swap(l1,l2);
        node *res_head = l1;
        while(l1!=NULL and l2!=NULL){
            node *tmp = NULL;
            while(l1!=NULL and l1->val<=l2->val){
                tmp = l1;
                l1 = l1->nxt;
            }
            tmp->nxt = l2;
            swap(l1,l2);
        }
        return res_head;
    }
};



class TwoPointerList{
    public:
        deepnode *head;
    TwoPointerList(){
        head = NULL;
    }

    void Print(deepnode *head){
        deepnode *it = head;
        while(it!=NULL){
            cout<<it->val<<" ";
            if(it->nxt) cout<<it->nxt->val<<" ";
            else cout<<"no next ";
            if(it->random) cout<<it->random->val<<" ";
            else cout<<"no random ";
            it = it->nxt;
            cout<<endl;
        }
    }

    deepnode *CloneLinkedListDeepCopywithHashing(deepnode *head){
        unordered_map<deepnode*,deepnode*>cache;
        deepnode *it = head;
        while(it!=NULL){
            deepnode *newdeepnode = new deepnode(it->val); 
            cache.insert({it,newdeepnode});
            it = it->nxt;
        }
        it = head;
        auto cit = cache.find(it);
        deepnode *deephead = cit->second;
        while(it!=NULL){
           auto cit = cache.find(it);
           deepnode *orignal = cit->first;
           deepnode *copy = cit->second;
           copy->nxt = orignal->nxt;
           copy->random = orignal->random;
           it = it->nxt;
        }
        return deephead;
    }

    deepnode* CloneLinkedListDeepCopySpaceOptimized(deepnode *head){
        deepnode *deep_head = NULL;
        deepnode *cpy_tmp = deep_head;
        deepnode *tmp = head;
        while(tmp!=NULL){
            if(deep_head==nullptr){
                deep_head = new deepnode(head->val);
                deepnode *tmp_nxt = tmp->nxt;
                cpy_tmp = deep_head;
                tmp->nxt = deep_head;
                deep_head->nxt = tmp_nxt;
                tmp = tmp_nxt;
                continue;
            }
            deepnode* nn = new deepnode(tmp->val);
            deepnode *tmp_nxt = tmp->nxt;
            tmp->nxt = nn;
            nn->nxt = tmp_nxt;
            tmp = tmp_nxt;
            cpy_tmp = nn;
        }
        tmp = head;
        cpy_tmp = deep_head;
        while(cpy_tmp!=NULL){
            deepnode* tmpnxt = tmp->nxt->nxt;
            cpy_tmp->random = (tmp->random->nxt);
            cpy_tmp->nxt = (tmpnxt->nxt);
            tmp->nxt = tmpnxt;
            cpy_tmp = cpy_tmp->nxt;
            tmp = tmpnxt;
        }
        return deep_head;
    }

    deepnode* MergeLists(deepnode *l1,deepnode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val>l2->val) swap(l1,l2);
        l1->nxt = NULL;
        deepnode *reshead = l1;
        while(l1!=NULL and l2!=NULL){
            deepnode *tmp = NULL;
            while(l1->val<=l2->val and l1!=NULL){
                tmp = l1;
                l1 = l1->random;
            }
            tmp->random = l2;
            swap(l1,l2);
        }
        return reshead;
    }

    deepnode *FlatteningOfLinkedList(deepnode *root){
        if(root==NULL or root->nxt==NULL) return root;
        FlatteningOfLinkedList(root->nxt);
        root = MergeLists(root,root->nxt);
        return root;
    }
};






int main(){
    SinglyLinkedList l1,l2;
    // TwoPointerList dl;
    // dl.head = new deepnode(1);
    // dl.head->nxt = new deepnode(2);
    // dl.head->nxt->nxt = new deepnode(3);
    // dl.head->nxt->nxt->nxt = new deepnode(4);
    // dl.head->random = dl.head->nxt->nxt->nxt;
    // dl.head->nxt->random = dl.head;
    // dl.head->nxt->nxt->random = NULL;
    // dl.head->nxt->nxt->nxt->random =  dl.head->nxt;
    // deepnode *copy_head =  TwoPointerList().CloneLinkedListDeepCopySpaceOptimized(dl.head);
    //TwoPointerList().Print(dl.head);

    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        l1.Insert(x);
    }
    int n2;
    cin>>n2;
    for(int i =0;i<n2;i++){
        int x;
        cin>>x;
        l2.Insert(x);
    }
    node* head =  l1.MergeSortedLinkedLists(l1.head,l2.head);
    SinglyLinkedList().Show(head);
}
