
template <typename T>
class List {
    public:
        virtual T* get(int index) = 0;
        virtual void add(T* element) = 0;
        virtual T* remove(int index) = 0;
        virtual int size() = 0;
};