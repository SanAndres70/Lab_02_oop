#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <initializer_list>
#include <iostream>
#include "iterator.h"

template<typename T>
class m_vector {
public:
    m_vector(int len);
    m_vector(const T* arr, int len);
    m_vector(const m_vector<T>& other);
    m_vector(m_vector<T>&& other);
    m_vector(std::initializer_list<T> lst);

    ~m_vector();

    int get_length() const;
    void set_elem(int index, const T& val);
    T& get_elem(int index);
    T& operator[](int index);

    T* to_array() const;

    Iterator<T> iterator_begin();
    Iterator<T> iterator_end();

private:
    T* data;
    int len;
};

template<typename T>
m_vector<T>::m_vector(int len) : len(len) {
    data = new T[len];
}

template<typename T>
m_vector<T>::m_vector(const T* arr, int len) : len(len) {
    data = new T[len];
    for (int i = 0; i < len; ++i) {
        data[i] = arr[i];
    }
}

template<typename T>
m_vector<T>::m_vector(const m_vector<T>& other) : len(other.len) {
    data = new T[len];
    for (int i = 0; i < len; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
m_vector<T>::m_vector(m_vector<T>&& other) : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

template<typename T>
m_vector<T>::m_vector(std::initializer_list<T> lst) : len(lst.size()) {
    data = new T[len];
    int i = 0;
    for (const T& val : lst) {
        data[i++] = val;
    }
}

template<typename T>
m_vector<T>::~m_vector() {
    delete[] data;
}

template<typename T>
int m_vector<T>::get_length() const {
    return len;
}

template<typename T>
void m_vector<T>::set_elem(int index, const T& val) {
    if (index < 0 || index >= len) throw std::out_of_range("Index out of bounds");
    data[index] = val;
}

template<typename T>
T& m_vector<T>::get_elem(int index) {
    if (index < 0 || index >= len) throw std::out_of_range("Index out of bounds");
    return data[index];
}

template<typename T>
T& m_vector<T>::operator[](int index) {
    return get_elem(index);
}

template<typename T>
T* m_vector<T>::to_array() const {
    T* copy = new T[len];
    for (int i = 0; i < len; ++i) {
        copy[i] = data[i];
    }
    return copy;
}

template<typename T>
Iterator<T> m_vector<T>::iterator_begin() {
    return Iterator<T>(data);
}

template<typename T>
Iterator<T> m_vector<T>::iterator_end() {
    return Iterator<T>(data + len);
}

#endif
