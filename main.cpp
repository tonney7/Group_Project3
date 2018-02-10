#include <iostream>
using namespace std;

struct node{
    char n;
    node * next;
};

class Pig_Latin_linked_List{
private:
    node * head;
public:
    Pig_Latin_linked_List(){
        head = new node;
        head->next = 0;
    }

    void add(char character){
        node * cu = head;
        
        //if first node in system
        /*(if (cu->next == 0){
            cu = new node;
            cu->n = character;
            cu->next = 0;
            return;
        }*/
        
        while (cu->next != 0) {
            cu = cu->next;
        }
        cu->next = new node;
        cu = cu->next;
        cu->n = character;
        cu->next = 0;
    }
    
    
    void print(){
        node * cu = head;
        while (cu->next != 0){
            cout<<cu->n;
            cu= cu->next;
        }
        //for the last thing in the Linked list
        cout<<cu->n;
    }
    
};

int main() {
    cout<<"Please Enter in 1 word at a time (ie no spaces):"<<endl;
    
    bool done = false;
    string Word;
    string StopPhrase = "Qwerty";
    Pig_Latin_linked_List LINKEDLIST;
    
    while (!done){
        cout<<"What is your word (to stop, type in Qwerty)"<<endl;
        cin>>Word;
        // if stoping word
        if (Word == StopPhrase){
            done = true;
            continue;
        }
        for (int i = 0; i < Word.size();i++){
            LINKEDLIST.add(Word[i]);
        }
        LINKEDLIST.add(' ');
    }
    
    cout<<endl<<endl<<endl;
    LINKEDLIST.print();
    cout<<"\nDONE"<<endl;
    
    
    
    
    
    
    
    /*
    //trying out Linked List
    node * head = new node;
    head->n = 0;
    node * cu = head;
    for (int i = 1; i < 11;i++){
        cu->next = new node;
        cu = cu->next;
        cu->n = i;
    }
    
    cu = head;
    for (int i = 0; i < 11;i++){
        cout<<cu->n<<" ";
        cu = cu->next;
    }
    cout<<endl;
     */
    return 0;
}
