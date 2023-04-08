#include <iostream>
using namespace std;
void insertAtEnd();
void insertAtStart();
void insertBeforeSpecific(int element);
void insertAfterSpecific(int element);
void deleteMethod(int key);
void deleteBeforeSpecific(int element);
void deleteAfterSpecific(int element);
void deleteMultiple(int key);
void display();
int search(int key);
void searchMultiple(int key);
void searchBefore(int key);
void searchAfter(int key);
void menu();
struct node {
    int data;
    node*next = NULL;
};
node*head = NULL;
node*tail = NULL;
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
void insertBeforeSpecific(int element){
    int a = search(element);
    if(a==0){
        cout<<"Element does not exist"<<endl;   
    }
    else{
        node*current = head;
        node*pre = head;
        node*add = new node;
        cout<<"Enter data: ";
        cin>>add->data;
        if(head->data==element){
            add->next = head;
            head = add;
            cout<<"Data Added";
        }
        else{
            while(current!=NULL){
            if(current->data==element){
                pre->next = add;
                add->next = current;
                cout<<"Data Added"<<endl;
                break;
            }
            pre = current;
            current = current->next;
            }
        } 
    }
}
void insertAfterSpecific(int element){
    int a = search(element);
    if(a==0){
        cout<<"Element does not exist"<<endl;
    }
    else{
        node*current = head;
        node*add = new node;
        cout<<"Enter data: ";
        cin>>add->data;
        while(current!=NULL){
            if(current->data==element){
                add->next = current->next;
                current->next = add;
                if(add->next==NULL){
                    tail = add;
                }
                cout<<"Data Added"<<endl;
                break;
            }
            current=current->next;
        }
    }
}
void display(){
    node*current = head;
    //current = head;
    if(head==NULL){
        cout<<"No Data"<<endl;
    }
    else{
        do{
            cout<<current->data<<endl;
            current = current->next;
        }while(current!=NULL);
    }
}
int search(int key){
    node*current = head;
    int nodeIndex = 1;
    if(head==NULL){
        cout<<"No Data"<<endl;
    }
    else{
        while(current!=NULL){    
            if(current->data==key){
                return nodeIndex;
            }
            current = current->next;
            nodeIndex ++;
        }
    }
    return 0;
}
void searchMultiple(int key){
    node*current = head;
    int nodeIndex = 1;
    int a = search(key);
    if(a==0){
        cout<<"This data does not exist"<<endl;   
    }
    else{
        while(current!=NULL){
            if(current->data==key){
                cout<<"Data at node: "<<nodeIndex<<endl;
            }
            current = current->next;
            nodeIndex++;
        }
    }
}
void searchBefore(int key){
    node*current = head;
    node*pre = NULL;
    int a = search(key);
    if(a==0){
        cout<<"This data does not exist"<<endl;   
    }
    else{
        while(current!=NULL){
            if(head->data==key){
                cout<<"There is no node before"<<endl;
                break;
            }
            else if(current->data==key){
                cout<<"Data before is: "<<pre->data<<endl;
                break;
            }
            else{
                pre = current;
                current = current->next;
            }
        }
    }
}
void searchAfter(int key){
    node*current = head;
    node*after = current->next;
    int a = search(key);
    if(a==0){
        cout<<"This data does not exist"<<endl;   
    }
    else{
        while(current!=NULL){
            if(after==NULL){
                cout<<"There is no node after."<<endl;
                break;
            }
            else if(current->data==key){
                cout<<"Data after is: "<<after->data<<endl;
                break;
            }
            else{
                current = current->next;
                after = current->next;
            }
        }
    }
}
void deleteMethod(int key){
    node*current = head;
    node*pre = NULL;
    int a = search(key);
    if(a==0){
        cout<<"This data does not exist"<<endl;   
    }
    else{
        if(current->data==key){
            head = current->next;
            delete current;
            cout<<"Deleted Successfully"<<endl;
            return;
        }
        while(current!=NULL){
            if(current->data==key){
                if(current==tail){
                    tail = pre;
                    tail->next = NULL;
                    delete current;
                    cout<<"Deleted Successfully"<<endl;
                    break;
                }
                else{
                    pre->next = current->next;
                    delete(current);
                    cout<<"Deleted Successfully"<<endl;
                    break;
                } 
            }
            else{
                pre = current;
                current = current->next;
            }           
        }
    }
}
void deleteBeforeSpecific(int element){
    node*current = head;
    node*pre = NULL;
    int a = search(element);
    if(a==0){
        cout<<"This data does not exist"<<endl;
        return;
    }
    else{
        if(current->data==element){
            cout<<"There is no data before this element"<<endl;
            return;
        }
        else if(current->next->data==element){
            head = current->next;
            delete current;
            cout<<"Deleted Successfully"<<endl;
            return;
        }
        while(current!=NULL){
            if(current->next->data==element){
                pre->next = current->next;
                delete current;
                cout<<"Deleted Successfully"<<endl;
                break;
            }
            else{
                pre = current;
                current = current->next;
            }
        }
    }
}
void deleteAfterSpecific(int element){
    node*current = head;
    node*after = NULL;
    int a = search(element);
    if(a==0){
        cout<<"This data does not exist"<<endl;
        return;
    }
    else{
        while(current!=NULL){
            if(current->data==element && current->next==NULL){
                cout<<"There is no data after this element"<<endl;
                break;
            }
            else if(current->data==element){
                after = current->next;
                current->next = after->next;
                delete after;
                cout<<"Successfully Deleted"<<endl;
                break;
            }
            else{
                current = current->next;
            }
        }
    }
}
void deleteMultiple(int key){
    node*current = head;
    node*pre = NULL;
    int a = search(key);
    if(a==0){
        cout<<"This data does not exist"<<endl;
    }
    else{
        while(current!=NULL){
            if(head->data==key){
                if(head==tail){
                    head = NULL;
                    tail = NULL;
                    delete current;
                }
                else{
                    head = head->next;
                    delete current;
                    current = head;
                }
            }
            else if(current->data==key){
                if(current==tail){
                    tail = pre;
                    tail->next = NULL;
                    delete current;
                }
                else{
                    pre->next = current->next;
                    delete current;
                    current = pre->next;
                }
            }
            else{
                pre = current;
                current = current->next;
            }
        }
        cout<<"Deleted Successfully"<<endl;
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
        int a = search(key);
        if(a==0){
            cout<<"No Match"<<endl;   
        }
        else{
            cout<<"Data Found at node "<<a<<endl;
        }
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