#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* p) : ptr(p) {}

    Iterator<T>& operator++() {
        ++ptr;
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    bool operator==(const Iterator<T>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const Iterator<T>& other) const {
        return ptr != other.ptr;
    }

    bool is_end(T* end_ptr) const {
        return ptr == end_ptr;
    }

    T value() const {
        return *ptr;
    }

    Iterator<T> next() const {
        return Iterator<T>(ptr + 1);
    }
};

#endif
