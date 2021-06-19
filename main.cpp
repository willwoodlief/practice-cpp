#include <iostream>
#include "namespaces-and-arrays.h"
using namespace std;

int main() {

    namespace_demo::without_using();
    namespace_demo::using_example_a();
    namespace_demo::using_example_b();

    cout << "global var called from main " << my_namespace_example::some_bad_global_variable << endl;

    return 0;

}


