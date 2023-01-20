#include"list.cpp"

template <typename T> class ArrayList:public List<T> {
    private:
        T** list;
        int _size = 0;
        int maxSize = 10;
    
    public:
        ArrayList() {
            list = new T*[maxSize];
        }

        ArrayList(int maxSize) {
            this->maxSize = maxSize;
            list = new T*[maxSize];
        }

        int size() {
            return _size;
        }

        T* get(int index) {
            if(index > _size-1) {
                return NULL;
            }
            return list[index];
        }

        void add(T* element) {
            if(_size == maxSize) {
                maxSize = maxSize + 10;
                T** newlist = new T*[maxSize];

                for(int i=0; i<_size; i++) {
                    newlist[i] = list[i];
                }

                delete[] list;
                list = newlist;
            }

            list[_size] = element;
            _size++;       
        }

        T* remove(int index) {
            if(index > _size-1) {
                return NULL;
            }
            
            T* removed = list[index];
            for(int i=index; i<_size-1; i++) {
                list[i] = list[i+1];
            }
            _size--;
            return removed;
        }
};