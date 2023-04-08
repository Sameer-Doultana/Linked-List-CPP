#include <iostream>
using namespace std;
struct node {
    int data;
    node*next = NULL;
    node*prev = NULL;
};
node*head = NULL;
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
    node*temp = new node;
    cout<<"Enter data: ";
    cin>>temp->data;
    if(head==NULL){
        head = temp;
        temp->next = head;
        temp->prev = head;
        cout<<"Data Added"<<endl;
    }
    else{
        node*current = head;
        while(current->next!=head){
            current = current->next;
        }
        if(current->next==head){
            current->next = temp;
            temp->prev = current;
            temp->next = head;
            head->prev = temp;
            cout<<"Data added"<<endl;
        }
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
    node*temp = new node;
    cout<<"Enter data: ";
    cin>>temp->data;
    if(head==NULL){
        head = temp;
        temp->next = head;
        temp->prev = head;
        cout<<"Data Added"<<endl;
    }
    else{
        node*current = head;
        while(current->next!=head){
            current = current->next;
        }
        if(current->next==head){
            current->next = temp;
            temp->prev = current;
            temp->next = head;
            head->prev = temp;
            head = temp;
            cout<<"Data added"<<endl;
        }
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
        cout<<"Enter data: ";
        cin>>temp->data;
        node*current = head;
        while(current->data!=key && current->next!=head){
            current = current->next;
        }
        if(current->data==key){
            if(current==head){
                if(current->next==head){
                    current->prev = temp;
                    current->next = temp;
                    temp->prev = current;
                    temp->next = current;
                    head = temp;
                    cout<<"Added"<<endl;
                }
                else{
                    current->prev->next = temp;
                    temp->prev = current->prev;
                    temp->next = current;
                    current->prev = temp;
                    head = temp;
                    cout<<"Added"<<endl;
                }
            }
            else{
                
                temp->prev = current->prev;
                current->prev->next = temp;
                temp->next = current;
                current->prev = temp;
                cout<<"Added"<<endl;
            }
        }
        else{
            cout<<"No Match"<<endl;
        }
    }
}
void insertAfterSpecific(int key){
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        node*current = head;
        node*temp = new node;
        cout<<"Enter data: ";
        cin>>temp->data;
        while(current->data!=key && current->next!=head){
            current = current->next;
        }
        if(current->data==key){
            current->next->prev = temp;
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;
            cout<<"Added"<<endl;
        }
        else{
            cout<<"No match"<<endl;
        }
    }
}
void deleteMethod(int key){
    if(head==NULL){ // if linked list is empty
        cout<<"There is no data"<<endl;
    }
    else{
        node*current = head;
        while(current->data!=key && current->next!=head){
            current = current->next;
        }
        if(current->data==key){
            if(current==head){
                // if there is only one node
                if(head->next==head){
                    head = NULL;
                    delete current;
                    cout<<"Deleted the only node"<<endl;
                }
                else{ // if data is at head
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    head = current->next;
                    current->prev = NULL;
                    current->next = NULL;
                    delete current;
                    cout<<"Deleted"<<endl;
                }  
            }
            else{ // normal deletion
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->next = NULL;
                current->prev = NULL;
                delete current;
                cout<<"Deleted"<<endl;
            }
            
        }
        else{ // key does not match
            cout<<"This data does not exist"<<endl;
        }
    }
}
void deleteBeforeSpecific(int element){

    if(head==NULL){ // if linked list is empty
        cout<<"There is no data"<<endl;
    }
    else if(head->next == head){
        cout<<"There is no node before"<<endl;
    }
    else{
        node*current = head;
        node*del = current->prev;
        while(current->data!=element && current->next!=head){
            del = current;
            current = current->next;
        }
        if(current->data==element){
            if(current==head){
                current = head->prev;
                head->prev->prev->next = head;
                head->prev = head->prev->prev;
                current->next = NULL;
                current->prev = NULL;
                delete current;
                cout<<"Deleted"<<endl;
            }
            else if(current->prev==head){
                del->prev->next = current;
                current->prev = del->prev;
                head = current;
                del->prev = NULL;
                del->next = NULL; 
                delete del;
                cout<<"Deleted"<<endl;
            }
            else{
                del->prev->next = current;
                current->prev = del->prev;
                del->prev = NULL;
                del->next = NULL; 
                delete del;
                cout<<"Deleted"<<endl;
            }
        }
        else{
            cout<<"This data does not exist"<<endl;
        }
    }
}
void deleteAfterSpecific(int element){
    if(head==NULL){ // if linked list is empty
        cout<<"There is no data"<<endl;
    }
    else if(head->next == head){
        cout<<"There is no node after"<<endl;
    }
    else{
        node*current = head;
        node*aft = current->next;
        while(current->data!=element && current->next!=head){
            current = current->next;
            aft = current->next;
        }
        if(current->data==element){
            if(current->next==head){
                current->next = aft->next;
                aft->next->prev = current;
                aft->next = NULL;
                aft->prev = NULL;
                delete aft;
                head = current->next;
                cout<<"Deleted"<<endl;
            }
            else{
                current->next = aft->next;
                aft->next->prev = current;
                aft->next = NULL;
                aft->prev = NULL;
                delete aft;
                cout<<"Deleted"<<endl;
            }
        }
        else{
            cout<<"This data does not exist"<<endl;
        }   
    }
}
void deleteMultiple(int key){
    bool flag = false;
    node*current = head;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(head->data==key && head->next==head){
        head = NULL;
        delete current;
        cout<<"Deleted the only node"<<endl;
    }
    else{
        node*pre = current->prev;
        while(current->next!=head){
            if(current->data==key){
                if(current==head){
                    pre->next = current->next;
                    current->next->prev = pre;
                    current->next = NULL;
                    current->prev = NULL;
                    delete current;
                    head = pre->next;
                    current = head;
                    flag = true;
                }
                else{
                    pre->next = current->next;
                    current->next->prev = pre;
                    current->next = NULL;
                    current->prev = NULL;
                    delete current;
                    current = pre->next;
                    flag = true;
                }
            }
            else{
                current = current->next;
                pre = current->prev;
            }
        }
        if(current->data==key && current->next==head){
            pre->next = head;
            head->prev = pre;
            current->next = NULL;
            current->prev = NULL;
            delete current;
            current = head;
            flag = true;
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
    int nodeIndex = 1;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        node*current = head;
        while(current->data!=key && current->next!=head){
            current = current->next;
            nodeIndex ++;
        }
        if(current->data==key){
            cout<<"Data present at node "<<nodeIndex<<endl;
        }
        else{
            cout<<"This data does not exist"<<endl;
        }
    }
}
void searchMultiple(int key){
    int nodeIndex = 1;
    bool flag = false;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        node*current = head;
        while(current->next!=head){
            if(current->data==key){
            cout<<"Data present at node "<<nodeIndex<<endl;
            flag = true;
            }
            current = current->next;
            nodeIndex ++;
        }
        if(current->data==key && current->next==head){
            cout<<"Data present at node "<<nodeIndex<<endl;
            flag = true;
        }
        if(flag == false){
            cout<<"No Match"<<endl;
        }
    }
}
void searchBefore(int key){
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(head->next==head){
        cout<<"There is no data before"<<endl;
    }
    else{
        node*current = head;
        while(current->data!=key && current->next!=head){
            current = current->next;
        }
        if(current->data==key){
            cout<<"Data before is "<<current->prev->data<<endl;
        }
        else{
            cout<<"This data does not exist"<<endl;
        }
    }
}
void searchAfter(int key){
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else if(head->next==head){
        cout<<"There is no data after"<<endl;
    }
    else{
        node*current = head;
        while(current->data!=key && current->next!=head){
            current = current->next;
        }
        if(current->data==key){
            cout<<"Data after is "<<current->next->data<<endl;
        }
        else{
            cout<<"This data does not exist"<<endl;
        }
    }
}
void display(){
    node*current = head;
    if(head==NULL){
        cout<<"There is no data"<<endl;
    }
    else{
        while(current->next!=head){
            cout<<current->data<<endl;
            current = current->next;
        }
        cout<<current->data<<endl;
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