#include "m_vector.h"
#include "iterator.h"
#include <iostream>

int main() {
    m_vector<int> vec{1, 2, 3, 4, 5};

    cout << "Vector: " << vec << endl;

    vec.set_elem(2, 10);
    cout << "After set_elem: " << vec << endl;

    int value = vec.get_elem(2);
    cout << "Value at index 2: " << value << endl;

    Iterator<int> it = vec.iterator_begin();
    while (it != vec.iterator_end()) {
        cout << it.value() << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
