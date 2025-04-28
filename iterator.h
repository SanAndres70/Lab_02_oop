#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class m_vector;

template<typename T>
class Iterator {
private:
    m_vector<T>& vec;
    int index;

public:
    Iterator(m_vector<T>& v, int idx) : vec(v), index(idx) {}

    Iterator<T>& operator++() {
        if (index < vec.get_length())
            ++index;
        return *this;
    }

    T& operator*() const {
        if (index >= vec.get_length())
            throw std::out_of_range("Dereferencing end iterator");
        return vec[index];
    }

    bool operator==(const Iterator<T>& other) const {
        return &vec == &other.vec && index == other.index;
    }

    bool operator!=(const Iterator<T>& other) const {
        return !(*this == other);
    }

    bool is_end() const {
        return index >= vec.get_length();
    }

    T value() const {
        return vec.get_elem(index);
    }

    Iterator<T> next() const {
        return Iterator<T>(vec, index + 1);
    }
};

#endif // ITERATOR_H
