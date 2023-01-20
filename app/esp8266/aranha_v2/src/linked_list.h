#include"list.cpp"

template <typename T> class LinkedList:public List<T> {

    private:
        struct Node
        {
            T* data;
            Node* next;
        };
        Node* head = NULL;
        int _size = 0;
    

    public:
        int size() {
            return _size;
        }

        T* get(int index) {
            if(head == NULL) {
                return NULL;
            }

            int iterator=0;
            Node* currentNode = head;
            while(true) {
                if(iterator == index) return currentNode->data;
                if(currentNode->next == NULL) return NULL;

                currentNode = currentNode->next;
                iterator++;
            }
        }

        void add(T* element) {
            Node* newNode = new Node;
            newNode->data = element;
            newNode->next = NULL;

            if(head == NULL) {
                head = newNode;
                _size++;
                return;
            }

            Node* currentNode = head;
            while(true)
            {
                if(currentNode->next == NULL) {
                    currentNode->next = newNode;
                    _size++;
                    return;
                }
                currentNode = currentNode->next;
            }
            
        }

        T* remove(int index) {
            if(head == NULL) {
                return NULL;
            }

            if(index == 0) {
                T* element = head->data;
                head = head->next;
                delete head;
                _size--;
                return element;
            }

            Node* currentNode = head;
            for(int i=0; ;i++) {
                if(index == i+1) {
                    Node* nextElement = currentNode->next;
                    currentNode->next = nextElement->next;
                    T* element = nextElement->data;
                    delete nextElement;
                    _size--;
                    return element;
                }
                currentNode = currentNode->next;
            }
        }

};