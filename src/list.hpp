#include <string>
#include <iostream>

class myNode{
    public: std::string value;
    myNode* next;
    myNode* prev;
};

class myList{
    myNode* First;
    myNode* Last;
    unsigned size;
    public:
        myList():First(NULL),Last(NULL),size(0){};
        ~myList(){
           for(; First; Last=First->next, delete First, First=Last);
        }

    void add(std::string);
    void removeLast();
    void showmyList();
    unsigned getSize();
};

void myList::add(std::string value){
   myNode *temp= new myNode;
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

void myList::removeLast(){
    myNode *temp = Last->prev;
    if(temp){
        temp->next = NULL;
        delete Last;
        Last = temp;
    }
    size--;
}

void myList::showmyList(){
    for(myNode *temp=First; temp; std::cout << temp->value << std::endl, temp=temp->next);
}

unsigned myList::getSize(){
    return this->size;
}

