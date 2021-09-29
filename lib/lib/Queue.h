#ifndef QUEUE_H
#define QUEUE_H

#define TEMP template<class T> 

TEMP 
class QueueNode{
    T data;
    QueueNode<T>* next;

    public:
        // Constructors
        QueueNode(){
            next = NULL;
        }
        QueueNode(T data_in){
            next = NULL;
            data = data_in;
        }
};


TEMP
class Queue{
    int size;
    QueueNode<T>* head;
    QueueNode<T>* tail;

    public:
        // Constructors
        Queue(){
            size = 0;
            head = NULL;
        }
        Queue(T data){
            size = 0;
            head = NULL; 
            push(data);
        }

        // Functions
        void push(T data){
            QueueNode<T>* node = new QueueNode<T> (data);
            QueueNode<T>* curr;

            if (head == NULL){
                head = node;
                tail = node;
                return;
            }

            curr = head;

            while (curr->next != NULL) 
            {
                curr = curr->next;
            }
            
            curr->next = node;
            tail = node;
        }
        T* peek(){
            if (head == NULL){
                return NULL;
            }
            return &(head->data);
        }
        T* pop (){
            QueueNode<T>* node, *temp;

            if (head == NULL){
                return NULL;
            }

            node = new QueueNode<T>(head->data);

            temp = head;

            head = head->next;

            delete temp;
            
            return &(node->data);
        }
};

#endif