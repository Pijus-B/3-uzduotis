#ifndef TA
#define TA

#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>

template <typename T>

class Vector{
    // MEMBER TYPES
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
};






#endif