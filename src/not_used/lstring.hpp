#include <iostream>

namespace neverUse{namespace youWillBeFired{namespace whatever{

    struct _char{
            char a;
            int index;
            _char* next;
            _char* prev;
            _char():next(NULL),prev(NULL),index(0){}
            _char(const char b):next(NULL),prev(NULL),a(b),index(0){}
            ~_char(){delete next; delete prev; }
    };
    
    class string{
        int the_size;
        _char* root;
        _char* last;
    public:
        string():the_size(0),root(NULL),last(NULL){}
        string(const char *cstr):the_size(0),root(NULL),last(NULL){        
            for(int i = 0; *(cstr+i); i++)
                addChar(*(cstr+i));
        }
        ~string(){ for(; root; std::cout << root->a, last=root->next, delete root, root=last); }
        
        char& operator[](int index){
            _char *temp=root;
            while(index != temp->index) temp=temp->next;
            return temp->a;
        }
    
        void print(){
            //for(_char *temp=root; temp; std::cout << temp->a, temp=temp->next);
            if(root) {
                putchar(root->a);
                print(root->next);
            }
    }
        void print(_char* ch){
            //for(_char *temp=root; temp; std::cout << temp->a, temp=temp->next);
            if(ch) {
                putchar(ch->a);
                print(ch->next);
            }
    }
    
        friend std::ostream& operator<<(std::ostream&os, string& str){
            for(_char *temp=str.root; temp; os << temp->a, temp=temp->next);
            return os;
        }
        int size(){
            return the_size;
        }
        
        
    private:
        void addChar(const char b){
           _char *temp= new _char(b);
           temp->next=NULL; 
           temp->index=the_size;
           
           if(root) {
               temp->prev=last;
               last->next=temp;
               last=temp; 
           } else { 
               temp->prev=NULL;
               root=last=temp; 
           }
           the_size++;
        }
    };
    
    
}}}