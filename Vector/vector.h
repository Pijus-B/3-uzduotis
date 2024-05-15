#ifndef TA
#define TA

#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>

template <typename T>

class Vector{
    // MEMBER TYPES
private:
    iterator dat;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;

    void create() { dat = avail = limit = nullptr; }
    void create(size_type n, const T& val) {
        dat = alloc.allocate(n);
        limit = avail = dat + n;
        std::uninitialized_fill(dat, limit, val);
    }
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& reference;
    typedef T* iterator;
    typedef const T* const_iterator;

    // MEMBER FUNCTIONS
    Vector() {create ();} // default konstruktorius
    explicit Vector (size_type n, const T& t = T{}) {create (n, T);} // fill
    Vector (const Vector& v) {create(v.begin(), v.end());} // copy konstruktorius
    template <class InputIterator>
    Vector (InputIterator first, InputIterator last) {create(first, last);} // range konstruktorius
    Vector (Vector && v) {create(); swap(v); v.uncreate();} // move konstruktorius
    Vector (const std::initializer_list <T> il) {create(il.begin(), il.end());} // initializer list konstruktorius
    ~Vector(){uncreate();} // destruktorius
    //operator=
    Vector& operator = (const Vector& other) {
        if(this != &other){
            uncreate();
            create(other.begin(), other.end()); // copy assignment operatorius
        }
        return *this;
    };
    Vector& operator = (Vector&& other){
        if (this != &other){
            create(other.begin(), other.end()); // move assignment operatorius
            uncreate();
        }
        return *this;
    };
    //assign
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last){
        uncreate();
        create(first, last);
    }
    void assign (size_type n, const value_type& val){
        uncreate();
        create(n, val);
    }
    void assign (initializer_list <value_type> il){
        uncreate ();
        create (il);
    }
    //element access
    const_reference at (size_type n) const {
        if (n >= size() || n < 0){
            throw std::out_of_range("Index Out of Range"); // at
            return dat[n];
        }
    }
    T& operator[] (size_type n) {return dat[n];}
    const T& operator [] (size_type) {const return dat[n];}
    reference at (size_type n){
        if (n >= size() || n < 0){                                //operator[]
            throw std::out_of_range("Index Out of Range");
            return dat[n];
        }
    }
    reference front(){
        return dat[n];
    };                                              //front
    const_reference front() const{
        return dat[n];
    }
    reference back(){
        return dat[size() - 1];
    }                                                //back
    const_reference back() const{
        return dat[size() - 1];
    }
    value_type* data() noexcept{
        return dat;                                  //data
    }
    const value_type* data() const noexcept{
        return dat;
    }
    //iterators
    iterator begin() {return dat;}
    const_iterator begin() const {return dat;}
    iterator end() {return avail;}
    const_iterator end() const{return avail;}
    //capacity
    size_type size() const{return avail-dat;}
    size_type max_size() const {return std::numeric_limits<size_type>::max();}    //max size
    void resize(size_type sz){
        if (sz < size()){
            iterator it = dat + sz;
            while (it != avail){
                alloc.destroy(it++);
            }
            avail = dat + sz;
        }
        else if (sz > capacity()){
            grow(sz);
            std::uninitialized_fill(avail, dat + sz, value_type());
            avail = dat + sz;
        }
    }
     void resize(size_type sz, const value_type& value) {
        if (sz > capacity()) {
            grow(sz);
        }
            
        if (sz > size()) {
            insert(end(), sz - size(), value);
        } else if (sz < size()) {
            avail = dat + sz;
        }
    }
    size_type capacity() const {return limit-dat;}            //capacity
    bool empty() const noexcept { return size() == 0;}     //empty
    void reserve (size_type n) {                        // reserve
        if (n > capacity()) {
            grow(n);
        }
    }
    void shrink_to_fit(){
        if (limit > avail)    //shrink to fit
        limit = avail;
    }
    //modifiers
    void clear () noexcept {uncreate();} // clear
    iterator insert (iterator position, size_type n, const value_type& val){return insert(position, 1, val);} //insert
    iterator insert(iterator position, size_type n, const value_type& val) {
        if (position < begin() || position > end()) {
            throw std::out_of_range("Index out of range");
        }
        if (avail + n > limit) {
            size_type index = position - begin();
            grow(n);
            position = begin() + index;
        }
        for (iterator it = end() + n - 1; it != position + n - 1; --it) {
            *it = std::move(*(it - n));
        }
        std::uninitialized_fill(position, position + n, val);
        avail += n;

        return position;
        }
    iterator erase(iterator position) {
        if (position < dat || position > avail) {
            throw std::out_of_range("Index out of range");
        }
        std::move(position + 1, avail, position);
        alloc.destroy(avail - 1);
        --avail;

        return position;
    }
        
    iterator erase(iterator first, iterator last) {
        iterator new_available = std::uninitialized_copy(last, avail, first); //erase

        iterator it = avail;
        while (it != new_available) {
            alloc.destroy(--it);
        }

        avail= new_available;
        return last;
    }
     void push_back (const value_type& t) { //push_back
            if (avail==limit) 
                grow();
            unchecked_append(t);
        }

        void push_back (value_type&& val) {   //push_back
            if (avail == limit)
                grow();
            unchecked_append(val);
        }

        void pop_back() {
            if (avail != dat)         //pop_back
                alloc.destroy(--avail);
        }

        void swap(Vector& x) {
            std::swap(dat, x.dat);          //swap
            std::swap(avail, x.avail);
            std::swap(limit, x.limit);
        }
        
        // NON-MEMBER FUNCTIONS
        bool operator= (const Vector <T>& other) const{
            if (size() != other.size()){
                return false;
            }
            return std::equal(begin(), end(), other.begin());
        }
        bool operator!= (const Vector <T>& other) const{
            return !(this* == other);
        }
        bool operator< (const Vector <T>& other) const{
            return std::lexicographical_compare(begin(), end(), other.begin(), other.end())
        }
        bool operator<= (const Vector <T>& other) const{
            return !(other < this*);
        }
        bool operator> (const Vector <T>& other) const{
            return std::lexicographical_compare(other.begin(), other.end(), begin(), end())
        }
        bool operator>= (const Vector <T>& other) const{
            return !(other > this*);
        }
};


#endif