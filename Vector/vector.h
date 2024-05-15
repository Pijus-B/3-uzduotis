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
    Vector (InputIterator first, InputIterator last) {create(first, last);} //range konstruktorius
    Vector (Vector && v) {create(); swap(v); v.uncreate();} //move konstruktorius
    Vector (const std::initializer_list <T> il) {create(il.begin(), il.end());} //initializer list konstruktorius
    ~Vector(){uncreate();} //destruktorius

};






#endif