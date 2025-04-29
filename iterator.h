#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdexcept>

template<typename T>
class m_vector;

template<typename T>
class Iterator {
private:
    m_vector<T>& vec;
    int index;

public:
    Iterator(m_vector<T>& container_obj, int idx = 0) : vec(container_obj), index(idx) {}

    Iterator<T> next() const {
        return Iterator<T>(vec, index + 1);
    }

    T value() const {
        return vec.get_elem(index);
    }

    bool is_end() const {
        return index >= vec.get_length();
    }

    Iterator<T>& operator++() {
        ++index;
        return *this;
    }

    T& operator*() const {
        return vec.get_elem(index);
    }

    bool operator==(Iterator<T>& b) {
        return &vec == &b.vec && index == b.index;
    }

    bool operator!=(Iterator<T>& b) {
        return !(*this == b);
    }
};

#endif // ITERATOR_H
