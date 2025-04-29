#include <iostream>
#include "m_vector.h"

using namespace std;

int main() {
    m_vector<int> v1{1, 2, 3, 4, 5};
    m_vector<int> v2{5, 4, 3, 2, 1};

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    m_vector<int> v3 = v1;
    cout << "v3 (copy of v1): " << v3 << endl;

    m_vector<int> v4 = std::move(v2);
    cout << "v4 (moved from v2): " << v4 << endl;

    v1.set_elem(0, 10);
    cout << "v1 after set_elem: " << v1 << endl;

    cout << "v1[0] = " << v1.get_elem(0) << endl;

    v1 += v3;
    cout << "v1 += v3: " << v1 << endl;

    v1 -= v3;
    cout << "v1 -= v3: " << v1 << endl;

    v1 *= 2;
    cout << "v1 *= 2: " << v1 << endl;

    v1 /= 2;
    cout << "v1 /= 2: " << v1 << endl;

    m_vector<int> v5 = v3 + v4;
    cout << "v3 + v4: " << v5 << endl;

    m_vector<int> v6 = v5 - v3;
    cout << "v5 - v3: " << v6 << endl;

    m_vector<int> v7 = v3 * 3;
    cout << "v3 * 3: " << v7 << endl;

    m_vector<int> v8 = v3 / 2;
    cout << "v3 / 2: " << v8 << endl;

    cout << "Iterating through v3 using Iterator:\n";
    for (Iterator<int> it = v3.iterator_begin(); !it.is_end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
