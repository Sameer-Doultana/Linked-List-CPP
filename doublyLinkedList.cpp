#include <iostream>
using namespace std;
struct node {
    int data;
    node*next = NULL;
    node*prev = NULL;
};
node*head = NULL;
node*tail = NULL;
void insertAtEnd();
void insertAtStart();
void insertBeforeSpecific(int key);
void insertAfterSpecific(int key);
void deleteMethod(int key);
void deleteBeforeSpecific(int element);
void deleteAfterSpecific(int element);
void deleteMultiple(int key);
void display();
bool search(int key);
void searchMultiple(int key);
void searchBefore(int key);
void searchAfter(int key);
void menu();
int main(){
    cout<<"Welcome!\nWhat do you want to do?"<<endl;
    menu();
    return 0;
}
void insertAtEnd(){
    node*current = new node;
    cout<<"Enter data: ";
    cin>>current->data;
    if(head==NULL){
        head = tail = current;
        cout<<"Data Entered"<<endl;
    }
    else{
        tail->next = current;
        current->prev = tail;
        tail = current;
        cout<<"Data Entered"<<endl;
    }
    char choice;
    cout<<"Enter Again?(y/n): ";
    cin>>choice;
    if(choice=='y'){
        insertAtEnd();
    }
    else{
        exit;
    }
}
void insertAtStart(){
    node*current = new node;
    cout<<"Enter data: ";
    cin>>current->data;
    if(head==NULL){
        head = tail = current;
        cout<<"Data Entered"<<endl;
    }
    else{
        head->prev = current;
        current->next = head;
        head = current;
        cout<<"Data Entered"<<endl;
    }
    char choice;
    cout<<"Enter Again?(y/n): ";
    cin>>choice;
    if(choice=='y'){
        insertAtStart();
    }
    else{
        exit;
    }
}
void insertBeforeSpecific(int key){
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        node*temp = new node;
        node*current = head;
        cout<<"Enter data: ";
        cin>>temp->data;
        if(head->data==key){
            head->prev = temp;
            temp->next = head;
            head = temp;
            cout<<"Data added"<<endl;
        }
        else{
            while(current!=NULL){
                if(current->data==key){
                    temp->next = current;
                    temp->prev = current->prev;
                    current->prev->next = temp;
                    current->prev = temp;
                    cout<<"Data added"<<endl;
                    return;
                }
                    current = current->next;
            }
            cout<<"No match"<<endl;
            delete temp;
        }
    }
}
void insertAfterSpecific(int key){
    node*temp = new node;
    node*current = head;
    cout<<"Enter data: ";
    cin>>temp->data;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(tail->data==key){
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                if(current->next==NULL){
                    temp->next = current->next;
                    temp->prev = current;
                    current->next = temp;
                    cout<<"Data added"<<endl;
                    return;
                }
                else{
                    temp->next = current->next;
                    temp->prev = current;
                    current->next->prev = temp;
                    current->next = temp;
                    cout<<"Data added"<<endl;
                    return;
                }
            }
            current = current->next;
        }
        cout<<"No match"<<endl;
        delete temp;
    }
}
void deleteMethod(int key){
    node*current = head;
    // if there is no data
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(head->data==key){
        // if there is only one node
        if(head==tail){
            head = NULL;
            tail = NULL;
            delete current;
            cout<<"Deleted only node"<<endl;
        }
        // if data is at head
        else{
            head = head->next;
            delete current;
            head->prev = NULL;
            cout<<"Deleted"<<endl;
        }
        
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                // if data is at tail
                if(current==tail){
                    tail = current->prev;
                    tail->next = NULL;
                    delete current;
                    cout<<"Deleted"<<endl;
                    return;
                }
                else{
                    // normal deletion
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    cout<<"Deleted"<<endl;
                    return;
                }               
            }
            current = current->next;
        }
        // if no match
        cout<<"No match"<<endl;
    }
}
void deleteBeforeSpecific(int element){
    node*current = head;
    // if there is no data
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    // if key is at head
    else if(head->data==element){
        cout<<"There is no data before"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==element){
                // if key is after head
                if(current->prev==head){
                    current->prev = NULL;
                    delete head;
                    head = current;
                    cout<<"Deleted"<<endl;
                    return;
                }
                else{
                    // normal deletion
                    node*pre = current->prev;
                    current->prev = pre->prev;
                    pre->prev->next = current;
                    delete pre;
                    cout<<"Deleted"<<endl;
                    return;
                }
            }
            current = current->next;
        }
        // if no match
        cout<<"No match"<<endl;
    }
}
void deleteAfterSpecific(int element){
    node*current = head;
    // if there is no data
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    // if key is at tail
    else if(tail->data==element){
        cout<<"There is no data after"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==element){
                // if key is before tail
                if(current->next==tail){
                    current->next = NULL;
                    delete tail;
                    tail = current;
                    cout<<"Deleted"<<endl;
                    return;
                }
                // normal deletion
                else{
                    node*post = current->next;
                    current->next = post->next;
                    post->next->prev = current;
                    delete post;
                    cout<<"Deleted"<<endl;
                    return;
                }
            }
            current = current->next;
        }
        // if there is no match
        cout<<"No match"<<endl;
    }
}
void deleteMultiple(int key){
    node*current = head;
    bool flag = false;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                if(head==tail){
                head = NULL;
                tail = NULL;
                delete current;
                cout<<"Deleted"<<endl;
                return;
                }
                else if(current==head){
                    head = head->next;
                    delete current;
                    head->prev = NULL;
                    current = head;
                    flag = true;
                }
                else if(current==tail){
                    tail = current->prev;
                    tail->next = NULL;
                    delete current;
                    flag = true;
                    current = NULL;
                }
                else{
                    node*del = current;
                    current = current->next;
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    delete del;
                    flag = true;
                }
            }
            else{
                current = current->next;
            }
        }
        if(flag==true){
            cout<<"Deleted"<<endl;
        }
        else{
            cout<<"No match"<<endl;
        }
    }
}
bool search(int key){
    node*current = head;
    node*temp = tail;
    int nodeIndex = 1;
    if(head==NULL){
        cout<<"there is no data"<<endl;
    }
    else{
        while(current!=NULL || temp!=NULL){
            if(current->data==key){
                cout<<"Data found at node "<<nodeIndex<<" from start"<<endl;
                return true;
            }
            else if(temp->data==key){
                cout<<"Data found at node "<<nodeIndex<<" from last"<<endl;
                return true;
            }
            current = current->next;
            temp = temp->prev;
            nodeIndex++;
        }
        cout<<"No match"<<endl;
        return false;
    }
}
void searchMultiple(int key){
    node*current = head;
    int nodeIndex = 1;
    bool flag = true;
    if(head==NULL){
        cout<<"there is no data"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                cout<<"Data found at node "<<nodeIndex<<endl;
                flag = false;
            }
            current = current->next;
            nodeIndex++;
        }
        if(flag==true){
            cout<<"No match"<<endl;
        }
    }
}
void searchBefore(int key){
    node*current = head;
    if(head==NULL){
        cout<<"there is no data"<<endl;
    }
    else if(head->data==key){
        cout<<"There is no data before"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                cout<<"Data before is "<<current->prev->data<<endl;
                return;
            }
            current = current->next;
        }
        cout<<"No match"<<endl;
    }
}
void searchAfter(int key){
    node*current = head;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(tail->data==key){
        cout<<"There is no data after"<<endl;
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                cout<<"Data after is "<<current->next->data<<endl;
                return;
            }
            current = current->next;
        }
        cout<<"No match"<<endl;
    }
}
void display(){
    node*current = head;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        while(current!=NULL){
            cout<<current->data<<endl;
            current = current->next;
        }
    }
}
void menu(){
    cout<<"0. Exit\n1. Insert at End\n2. Insert at Start\n3. Insert Before an Element\n4. Insert After Specific";
    cout<<"\n5. Delete\n6. Delete before specific\n7. Delete after specific\n8. Delete Multiple Instance"<<endl;
    cout<<"9. Search\n10. Search Multiple Instances\n11. Search before\n12. Search After\n13. Display"<<endl;
    int choosen;
    cout<<"Enter choice: ";
    cin>>choosen;
    if(choosen==1){
        insertAtEnd();
        menu();
    }
    else if(choosen==2){
        insertAtStart();
        menu();
    }
    else if(choosen==3){
        int element;
        cout<<"Enter Specific Element: ";
        cin>>element;
        insertBeforeSpecific(element);
        menu();
    }
    else if(choosen==4){
        int element;
        cout<<"Enter Specific Element: ";
        cin>>element;
        insertAfterSpecific(element);
        menu();
    }
    else if(choosen==5){
        cout<<"Enter key: ";
        int key;
        cin>>key;
        deleteMethod(key);
        menu();
    }
    else if(choosen==6){
        int element;
        cout<<"Enter Specific Element: ";
        cin>>element;
        deleteBeforeSpecific(element);
        menu();
    }
    else if(choosen==7){
        int element;
        cout<<"Enter Specific Element: ";
        cin>>element;
        deleteAfterSpecific(element);
        menu();
    }
    else if(choosen==8){
        int element;
        cout<<"Enter instance: ";
        cin>>element;
        deleteMultiple(element);
        menu();
    }
    else if(choosen==9){
        cout<<"Enter key: ";
        int key;
        cin>>key;
        search(key);
        menu();
    }
    else if(choosen==10){
        cout<<"Enter key: ";
        int key;
        cin>>key;
        searchMultiple(key);
        menu();
    }
    else if(choosen==11){
        cout<<"Enter key: ";
        int key;
        cin>>key;
        searchBefore(key);
        menu();
    }
    else if(choosen==12){
        cout<<"Enter key: ";
        int key;
        cin>>key;
        searchAfter(key);
        menu();
    }
    else if(choosen==13){
        display();
        menu();
    }
    else if(choosen==0){
        exit(0);
    }
    else{
        cout<<"Enter valid choice"<<endl;
        menu();
    }
}