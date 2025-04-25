#include <iostream>
#include <cctype>
using namespace std;

struct node {
    int data;
    node *next;
};

int recursiveSum(node *head) {
  if(!head) return 0;
  return head->data + recursiveSum(head->next);
}

int recursiveLargestValue(node* head) {
    if(!head) return 0;
    return max(head->data, recursiveLargestValue(head->next));
}

node* recursiveFindKthnode(node *head, int k){
    if(!head) return NULL;
    if(k == 1) {
        return head;
    } else {
        return recursiveFindKthnode(head->next, k-1);
    }
}

/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
node* recursiveDeleteKthnode(node *head, int k) {
    if(!head) return NULL;
    if(k == 1) {
        node*temp = head->next;
        delete head;
        return temp;
    } else{
        head->next = recursiveDeleteKthnode(head->next, k-1);
    }
    return head; //return modified head
}

node* removeElements(node* head, int num) {
    if(!head) return head;
    if(head->data == num) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    head->next = removeElements(head->next, num);
}

node* addIntAtEnd(node*head,int n){
    if(!head){
        node* temp = new node;
        temp->data = n;
        temp->next = NULL;
        return temp;
    } else{
        head->next = addIntAtEnd(head->next, n);
    }

    return head;
}

node* length(node* head) {
    if(!head) return 0;
    return 1+ length(head->next);
}


node* deleteKth(node* head, int k) {
    if(!head) return head;
    if(k == 1) {
        node*temp = head;
        head=head->next;
        delete temp;
        return head;
    } else{
        head->next = deleteKth(head->next, k-1);
    }
    return head;
}



node* removeHead(node *&head) {
    head = head->next; 
    return head;
}

/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
node* recursiveRemoveKFromFront(node *head, int k) {
    if(!head) return NULL;
    if(k == 0) {return head;
    }else{
    return recursiveRemoveKFromFront(head->next, k-1);
    delete head;
    }

}

// head: pointer to the head of a linked list
// Return the number of nodes in the linked list
// If head is null, return 
int recursiveCountNodes(node* head) {
    if(!head) return 0;
    return 1+recursiveCountNodes(head->next);

}

// head: pointer to the head of a linked list
// target: the value to search for
// Return true if the value exists in the linked list, otherwise false
bool recursiveSearch(node* head, int target) {
    if(!head) return false;
    if(head->data == target) {
        return true;
    } else {
        return recursiveSearch(head->next, target);
    }
    return false;
}


// head: pointer to the head of a linked list
// Return the new head of the reversed linked list
// node* recursiveReverse(node* head) {
//     head->next = head;
// }

// head: pointer to the head of a linked list
// value: the value to insert
// Return the head of the modified linked list
node* recursiveInsertAtEnd(node* head, int value) {
    if(!head) {
        node *temp = new node;
        temp->data = value;
        return temp;
    } else{
        head->next = recursiveInsertAtEnd(head->next, value);
    }
    return head;
}

// head: pointer to the head of a linked list
// Return the head of the modified linked list
node* recursiveDeleteLastNode(node* head) {
    if(head->next == NULL) return NULL;
    head->next = recursiveDeleteLastNode(head->next);
    return head;
}

bool isValid(node* head) {
    if(!head) return true;
    node* temp = head->next;
    if(temp == head) return false;
    return isValid(head->next);


}//checks if a list is cyclic;




void printList(node *head) {
    if(!head) return;
    cout << head->data << " ";
    printList(head->next);
}




int main(){
    node *p = new node;
    node *head = new node; 
    node *q = new node;
    node *r = new node;

    q->data = 16;
    q->next = r;

    r->data = 17;
    r->next = NULL;


    p->data = 15;
    p->next = q;

    head->next = p;
    head->data = 14;



    cout << recursiveSum(head) << endl;

    cout << recursiveLargestValue(head) << endl;

    cout << recursiveFindKthnode(head, 3)->data << endl;

    cout << recursiveCountNodes(head) << endl;

    cout << recursiveSearch(head, 15) << endl;

    printList(head);
    
    node *temp = new node;
    temp = recursiveDeleteLastNode(head);

    cout << endl;
    printList(temp);
    cout << q->next;

    return 0;

}





//g++ -std=c++11 linkedlistsb.cpp