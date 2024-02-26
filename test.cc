#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <stdexcept>
#include <chrono>
#include <regex>
#include <random>
#include <type_traits>

#define FIRST_MACRO
#define SECOND_MACRO

// Define a custom namespace
namespace CustomNamespace {
    // Define a custom class with more than 8 constructors
    class MyClass {
    public:
        MyClass(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8, int value9) 
            : value1_(value1), value2_(value2), value3_(value3), value4_(value4), value5_(value5), value6_(value6), value7_(value7), value8_(value8), value9_(value9) {}
        int getValue1() const { return value1_; }
        int getValue2() const { return value2_; }
        int getValue3() const { return value3_; }

        int getValue4() const { return value4_; }
        int getValue5() const { return value5_; }
        int getValue6() const { return value6_; }

        int getValue7() const { return value7_; }
        int getValue8() const { return value8_; }
        int getValue9() const { return value9_; }
        // it is going to be used to ignore starting a new logical block
    private:
        int value1_;
        int value2_;
        int value3_;
        int value4_;
        int value5_;
        int value6_;
        int value7_;
        int value8_;
        int value9_;
    protected:
        double dummy_;
    };

    // Define a single line function
    int add(int a, int b) { return a + b; }
}

namespace Nested {
// 1. constexpr static const int
constexpr static const int constexprStaticConstInt = 42;

// 2. const static constexpr int
const static constexpr int constStaticConstexprInt = 100;

// 3. static const constexpr int
static const constexpr int staticConstConstexprInt = 200;

// 4. constexpr const static int
constexpr const static int constexprConstStaticInt = 300;

// 5. static constexpr const int
static constexpr const int staticConstexprConstInt = 400;

// 6. const constexpr static int
const constexpr static int constConstexprStaticInt = 500;
}

// Define a custom alias for convenience
using namespace std;

int main() {
    // Create a vector of integers
    vector<int> numbers;
    for (int i = 1; i <= 100; ++i) {
        numbers.push_back(i);
    }

    // Apply customFunction to the vector
    auto doubledNumbers = CustomNamespace::customFunction(numbers);

    // Print the doubled numbers
    cout << "Doubled numbers: ";
    for (const auto& num : doubledNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Create an instance of MyClass with more than 8 constructor parameters
    CustomNamespace::MyClass obj(1, 2, 3, 4, 5, 6, 7, 8, 9);

    // Print values of MyClass instance
    cout << "Values of MyClass instance:" << endl;
    cout << "Value1: " << obj.getValue1() << endl;
    cout << "Value2: " << obj.getValue2() << endl;
    cout << "Value3: " << obj.getValue3() << endl;
    cout << "Value4: " << obj.getValue4() << endl;
    cout << "Value5: " << obj.getValue5() << endl;
    cout << "Value6: " << obj.getValue6() << endl;
    cout << "Value7: " << obj.getValue7() << endl;
    cout << "Value8: " << obj.getValue8() << endl;
    cout << "Value9: " << obj.getValue9() << endl;

    // Single line if statement
    int x = 10;
    if (x > 5) cout << "x is greater than 5" << endl;

    // Single line loop
    cout << "Numbers from 1 to 10: ";
    for (int i = 1; i <= 10; ++i) cout << i << " ";
    cout << endl;

    // Single line else-if statement with single statement
    if (x < 0)
        cout << "x is negative" << endl;
    else if (x == 0)
        cout << "x is zero" << endl;
    else if (x > 0)
        cout << "x is positive" << endl;

    // Multiple statements else-if statement with curly braces
    if (x < 0) {
        cout << "x is negative" << endl;
        x = -x;
    } else if (x == 0) {
        cout << "x is zero" << endl;
        ++x;
    } else if (x > 0) {
        cout << "x is positive" << endl;
        --x;
    }

    // Switch statement
    switch (x) {
        case 0:
            cout << "x is zero" << endl;
            break;
        case 1:
            cout << "x is one" << endl;
            break;
        default:
            cout << "x is neither zero nor one" << endl;
    }

#ifdef FIRST_MACRO
    cout << "First macro is defined." << endl;
#ifdef SECOND_MACRO
    cout << "Second macro is also defined." << endl;
#endif
#endif

#ifdef THIRD_MACRO
    cout << "Third macro is defined." << endl;
#else
    cout << "Third macro is not defined." << endl;
#endif

    // Pointer and reference usage
    int num = 42;
    int* ptr = &num;
    int& ref = num;

    cout << "Value of num: " << num << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;
    cout << "Value referred by ref: " << ref << endl;

    vector<int> v;
    static vector<int> v1;
    const vector<int>& v2 = v;

    const int kNum = 10;

    static const char* const strstr = "abcd";

    return 0;
}

// Define a custom class that uses C++14 features
template<typename T>
class CustomClass {
public:
    CustomClass() {
        static_assert(is_default_constructible<T>::value, "T must be default constructible");
    }

    void printInfo() const {
        cout << "CustomClass<T>" << endl;
    }
};

// Define a custom function that uses C++14 features
template<typename T>
void customFunction2(T&& arg) {
    if constexpr (is_same<T, int>::value) {
        cout << "Argument type: int" << endl;
    } else if constexpr (is_same<T, double>::value) {
        cout << "Argument type: double" << endl;
    } else {
        cout << "Argument type: unknown" << endl;
    }
}
