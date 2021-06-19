//
// some namespace stuff
//
#include <iostream>
#include <iomanip>
#include "namespaces-and-arrays.h"

using namespace std;

namespace my_namespace_example {
    //to use a namespace, just type the word namespace and give it a name ,
    // namespaces can be any combination of letters and numbers a variable or function name can be

    //this variable can be used anywhere in the file, but not outside the file
    int some_file_wide_global = 42;

    size_t some_bad_global_variable = {1000}; //initialize global variable from header

}

namespace my_namespace_example::blursed_example {  //the xxx::yyy {} is from c++2017 onward, if you use earlier versions have to do the way below
    //namespaces can be inside other namespaces
    int some_file_wide_global = 100; //same name different value and variable entirely !!
}

//when you want to add something more to a namespace, simply use it again. The same namespace can be used across many files, if needed

namespace  my_namespace_example {
    namespace blursed_example {
        //we don't have to use the xxx::yyy thing like above for namespaces, we can use a longer version of doing it xxx{ yyy{} }

        //long doubles can store up to 33 past the decimal point
        const long double pi {3.141592653589793238462643383279}; //make this a constant
    }
}

namespace namespace_demo {

    void print_pi(int); //function declaration , also this function is file wide

    //function definition, here we are not returning anything, so its void
    void without_using() {
        cout << " my_namespace_example::some_file_wide_global is " << my_namespace_example::some_file_wide_global
             << endl;
        cout << " my_namespace_example::blursed_example::some_file_wide_global is "
             << my_namespace_example::blursed_example::some_file_wide_global << endl;
    }

    void using_example_a() {
        using namespace my_namespace_example; //still have to access the innermost namespace
        cout << " my_namespace_example::some_file_wide_global is " << some_file_wide_global << endl;
        cout << " my_namespace_example::blursed_example::some_file_wide_global is "
             << blursed_example::some_file_wide_global << endl;
    }

    void using_example_b() {
        using namespace my_namespace_example::blursed_example; //we are using the inner namespace,
        // but do not have access to the parent namespace stuff unless we use the scope operator ::

        cout << " my_namespace_example::some_file_wide_global is " << my_namespace_example::some_file_wide_global
             << endl; //although we are using the innermost,
        // we need to specify which variable with the same name if we want the outer one

        cout << " my_namespace_example::blursed_example::some_file_wide_global is " << some_file_wide_global << endl;

        cout << " pi ";
        print_pi(6);
        cout << endl;
    }

    /**
     * does not modify the count precision function (resets it)
     * @param  precision
     */
    void print_pi(int precision) {
        auto remember_precision = cout.precision();
        cout<< setprecision(precision) << my_namespace_example::blursed_example::pi;
        cout << setprecision( (int)remember_precision); //cast long to int in a sloppy fashion, same as using static_cast

    }

}

