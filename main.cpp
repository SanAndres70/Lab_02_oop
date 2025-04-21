#include <iostream>
#include "m_vector.h"
using namespace std;

int main() {
    m_vector<int> vec = {10, 20, 30, 40};

    cout << "Длина вектора: " << vec.get_length() << endl;

    cout << "Элементы, использующие get_elem(): ";
    for (int i = 0; i < vec.get_length(); ++i) {
        cout << vec.get_elem(i) << " ";
    }
    cout << endl;

    cout << "Элементы, использующие итератор: ";
    for (auto it = vec.iterator_begin(); it != vec.iterator_end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vec.set_elem(2, 99);
    cout << "Изменено vec[2] на 99 → vec[2] = " << vec[2] << endl;

    return 0;
}
