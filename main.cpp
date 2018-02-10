#include <iostream>
#include <string>
using namespace std;

struct node{
    char n;
    node * next;
};

class Pig_Latin_linked_List{
private:
    node * head;
    node * cu;
    node * temp;

public:
    Pig_Latin_linked_List(){

        head = nullptr;
        cu = nullptr;
        temp = nullptr;


    }
    char getFirstNodeData()
    {
        return head->n;
    }

    void add(char character){

        node *no = new node;
        no->n = character;
        no->next = nullptr;

        //if first node in system
        if (head == nullptr){
            head = no;
        }
        else
        {
            cu = head;

            while (cu->next != nullptr) {
                cu = cu->next;
            }

            cu->next = no;

        }

    }


    void print(){

        cu = head;

        while (cu != nullptr){

            cout << cu->n;
            cu = cu->next;
        }

        cout << endl;
    }
    void toEnd()
    {
        cu = head;
        temp = head->next;

        while (cu->next != nullptr) {
            cu = cu->next;
        }

        cu->next = head;
        head = temp;

        cu = cu->next;
        cu->next = nullptr;



    }
    void listTolist(Pig_Latin_linked_List &llist)
    {
        cu = head;

        while(cu != nullptr)
        {
            char c = cu->n;
            llist.add(c);
            cu = cu->next;
        }

    }

    void emptyList()
    {
        while(head != nullptr)
        {
            cu = head;
            head = cu->next;

            delete cu;
        }

    }
    ~Pig_Latin_linked_List()
    {
        this->emptyList();
        delete head;
        head = nullptr;
        cu = nullptr;
        temp = nullptr;
    }



};
bool isVowel(char c)
{
    string vowels = "AEIOUaeiou";

    size_t found = vowels.find(c);

    if(found == string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool isY(string c)
{
    size_t found1 = c.find('Y');
    size_t found2 = c.find('y');

    if((found1 == string::npos)&&(found2 == string::npos))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() {
    bool done = false, ivowel = false, noVowels = true, yCase = false;
    string Word;
    string EndWord = "DONE";
    Pig_Latin_linked_List llist, sentence;

    cout<<"Type DONE (in all caps) when your'e done"<<endl;

    while (!done){


        cout << "Enter word: ";
        cin >> Word;

        if (Word == EndWord){
            done = true;
            continue;
        }

        if(isVowel(Word[0]))
        {
            ivowel = true;

            noVowels = false;

        }

        for(int i = 0; (i < Word.length()) && (noVowels == true); i++)
        {

            if(isVowel(Word[i]))
            {
                noVowels = false;

            }

        }

        if((isY(Word))&&(noVowels == true))
        {
            yCase = true;
        }



        for(int i = 0; i < Word.length(); i++)
        {
            llist.add(Word[i]);
        }


        if(ivowel == true)
        {
            llist.add('-');
            llist.add('w');
            llist.add('a');
            llist.add('y');

        }
        else if((ivowel == false) && (noVowels == false))
        {
            llist.add('-');

            while(!isVowel(llist.getFirstNodeData()))
            {
                llist.toEnd();
            }

            llist.add('a');
            llist.add('y');

        }
        else if(yCase == true)
        {
            llist.add('-');

            while((llist.getFirstNodeData() != 'Y' )&&(llist.getFirstNodeData() != 'y'))
            {
                llist.toEnd();
            }

            llist.add('a');
            llist.add('y');

        }
        else
        {
            llist.add('-');
            llist.add('w');
            llist.add('a');
            llist.add('y');

        }

        llist.listTolist(sentence);
        sentence.add(' ');

        //resetting
        done = false;
        ivowel = false;
        noVowels = true;
        yCase = false;
        llist.emptyList();

    }

    sentence.print();






    return 0;
}


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
