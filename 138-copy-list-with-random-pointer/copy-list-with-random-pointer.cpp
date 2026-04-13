class Solution {
public:
    Node* copyRandomList(Node* head){
        if(head==NULL)return NULL;

        unordered_map<Node*,Node*>m; //oldNode,newNode

        Node* newhead=new Node(head->val);
        Node* newtemp=newhead;
        Node* oldtemp=head->next;

        m[head]=newhead;

        while(oldtemp!=NULL){  //simply copy 
            Node* copyNode = new Node(oldtemp->val);
            m[oldtemp]=copyNode;
            newtemp->next=copyNode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        newtemp=newhead;
        oldtemp=head;
        
        while(oldtemp!=NULL){ //random connection in new LL
            newtemp->random=m[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;

        }
        return newhead;



    }
};