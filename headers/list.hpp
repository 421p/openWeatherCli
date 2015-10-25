#include <string>
#include <iostream>

namespace MY{
    
class Node{
    public: std::string value;
    Node* next;
    Node* prev;
};

class List{
    Node* First;
    Node* Last;
    unsigned size;
    public:
        List():First(NULL),Last(NULL),size(0){};
        ~List();
    
    void add(std::string);
    void removeLast();
    void showList();
    unsigned getSize();
};

List::~List(){
   for(; First; Last=First->next, delete First, First=Last);
}

void List::add(std::string value){
   Node *temp= new Node;
   temp->next=NULL; 
   temp->value=value;
   
   if(First) {
       temp->prev=Last;
       Last->next=temp;
       Last=temp; 
   } else { //if empty
       temp->prev=NULL;
       First=Last=temp; 
   }
   size++;
}

void List::removeLast(){
    Node *temp = Last->prev;
    if(temp){
        temp->next = NULL;
        delete Last;
        Last = temp;
    }
    size--;
}

void List::showList(){
    for(Node *temp=First; temp; std::cout << temp->value << std::endl, temp=temp->next);
}

unsigned List::getSize(){
    return this->size;
}

}
