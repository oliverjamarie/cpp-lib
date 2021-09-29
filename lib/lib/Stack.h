#ifndef STACK_H
#define STACK_H

 #define TEMP template<class T>

// Because we're working with templates and templates are 
// translated before compile time, we implement their code here 
// in the header file 

TEMP
class StackNode{
    private:
        // Variables
        T data;
        StackNode<T>* next;

        // Functions
        

    public:
        // Constructors
        StackNode(){
            next = NULL;
        }
        StackNode(T data_in){
            next = NULL;
            data = data_in;
        }
        //Copy
        StackNode(StackNode<T> &node){
            data = node.data;
            next = node.next;
        }

    template <class U> friend class Stack;
};

TEMP
class Stack{
    private:
        StackNode<T>* head;
        int size;

    public:
        // Constructors
        Stack(){
            head = NULL;
            size = 0;
        }
        Stack(T data){
            size = 0;
            head = NULL;

            push(data);
        }

        // Functions
        void push(T data){
            StackNode<T>* node = new StackNode<T>(data);

            node->next = head;
            head = node;

        }
        
        T* peek (){
            if (head == NULL){
                return NULL;
            }

            
            return &(head->data);
        }

        T pop(){
            T data;
            StackNode<T>* node;

            if (head == NULL){
                return NULL;
            }

            node = head;
            
            data = *(peek());

            head = head->next;

            size --;
            delete node;

            return data;
        }

        int getSize(){
            return size;
        }



        
};





#endif