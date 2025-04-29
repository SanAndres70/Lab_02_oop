#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include "iterator.h"

template<typename T>
class m_vector {
private:
    T* data;
    int length;

public:
    explicit m_vector(int length) : length(length) {
        if (length <= 0) throw std::invalid_argument("Length must be positive");
        data = new T[length]{};
    }

    m_vector(const m_vector<T>& vect) : length(vect.length) {
        data = new T[length];
        for (int i = 0; i < length; ++i)
            data[i] = vect.data[i];
    }

    m_vector(m_vector<T>&& vect) noexcept : data(vect.data), length(vect.length) {
        vect.data = nullptr;
        vect.length = 0;
    }

    explicit m_vector(std::initializer_list<T> lst) : length(lst.size()) {
        data = new T[length];
        int i = 0;
        for (const auto& el : lst) {
            data[i++] = el;
        }
    }

    ~m_vector() {
        delete[] data;
    }

    m_vector<T>& operator=(const m_vector<T>& lst) {
        if (this != &lst) {
            delete[] data;
            length = lst.length;
            data = new T[length];
            for (int i = 0; i < length; ++i)
                data[i] = lst.data[i];
        }
        return *this;
    }

    int get_length() const {
        return length;
    }

    void set_elem(int index, const T& elem) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        data[index] = elem;
    }

    T& get_elem(int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    T* to_array() {
        T* arr = new T[length];
        for (int i = 0; i < length; ++i)
            arr[i] = data[i];
        return arr;
    }

    T& operator[](int index) const {
        return get_elem(index);
    }

    template<typename _T>
    friend std::ostream& operator<<(std::ostream& os, const m_vector<_T>& lst) {
        os << "[ ";
        for (int i = 0; i < lst.length; ++i)
            os << lst.data[i] << " ";
        os << "]";
        return os;
    }

    m_vector<T>& operator+=(const m_vector<T>& vect) {
        if (length != vect.length)
            throw std::invalid_argument("Vector lengths must match");
        for (int i = 0; i < length; ++i)
            data[i] += vect.data[i];
        return *this;
    }

    m_vector<T>& operator-=(const m_vector<T>& vect) {
        if (length != vect.length)
            throw std::invalid_argument("Vector lengths must match");
        for (int i = 0; i < length; ++i)
            data[i] -= vect.data[i];
        return *this;
    }

    m_vector<T>& operator*=(const T& val) {
        for (int i = 0; i < length; ++i)
            data[i] *= val;
        return *this;
    }

    m_vector<T>& operator/=(const T& val) {
        if (val == 0)
            throw std::invalid_argument("Division by zero");
        for (int i = 0; i < length; ++i)
            data[i] /= val;
        return *this;
    }

    template<typename _T>
    friend m_vector<_T> operator+(const m_vector<_T>& v1, const m_vector<_T>& v2) {
        if (v1.length != v2.length)
            throw std::invalid_argument("Vector lengths must match");
        m_vector<_T> result(v1.length);
        for (int i = 0; i < v1.length; ++i)
            result.data[i] = v1.data[i] + v2.data[i];
        return result;
    }

    template<typename _T>
    friend m_vector<_T> operator-(const m_vector<_T>& v1, const m_vector<_T>& v2) {
        if (v1.length != v2.length)
            throw std::invalid_argument("Vector lengths must match");
        m_vector<_T> result(v1.length);
        for (int i = 0; i < v1.length; ++i)
            result.data[i] = v1.data[i] - v2.data[i];
        return result;
    }

    template<typename _T>
    friend m_vector<_T> operator*(const m_vector<_T>& v1, const _T& val) {
        m_vector<_T> result(v1.length);
        for (int i = 0; i < v1.length; ++i)
            result.data[i] = v1.data[i] * val;
        return result;
    }

    template<typename _T>
    friend m_vector<_T> operator/(const m_vector<_T>& v1, const _T& val) {
        if (val == 0)
            throw std::invalid_argument("Division by zero");
        m_vector<_T> result(v1.length);
        for (int i = 0; i < v1.length; ++i)
            result.data[i] = v1.data[i] / val;
        return result;
    }

    Iterator<T> iterator_begin() {
        return Iterator<T>(*this, 0);
    }

    Iterator<T> iterator_end() {
        return Iterator<T>(*this, length);
    }
};

#endif // M_VECTOR_H
