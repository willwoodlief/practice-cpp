//
// Created by will on 6/19/21.
//

#ifndef PRACTICE_CPP_NAMESPACES_AND_ARRAYS_H
#define PRACTICE_CPP_NAMESPACES_AND_ARRAYS_H

namespace my_namespace_example {
    //we make a global variable that can be used anywhere in the program by using the word extern, we do not have to initialize it now
    extern size_t some_bad_global_variable ; // this only declares it, we actually create it in the namespaces.cpp
}

namespace namespace_demo {
    void without_using();

    void using_example_a();

    void using_example_b();
}

#endif //PRACTICE_CPP_NAMESPACES_AND_ARRAYS_H
