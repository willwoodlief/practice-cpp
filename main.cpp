#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



namespace my_namespace_example {
    //to use a namespace, just type the word namespace and give it a name ,
    // namespaces can be any combination of letters and numbers a variable or function name can be

    //this variable can be used anywhere in the file, but not outside the file when you are using other files
    int some_file_wide_global = 42;

    //we make a global variable that can be used anywhere in the program by using the word extern, we do not have to initialize it now
    extern size_t some_bad_global_variable ;
}

namespace my_namespace_example::blursed_example {
    //namespaces can be inside other namespaces
    int some_file_wide_global = 100; //same name different value and variable entirely !!
}

//when you want to add something more to a namespace, simply use it again. The same namespace can be used across many files, if needed

namespace  my_namespace_example {
    namespace blursed_example {
        //we don't have to use the xxx::yyy thing like above for namespaces, we can use a longer version of doing it xxx{ yyy{} }

        //long doubles can store up to 33 past the decimal point
        long double pi {3.141592653589793238462643383279};
    }
}

namespace older {
    void my_first_code();  //an example of declaring a function, I want to use this
}

//function definition, here we are not returning anything, so its void
void without_using() {
    cout << " my_namespace_example::some_file_wide_global is " << my_namespace_example::some_file_wide_global << endl;
    cout << " my_namespace_example::blursed_example::some_file_wide_global is " << my_namespace_example::blursed_example::some_file_wide_global << endl;
}

void using_example_a() {
    using namespace my_namespace_example; //still have to access the innermost namespace
    cout << " my_namespace_example::some_file_wide_global is " << some_file_wide_global << endl;
    cout << " my_namespace_example::blursed_example::some_file_wide_global is " << blursed_example::some_file_wide_global << endl;
}

void using_example_b() {
    using namespace my_namespace_example::blursed_example; //we are using the inner namespace,
    // but do not have access to the parent namespace stuff unless we use the scope operator ::

    cout << " my_namespace_example::some_file_wide_global is " << my_namespace_example::some_file_wide_global << endl; //although we are using the innermost,
    // we need to specify which variable with the same name if we want the outer one

    cout << " my_namespace_example::blursed_example::some_file_wide_global is " << some_file_wide_global << endl;
}


int main() {

    without_using();
    using_example_a();
    using_example_b();

    //older::my_first_code();

    return 0;

}

namespace older {
    void my_first_code() {
        //arrays can be in a vector class, but we are not using them here
        std::vector<int> v = { 3, 1, 4 }; //initialize like this for arrays
        v.push_back(6); //add a six to the end

        for (auto i : v ) { //iterate through the vector, we iterate through the plain vanilla array same way
            cout << i << endl;
        }

        //integers can be signed or unsigned, this is important !
        unsigned int test_me {};
        cout <<  setbase(16) << test_me <<endl ; //set output to hex base for integers (base 16)

        test_me = static_cast<unsigned int>(-1);  //negative number to see how the bits form (are stored) !
        cout << "as -1 " <<   test_me <<endl ;

        test_me >>= 8 ; //bits can be shifted around, here we are shifting the bits 8 to the right (32 bit int) , the left most are filled with 0

        cout << "shifted 8 right  "  << test_me   << endl ;
        cout << "and orred with - 1 "  << (test_me | -1)  << endl ;

        char what[] {'1','3','a'}; //standard integer array
        cout << &what << endl; //get the address of the array (will be covered in pointers, not here anymore)

        double why {1.1234567890};
        cout << std::setprecision(4) << why << endl; //show 4 digits instead of more

        double carrots[3][4] {}; //a double array initiation

        size_t who_x = sizeof(carrots)/sizeof(carrots[0]);  //to find the size of the elements
        size_t who_y = sizeof(carrots[1])/sizeof(carrots[0][0]);

        //iterating through the double array, no frills output
        for(size_t x {} ; x < who_x ; x++ ) {

            for(size_t y {} ; y < who_y ; y++ ) {
                cout << carrots[x][y] << "  ";
            }
        }

        cout << "--------------------" << endl;

        //array of of 100, here is the constant
        const int max_length {100};
        char text[max_length] {};
        const char *  what_i_said = "hello world,";
        cout << what_i_said << " Enter a line of text:" << endl;
        cin.getline(text,max_length,'*'); //get multiline text end when get to 100 or enter *
        cout << "You entered:\n" <<text <<endl;
        size_t vowels {};
        size_t consonants {};

        for(int i {}; text[i] != '\0';i++) {

            if (isalpha(text[i])) {
                char letter = text[i];
                if (letter == 'z') {continue;}

                switch(letter) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u' : {
                        ++vowels;
                        break;
                    }
                    default: {
                        ++consonants;
                    }
                }
            }
        } //end if

        cout << " excluding z, there are " << consonants << " consonants ; and " << vowels << " vowels " << endl;

        for( auto c : text) {
            if (!c) { break;}
            auto bear = static_cast<int>(c);
            std::cout << std::hex;
            std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
            cout << setw(3) << c << setw(6) << setbase(8) << bear << endl ;

        }
    }
}
