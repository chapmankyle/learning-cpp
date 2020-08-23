#include <array>       // for std::array
#include <algorithm>   // for std::sort()
#include <bitset>      // for std::bitset
#include <iterator>    // for std::size()
#include <string>      // for std::string and std::getline
#include <string_view> // for std::string_view
#include <utility>     // for std::swap()
#include <vector>      // for std::vector

#include <cstddef>     // for std::nullptr_t
#include <cstdint>     // for std::int_fast#_t and std::int_least#_t
#include <cstdlib>     // for std::rand() and std::srand()
#include <ctime>       // for std::time()

#include <typeinfo>    // for typeid()
#include <iostream>

// preprocessor macros
#define SOME_TEXT "Some Text"
#define PRINT

/**
 * Chapter 1.4
 * Variable assignment and initialization
 * (https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/)
 */
void chap1point4() {
	int a; // define variable (uninitialized)
	a = 5; // copy assignment of value 5 into 'a'

#ifdef PRINT
	std::cout << "a = " << a << '\n';
#endif

	int b = 7; // copy initialization of value 7 into 'b'

#ifdef PRINT
	std::cout << "b = " << b << '\n';
#endif

	int c(9); // direct initialization of value 9 into 'c'

#ifdef PRINT
	std::cout << "c = " << c << '\n';
#endif

	int d{ 2 }; // direct brace initialization of value 2 into 'd'

#ifdef PRINT
	std::cout << "d = " << d << '\n';
#endif

	int e{}; // direct brace zero initialization

#ifdef PRINT
	std::cout << "e = " << e << '\n';
#endif

	int f{ 0 }; // when using value immediately after
	int g{};    // when immediately replacing value

#ifdef PRINT
	std::cout << "f = " << f << '\n';
	std::cout << "g = " << g << '\n';
#endif
}

/**
 * Chapter 1.6
 * Tricks compiler into thinking parameter value is used
 * (https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/)
 */
void doNothing(int&) { }

/**
 * Chapter 1.7
 * All of the current keywords present in C++17
 * (https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/)
 */
void chap1point7() {
	std::string_view a{ "alignas   alignof   and        and_eq       asm       auto              bitand        bitor    bool          break\n" };
	std::string_view b{ "case      catch     char       char16_t     char32_t  class             compl         const    constexpr     const_cast\n" };
	std::string_view c{ "continue  decltype  default    delete       do        double            dynamic_cast  else     enum          explicit\n" };
	std::string_view d{ "export    extern    false      float        for       friend            goto          if       inline        int\n" };
	std::string_view e{ "long      mutable   namespace  new          noexcept  not               not_eq        nullptr  operator      or\n" };
	std::string_view f{ "or_eq     private   protected  public       register  reinterpret_cast  return        short    signed        sizeof\n" };
	std::string_view g{ "static    static_assert        static_cast  struct    switch            template      this     thread_local  throw\n" };
	std::string_view h{ "true      try       typedef    typeid       typename  union             unsigned      using    virtual       void\n" };
	std::string_view i{ "volatile  wchar_t   while      xor          xor_eq\n" };

	std::cout << a << b << c << d << e << f << g << h << i;
}

/**
 * Chapter 1.9
 * Introduction to expressions
 * (https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/)
 */
void chap1point9(void) {
	int x{ 17 }; // direct brace initialization
	int y{ x - 12 }; // expression within initialization

	std::cout << "x = " << x << "\ny = " << y << '\n';
}

/*
 * Chapter 4.6
 * Fixed-width integers and size_t
 * (https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/)
 */
void chap4point6() {
	// unsigned (avoid use as may not be defined on all target architectures)
	std::uint8_t  a{}; // (1) 0 to 255
	std::uint16_t b{}; // (2) 0 to 65,535
	std::uint32_t c{}; // (4) 0 to 4,294,967,295
	std::uint64_t d{}; // (8) 0 to 18,446,744,073,709,551,615

	// signed (avoid use as may not be defined on all target architectures)
	std::int8_t  e{}; // (1) -128 to 127 (may be interpreted as a char on some compilers)
	std::int16_t f{}; // (2) -32,768 to 32,767
	std::int32_t g{}; // (4) -2,147,483,648 to 2,147,483,647
	std::int64_t h{}; // (8) -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

	// fast integers (guaranteed minimum size, safe and recommended)
	std::int_fast16_t i{}; // at least 16 bits (2 bytes)
	std::int_fast32_t j{}; // at least 32 bits (4 bytes)
	std::int_fast64_t k{}; // at least 64 bits (8 bytes)

	// least integers (guaranteed actual size, safe and recommended)
	std::int_least16_t l{}; // guaranteed to be 16 bits (2 bytes)
	std::int_least32_t m{}; // guaranteed to be 32 bits (4 bytes)
	std::int_least64_t n{}; // guaranteed to be 64 bits (8 bytes)

	// std::size_t is the size of the largest object creatable on your system
}

/*
 * Chapter 4.9
 * Boolean values
 * (https://www.learncpp.com/cpp-tutorial/boolean-values/)
 */
void chap4point9() {
	// declaration
	bool isTrue{ true };

	// use std::boolalpha to print boolean values as 'true' or 'false'
	std::cout << std::boolalpha;
	std::cout << true << '\n';

	// use std::noboolalpha to return to normal printing
	std::cout << std::noboolalpha;
	std::cout << true << '\n';
}

/*
 * Chapter 4.11
 * Chars
 * (https://www.learncpp.com/cpp-tutorial/chars/)
 */
void chap4point11() {
	// use single quotes over double quotes in every applicable instance
	char c{ 'a' };

	// equally as valid as above, but not preferred
	char d{ 97 };

	// casting from one type to another
	//   static_cast<new_type>(expression)
	char e{ static_cast<char>(97) };

	// hex numbers can be printed by using '\x<hex>'
	std::cout << "6F in hex is char '\x6F'\n";
}

/*
 * Chapter 4.12
 * Literals
 * (https://www.learncpp.com/cpp-tutorial/literals/)
*/
void chap4point12() {
	// add suffix with upper or lowercase letter to specify type explicitly
	long x{ 5L };
	float y{ 4.3f };

	// no need to specify explicitly since any decimal will be converted to
	// double unless 'f' is appended to the end
	double z{ 6.02e23 };

	// assigning binary value using hexadecimal
	int bin{};
	bin = 0x01; // assign binary 0000 0001 to the variable
	bin = 0x02; // assign binary 0000 0010 to the variable
	bin = 0x04; // assign binary 0000 0100 to the variable
	bin = 0x08; // assign binary 0000 1000 to the variable
	bin = 0x10; // assign binary 0001 0000 to the variable
	bin = 0x20; // assign binary 0010 0000 to the variable
	bin = 0x40; // assign binary 0100 0000 to the variable
	bin = 0x80; // assign binary 1000 0000 to the variable
	bin = 0xFF; // assign binary 1111 1111 to the variable
	bin = 0xB3; // assign binary 1011 0011 to the variable

	// print in different formats
	std::cout << std::dec; // decimal (default)
	std::cout << std::hex; // hexadecimal
	std::cout << std::oct; // octal

	// to print binary, use std::bitset<num_bits>{expression}
	// useful for holding actual binary values and working with them
	std::cout << std::bitset<4>{ 0b1010 } << '\n';

	// magic numbers
	int numClassrooms{ 10 };
	int maxStudents{ numClassrooms * 30 }; // '30' is a MAGIC number
}

/*
 * Chapter 4.13
 * Const, constexpr and symbolic constants
 * (https://www.learncpp.com/cpp-tutorial/const-constexpr-and-symbolic-constants/)
 */
void chap4point13() {
	const double gravity{ 9.8 }; // value will not change

	// const is often used in function parameters
	// e.g.  void someFunc(const int age)
	// ----------------------------------
	// This tells the person calling the function that the function will not
	// change the value of the parameter, and it ensures that the function does
	// not change the value of the parameter.

	// constexpr needs to be able to be resolved at COMPILE time.
	// e.g.  constexpr int nextAge{ age + 1 };
	//       => not valid since 'age' is evaluated at RUNTIME.
	constexpr int nextAge{ 12 + 32 }; // valid since 12 + 32 can be resolved at COMPILE time

	// symbolic constants
	// - using preprocessor macros (#define <identifier> <substitution>)
	//   -> could break if including some file with a macro with the same name
	// - using constexpr variables (recommended)

	// inline function - removes a function call by copy/pasting the function
	// body into the call site (may create a larger executable).
	// inline function will be ignored if function contains
	// 1) a loop
	// 2) static variables
	// 3) recursive calls
	// 4) switch / goto statement

	// inline variable - guarantees that the variable will have the same
	// memory address no matter where it is called from or defined.

	// using constants in multiple files
	// 1) create header file to hold constants
	// 2) declare namespace inside header file
	// 3) add all constants to namespace
	// 4) #include header file wherever you need
	// e.g.:
	// constants.hpp
	// namespace constants {
	//   inline constexpr double pi{ 3.14159 };
	// }
	// use as following -> constants::pi
}

/*
 * Chapter 5.2
 * Arithmetic operators
 * (https://www.learncpp.com/cpp-tutorial/arithmetic-operators/)
 */
void chap5point2() {
	int x{ 7 };
	int y{ 4 };

	// the following shows that if any of the operands are a floating
	// point number, the result will be a floating point value
	std::cout << "int / int = " << x / y << '\n';
	std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
	std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';
}

/*
 * Chapter 5.3
 * Modulus and exponentiation
 * (https://www.learncpp.com/cpp-tutorial/5-3-modulus-and-exponentiation/)
 */
void chap5point3() {
	// modulus always takes the sign of the first operand
	constexpr int x{ -6 };
	constexpr int y{ 4 };
	constexpr int z{ -2 };

	std::cout << x << " % " << y << " = " << x % y << '\n'; // -2
	std::cout << x << " % " << z << " = " << x % z << '\n'; // 0
	std::cout << y << " % " << x << " = " << y % x << '\n'; // 4
	std::cout << y << " % " << z << " = " << y % z << '\n'; // 0
	std::cout << z << " % " << x << " = " << z % x << '\n'; // -2
	std::cout << z << " % " << y << " = " << z % y << '\n'; // -2
}

/*
 * Chapter 5.5
 * Comma and conditional operators
 * (https://www.learncpp.com/cpp-tutorial/comma-and-conditional-operators/)
*/
void chap5point5() {
	// comma separator is used to evaluate first expression and then second
	int x{ 1 };
	int y{ 2 };

	std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to right operand

	// conditional operator (always surround entire operator with parentheses)
	int larger = ((x > y) ? x : y);
}

/*
 * Optional chapter O.1
 * Bit flags and bit manipulation via std::bitset
 * (https://www.learncpp.com/cpp-tutorial/o-1-bit-flags-and-bit-manipulation-via-stdbitset/)
 */
void chapOpoint1() {
	// set initial bitset with 8 bits
	std::bitset<8> bits{ 0b0000'0101 };

	// available functions
	bits.set(3); // set bit position 3 to 1 (now have 0000 1101)
	bits.flip(4); // flip bit position 4 (now have 0001 1101)
	bits.reset(4); // set bit position 4 to 0 (now have 0000 1101)
	bits.test(1); // returns the value of the bit at position 1 (returns 0)
}

/*
 * Optional chapter O.2
 * Bitwise operators
 * (https://www.learncpp.com/cpp-tutorial/bitwise-operators/)
 */
void chapOpoint2() {
	// NB: only used unsigned integers for bit manipulation!

	unsigned int x{ 0b1010 };
	unsigned int res{};

	// [insert 0 at the end] left shift by 1 bit (1010 -> 0100)
	res = x << 1;

	// [insert 0 at the start] right shift by 1 bit (1010 -> 0101)
	res = x << 1;

	// bitwise not (flips every bit: 1010 -> 0101)
	res = ~x;

	// bitwise AND (&) returns true if both bits are true, false otherwise
	// 0 1 0 1  AND
	// 0 1 1 0
	// -------
	// 0 1 0 0

	// bitwise OR (|) returns false if both bits are false, true otherwise
	// 0 1 0 1  OR
	// 0 1 1 0
	// -------
	// 0 1 1 1

	// bitwise XOR (^) returns true if and only if one bit is true, false otherwise
	// 0 1 0 1  XOR
	// 0 1 1 0
	// -------
	// 0 0 1 1
}

/*
 * Optional chapter O.3
 * Bit manipulation with bitwise operators and bit masks
 * (https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/)
 */
void chapOpoint3() {
	// bit masks protect the bits we don't want altered and change the bits
	// we did want to change (use 0 to mask out bits we don't want changed,
	// and use 1 to denote the bits we want changed)
	constexpr std::uint_fast8_t mask0{ 0b0000'0001 };
	constexpr std::uint_fast8_t mask1{ 0b0000'0010 };
	constexpr std::uint_fast8_t mask2{ 0b0000'0100 };
	constexpr std::uint_fast8_t mask3{ 0b0000'1000 };

	std::uint_fast8_t check{ 0b0000'0101 };

	// ########  TEST  ########
	// check if bit 0 is on or off
	std::cout << "bit 0 is " << ((check & mask0) ? "on\n" : "off\n");
	// 0 0 0 0 0 1 0 1  AND
	// 0 0 0 0 0 0 0 1
	// ---------------
	// 0 0 0 0 0 0 0 1 (= 2^0 = 1 => true)

	// check if bit 1 is on or off
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	// 0 0 0 0 0 1 0 1  AND
	// 0 0 0 0 0 0 1 0
	// ---------------
	// 0 0 0 0 0 0 0 0 (= 0 => false)

	// ########  SET  ########
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	check |= mask1;
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	// 0 0 0 0 0 1 0 1  OR
	// 0 0 0 0 0 0 1 0
	// ---------------
	// 0 0 0 0 0 1 1 1

	// you can set multiple bits at the same time
	check |= (mask2 | mask3);

	// ########  RESET  ########
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	check &= ~mask1;
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	// 0 0 0 0 0 0 1 0  NOT
	// ---------------
	// 1 1 1 1 1 1 0 1
	//
	// 0 0 0 0 0 1 1 1  AND
	// 1 1 1 1 1 1 0 1
	// ---------------
	// 0 0 0 0 0 1 0 1

	// you can reset multiple bits at the same time
	check &= ~(mask2 | mask3);

	// ########  FLIP  ########
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");
	check ^= mask1;
	std::cout << "bit 1 is " << ((check & mask1) ? "on\n" : "off\n");

	// you can flip multiple bits at the same time
	check ^= (mask2 | mask3);

	// most useful for passing in options to a function, so instead of
	// | void someFunc(bool option1, bool option2, ..., bool option 32) |
	// we can have
	// | void someFunc(std::bitset<32> options) |
	// then call with
	// someFunc(option2 | option10)
}

/*
 * Chapter 6.2
 * User defined namespaces
 * (https://www.learncpp.com/cpp-tutorial/user-defined-namespaces/)
 */
void chap6point2() {
	// declaring namespace
	// namespace foo {
	//     int sum(int x, int y) {
	//         return x + y;
	//     }
	// }
	// then use it as foo::sum(x, y)

	// :: is called the 'scope resolution modifier'
	// calling a function in the global namespace can be done by
	// ::funcName  [no prefix]

	// namespace with same name can have functions added to it in different
	// files, so you can actually add functions to the `std` namespace if you
	// wanted

	// you can alias namespaces, for example
	// namespace boo = foo::goo;
}

/*
 * Chapter 6.4
 * Introduction to global variables
 * (https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/)
 */
void chap6point4() {
	// global variables, declare with g_
	// zero-initialized by default

	// internal linkage - can be seen and used within a single file, but
	// not accessible from other files
	// => also known as 'internal' variables

	// external linkage - can be seen and used across multiple files
	// => also known as 'external' variables

	// non-constant global variables have external linkage by default
	// 'static' (storage class specifier) keyword gives variable internal linkage
	// 'const' has internal linkage by default
	// 'constexpr' has internal linkage by default
}

/*
 * Chapter 6.7
 * External linkage
 * (https://www.learncpp.com/cpp-tutorial/external-linkage/)
 */
void chap6point7() {
	// convert variables/functions with internal linkage to external by using
	// extern <type> <name>
	// eg: extern const int g_x{ 1 }; will convert g_x to an external variable

	// inline global variables have external linkage by default
	// prefer using
	// inline constexpr <name>{ <value> };
	// in a namespace than using 'extern'
}

/*
 * Chapter 6.13
 * Typedefs and type aliases
 * (https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/)
 */
void chap6point13() {
	// typedef => type definition, allows programmer to create alias for
	// a data type (usually suffixed with a "_t"
	// 'typedef <data_type> <alias>'   (type definition)  OR
	// 'using <alias> = <data_type>'   (type alias)
	typedef double distance_t;
	using speed_t = double;

	distance_t distanceTravelled{ 300 };
	speed_t carSpeed{ 118.5 };
}

/*
 * Chapter 6.14
 * The auto keyword
 * (https://www.learncpp.com/cpp-tutorial/the-auto-keyword/)
 */
void chap6point14() {
	// during initialization, you can tell C++ to infer the correct type using 'auto'
	// the below two statements are the same
	double a{ 5.0 };
	auto b{ 5.0 };

	// auto can be used for function return types (NOT RECOMMENDED)
	// e.g.  auto add(int x, int y) { return x + y }
	// will return a value of type int

	// you can use 'trailing return syntax' to make all forward declarations of
	// functions line up
	// e.g.  auto add(int x, int y) -> int;
	//       auto divide(double x, double y) -> double;
	//       auto substr(const std::string &s, int start, int len) -> std::string;

	// DO NOT USE 'auto' FOR FUNCTION PARAMETERS
	// instead use 'function templates'
}

/*
 * Chapter 6.15
 * Implicit type conversion (coercion)
 * (https://www.learncpp.com/cpp-tutorial/implicit-type-conversion-coercion/)
 */
void chap6point15() {
	// two type conversions:
	// - implicit => compiler transforms one data type into another
	//     e.g.  double d{ 3 };  => compiler converts int 3 into a double
	// - explicit => developer uses casting operator to direct the conversion
	//     e.g.  double d{ static_cast<double>(3) };

	// numeric promotion
	long l{ 64 }; // widen integer 64 into a long
	double d{ 0.12f }; // promote float 0.12 into a double

	// integral promotion => conversion of integer types narrower than int (bool,
	// char, unsigned char, short, unsigned short) to an int (if possible), or
	// unsigned int otherwise (usually involves adding leading 0s)

	// floating point promotion => conversion of float to double

	// std::cout << std::setprecision(9);
	// sets the precision to print to in the console (#include <iomanip>)

	int a{ 4 };
	int b{ 5 };

	// show the type of an expression
	std::cout << typeid(a + b).name() << ' ' << a + b << '\n';

	// when two operands are of a different type, the following priority applies:
	// - long double (highest)
	// - double
	// - float
	// - unsigned long long
	// - long long
	// - unsigned long
	// - long
	// - unsigned int
	// - int (lowest)
	// ==> e.g. if one operand is a 'long double' and the other operand is an
	//          'int', both operands will be cast to 'long double' since it has
	//          a higher priority
}

/*
 * Chapter 6.16
 * Explicit type conversion (casting)
 * (https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
 */
void chap6point16() {
	// AVOID const casts AND reinterpret casts UNLESS GOOD REASON TO USE THEM
	// AVOID C-style casts => float f{ (float) 1 / 2 };

	// favour static casts when converting from one fundamental type to another
	int a{ 10 };
	int b{ 4 };
	float f{ static_cast<float>(a) / b };
}

/*
 * Chapter 6.17
 * Unnamed and inline namespaces
 * (https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/)
 */
void chap6point17() {
	// unnamed namespace is typically used when you have a lot of content that you
	// want to ensure stays local to the file, instead of individually marking each
	// declaration as static
	// e.g.   namespace { void sayHello() { std::cout << "Hello\n"; } }

	// inline namespaces will be used when no scope resolution modifier (::) is
	// provided
	// for example:
	// inline namespace v1 { void sayHi() { std::cout << "Hi\n"; } }
	// namespace v2 { void sayHi() { std::cout << "Hello\n"; } }
	// v1::sayHi()  =>  calls sayHi from namespace v1
	// v2::sayHi()  =>  calls sayHi from namespace v2
	// sayHi()      =>  calls sayHi from namespace v1
}

/*
 * Chapter S.4.4b
 * An introduction to std::string
 * (https://www.learncpp.com/cpp-tutorial/4-4b-an-introduction-to-stdstring/)
 */
void chapSpoint4b() {
	// declare string
	std::string myName{ "Kyle" };

	// getting input from std::cin only reads until first whitespace
	// use std::getline instead to get the full line
	std::cout << "Enter your name: ";
	std::string enteredName{};
	std::getline(std::cin, enteredName);

	// if you use std::cin then std::getline, you may run into problems
	// => ignore characters using
	//   std::cin.ignore(32767, '\n')  OR
	//   std::cin.ignore(std::numeric_limits<sttd::streamsize>::max(), '\n')
	// which ignores up to 32767 characters until a \n is removed
	// std::numeric_limits needs #include <limits>

	// get length of string
	int nameLength{ static_cast<int>(myName.length()) };

	// get character at index
	char a{ myName.at(1) };
	char b{ myName[1] };
}

/*
 * Chapter S.4.5
 * Enumerated types
 * (https://www.learncpp.com/cpp-tutorial/45-enumerated-types/)
 */
void chapSpoint5() {
	// use an enum to represent options
	// enum Result {
	//     RESULT_SUCCESS,            // (0)
	//     RESULT_ERROR_OPENING_FILE, // (1)
	//     RESULT_ERROR_READING_FILE  // (2)
	// }
	// only problem is that the enum values can conflict with
	// preprocessor macros

	// you can forward-declare an enum, but you have to specify its type
	// enum Color : int;
	// then you need to include the base when defining it
	// enum Color : int {
	//     ...
	// }

	// problem with enum types is the following:
	// enum Color { COLOR_RED, COLOR_BLUE };
	// enum FRUIT { FRUIT_APPLE, FRUIT_BANANA };
	// Color col{ COLOR_RED };
	// Fruit fruit{ FRUIT_APPLE };
	// (col == fruit) => returns true, even though they are from different enums

	// fix is to use enum classes
	//   enum class Color { RED };
	// call with
	//   Color col{ Color::RED };
}

/*
 * Chapter S.4.7
 * Structs
 * (https://www.learncpp.com/cpp-tutorial/47-structs/)
 */
void chapSpoint7() {
	// struct can aggregate variables of different data types
	struct Person {
		std::string name;
		int age;
		double bmi;
	};

	// define as follows
	Person me{ "Kyle", 21, 18.8 };
	Person beb{ "Beb", 21 }; // `bmi` will default to a zero value

	// interact using the dot '.'
	int meAge{ me.age };
	me.bmi += 0.3;

	// you can set default values for a struct
	struct Rectangle {
		double width{ 1.0 };
		double height{ 1.0 };
	};

	// we can get the zero of any struct by using the curly braces
	//  Point3D getZeroPoint() {
	//      return {};
	//  }
	//  OR
	//  Point3D getZeroPoint() {
	//      return { 0.0, 0.0, 0.0 };
	//  }
	// to be more explicit, but will have to change number of 0s if update struct parameters

	// to use struct across many files, put struct declaration in header file
	// and #include header
}

/*
 * Chapter 5.9
 * Random number generation
 * (https://www.learncpp.com/cpp-tutorial/59-random-number-generation/)
 */
void chap5point9() {
	// set seed to time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// get random number
	int rand{ std::rand() };

	// get random number between range, where RAND_MAX ~= 32767
	//  int getRandomNumber(int min, int max) {
	//      static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // only calculates value once
	//      return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	//  }

	// when debugging using a random number, set the seed to a concrete
	// value so that the same random numbers are generated every time

	// Mersenne Twister PRNG
	//  #include <random> // for std::mt19937
	//  namespace Rand {
	//      std::mt19937 mersenne{ static_cast<std::mt19937::result_type> };
	//  }
	//  int getRandomNumber(int min, int max) {
	//      std::uniform_int_distribution die{ min, max }; // create distribution in any function that needs it
	//      return die(Rand::mersenne);
	//  }
}

/*
 * Chapter P.6.1
 * Arrays (Part I)
 * (https://www.learncpp.com/cpp-tutorial/61-arrays-part-i/)
 */
void chapPpoint1() {
	// zero initialize array of size 4
	double someArray[4]{};

	// initialize array with elements (let compiler decide how many elements)
	int theArray[]{ 1, 2, 3, 4 };

	// array size has to be compile-time constant
	// cannot be some variable that is read in from command-line for example
}

/*
 * Chapter P.6.2
 * Arrays (Part II)
 * (https://www.learncpp.com/cpp-tutorial/62-arrays-part-ii/)
 */
void chapPpoint2() {
	// if array has greater size than declaration, rest will be zeros
	int prime[5]{ 1, 3, 5, 7 };

	// use enums to get the elements (allows you to add more students and keeps track of size)
	enum StudentNames {
		KYLE,
		JENNA,
		FRANNA,
		ANTON,
		MAX_STUDENTS
	};

	// initialize as follows
	int testScores[MAX_STUDENTS]{};
	testScores[KYLE] = 76;

	// does not work with enum classes, since they don't automatically convert to int
	enum class OtherStudents {
		BEB,
		ADRIAN,
		RONALDO,
		AIDAN,
		MAX_STUDENTS
	};

	// use static_cast for enum classes
	int otherTestScores[static_cast<int>(OtherStudents::MAX_STUDENTS)]{};
	otherTestScores[static_cast<int>(OtherStudents::RONALDO)] = 21;

	// however, this is a pain so we use enum inside of namespace
	//   namespace MoreStudents {
	//	     enum SomeMoreStudents {
	//		     DECLAN,
	//		     MORNE,
	//		     JARROD,
	//		     MAX_STUDENTS
	//	     };
	//  }
	// then use like
	// int testScores[MoreStudents::MAX_STUDENTS]{};

	// function parameters are pass-by-value, but arrays are
	// pass-by-reference
	// to not alter the array passed as a parameter, we can use
	//   func(const <array_type> <array_name>[<num_elements>])

	// find size of array using std::size() [need to #include <iterator>]
	int findingSize[]{ 1, 2, 3, 4, 5, 6 };
	int sizeOfArray1{ static_cast<int>(std::size(findingSize)) }; // added in C++17

	// find size of array using sizeof()
	int sizeOfArray2{ sizeof(findingSize) / sizeof(findingSize[0]) };
}

/*
 * Chapter P.6.4
 * Sorting using selection sort
 * (https://www.learncpp.com/cpp-tutorial/64-sorting-an-array-using-selection-sort/)
 */
void chapPpoint4() {
	// selection sort
	int arr[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(arr)) };

	// last element will already be sorted when we get there
	for (int i{ 0 }; i < length - 1; ++i) {
		// assume smallest element is first element
		int minIdx{ i };

		// look for smaller element
		for (int j{ i + 1 }; j < length; ++j) {
			if (arr[j] < arr[i]) {
				minIdx = j;
			}
		}

		// swap indices
		std::swap(arr[i], arr[minIdx]);
	}

	// alternatively, use std::sort() from <algorithm> header
	int otherArr[]{ 30, 50, 20, 10, 40 };

	// sorts in-place
	std::sort(std::begin(otherArr), std::end(otherArr));
}

/*
 * Chapter P.6.5
 * Multidimensional arrays
 * (https://www.learncpp.com/cpp-tutorial/65-multidimensional-arrays/)
 */
void chapPpoint5() {
	// order is [<num_rows>][<num_cols>]
	// can only omit left-most length specifier
	int arr[][3]{ {1, 2, 3}, {4, 5, 6} };
}

/*
 * Chapter P.6.6a
 * An introduction to std::string_view
 * (https://www.learncpp.com/cpp-tutorial/6-6a-an-introduction-to-stdstring_view/)
 */
void chapPpoint6() {
	// can create strings using a character array
	char text[]{ "hello" };

	// copies value into a seperate string object
	std::string str1{ text };
	std::string str2{ str1 };

	// string_view is simply a view onto a string
	// i.e. does not copy string, instead refers to original string
	// any operation done to string is changed in original string

	// std::string and std::string_view cannot be concatenated
	// if std::string_view refers to string that is out of scope, causes
	// undefined behaviour
}

/*
 * Chapter P.6.7
 * Introduction to pointers
 * (https://www.learncpp.com/cpp-tutorial/67-introduction-to-pointers/)
 */
void chapPpoint7() {
	// define normal variable
	int x{ 5 };

	// store address of (&) variable in pointer
	int *addrX{ &x };

	// store value of (*), a.k.a dereference, variable
	int valX{ *(&x) };

	// for variables => put asterisk next to variable name
	// for functions => put asterisk next to return type

	// pointer size depends on size of type the pointer is storing
	// i.e.  int => pointer of size 4 bytes
	//       char => pointer of size 1 byte
}

/*
 * Chapter P.6.7a
 * Null pointers
 * (https://www.learncpp.com/cpp-tutorial/6-7a-null-pointers/)
 */
void chapPpoint7a() {
	// use nullptr to denote a null pointer
	int *x{ nullptr };

	// can specify null pointer to function by using null pointer type
	std::nullptr_t ptr{ nullptr };
}

/*
 * Chapter P.6.8a
 * Pointer arithmetic and array indexing
 * (https://www.learncpp.com/cpp-tutorial/6-8a-pointer-arithmetic-and-array-indexing/)
 */
void chapPpoint8a() {
	// arrays *decay* into a pointer that points to the first element
	int arr[]{ 1, 2, 3, 4, 5 };

	// we can index into array using pointers { arr[n] == *(arr + n) }
	int firstElem{ *arr };
	int secondElem{ *(arr + 1) };

	// trying to print address of character pointer will print garbage
}

/*
 * Chapter P.6.9
 * Dynamic memory allocation with new and delete
 * (https://www.learncpp.com/cpp-tutorial/69-dynamic-memory-allocation-with-new-and-delete/)
 */
void chapPpoint9() {
	int *ptr{ new int }; // dynamically allocate an integer
	*ptr = 7;            // assign value to memory allocated

	delete ptr; // return memory to operating system

	// any further references to ptr will cause undefined behaviour (dangling pointer)

	int *otherPtr{ new int{ 7 } }; // use uniform initialization for dynamic variable

	// check if memory has been allocated
	int *val{ new (std::nothrow) int{} }; // val will be set to nullptr if allocation fails
	if (!val) {
		std::cout << "Could not allocate memory";
	}

	// have to delete to stop memory leaks (does nothing if val == nullptr)
	delete val;

	// if dynamically allocated variable does not get deleted,
	// can cause memory leak since the address is lost when variable
	// goes out of scope
}

/*
 * Chapter P.6.9a
 * Dynamically allocating arrays
 * (https://www.learncpp.com/cpp-tutorial/6-9a-dynamically-allocating-arrays/)
 */
void chapPpoint9a() {
	// dynamic array allocation
	std::size_t arrLength{ 2 }; // needs to be size_t or use a static_cast<std::size_t>(...)
	int *arr{ new int[arrLength] };

	// dynamic array deletion
	delete[] arr;

	// show differences between const pointers and normal pointers
	int val{ 5 };
	const int *ptr1 = &val; // ptr1 points to "const int" => pointer to constant value
	int *const ptr2 = &val; // ptr2 points to an "int" => const pointer to non-const value
	const int *const ptr3 = &val; // ptr3 points to "const int" => constant pointer to const value
}

/*
 * Chapter P.6.11
 * References
 * (https://www.learncpp.com/cpp-tutorial/611-references/)
 */
void chapPpoint11() {
	// keep reference to value
	int value{ 5 };
	int &ref{ value };

	// setting or getting the value from a reference will alter the original value
	// l-value (ell-value) is value that has an address in memory
	// r-value (arr-value) is value that is not an l-value

	// when needing to change the value of a variable, use a reference as the parameter
	// i.e.
	//   void changeN(int &ref) {
	//       ref = 6;
	//   }
	//   int main() {
	//       int n{ 5 };
	//       std::cout << n << '\n';
	//       changeN(n);
	//       std::cout << n << '\n';
	//       return 0;
	//   }

	// can be used to reference nested values in structs, for example:
	struct Point {
		float x;
		float y;
	};

	struct Rectangle {
		Point p1;
		Point p2;
		Point p3;
		Point p4;
	};

	Rectangle rect{};
	float &fx{ rect.p1.x }; // access nested float

	// member selection using pointer to struct
	Rectangle *r{ &rect };
	(*r).p1.x = 21.3; // valid
	r->p1.x = 22.4;   // equally valid and preferred
}

/*
 * Chapter P.6.12a
 * For-each loops
 * (https://www.learncpp.com/cpp-tutorial/6-12a-for-each-loops/)
 */
void chapPpoint12() {
	// looping over array using for-each
	constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13 };
	for (int num : fibonacci) { // copies each element from array
		std::cout << num << ' ';
	}
	std::cout << '\n';

	// using 'auto' keyword is better than typing entire type
	// using 'const' keyword is preferred when not changing value
	// using '&' (reference) is preferred if the elements are NON-FUNDAMENTAL data types
	std::string names[]{ "Kyle", "Beb", "Declan" };
	for (const auto &name : names) {
		std::cout << name << ' ';
	}
	std::cout << '\n';
}

/*
 * Chapter P.6.13
 * Void pointers
 * (https://www.learncpp.com/cpp-tutorial/613-void-pointers/)
 */
void chapPpoint13() {
	// void pointers can point to any data type
	int val{ 5 };
	void *ptr{ &val };

	// in order to use it, pointer must be explicitly cast to another type
	int *intPtr{ static_cast<int*>(ptr) };

	// used mainly for passing to functions
	// i.e.  printPointer(void *ptr)
	// can call `printPointer(int *ptr)`
}

/*
 * Chapter P.6.15
 * An introduction to std::array
 * (https://www.learncpp.com/cpp-tutorial/6-15-an-introduction-to-stdarray/)
 */
void chapPpoint15() {
	// create array
	std::array numbers{ 0, 1, 2, 3, 4 };

	// can use [] or .at to get element
	int someNum{ numbers[2] }; // no bounds-checking
	someNum = numbers.at(1);   // bounds-checking

	// get the length of the array
	int len = numbers.size();

	// always pass std::array by reference or const reference

	// can sort in ascending or descending order
	std::sort(numbers.begin(), numbers.end());   // increasing order
	std::sort(numbers.rbegin(), numbers.rend()); // decreasing order

	// can use for-each
	for (int num : numbers) {
		std::cout << num << ' ';
	}
	std::cout << '\n';

	// BE CAREFUL when using a normal for loop because `size` returns size_type (unsigned)
	// use 'std::size_t' keyword for index variable, since std::array::size_type is alias for std::size_t
	for (std::size_t i{ 0 }; i < numbers.size(); ++i) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';

	// reverse for loop DOES NOT work like you think
	// the below code produces an infinite loop
	// 1) for (auto i{ numbers.size() - 1 }; i >= 0; --i) {
	// 2)     ...
	// 3) }
	// this is because the result of `numbers.size() - 1` will be an unsigned int,
	// thus always >= 0

	// WORKING reverse for loop, but looks odd
	for (auto i{ numbers.size() }; i-- > 0; ) {
		std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';
	// works because we decrement after comparison, so it wraps around for
	// the last time, but we don't use that result

	// cannot brace initialize an array of structs

	// std::array - fixed size array
	// std::vector - dynamically allocated array (allows for resize)
}

/*
 * Chapter P.6.18
 * Introduction to standard library algorithms
 * (https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/)
 */
void chapPpoint18() {
	std::array numbers{ 1, 2, 3, 4, 8 };
	int search{ 5 };

	// find an element in array, returning end if not found or iterator pointing to element
	auto found{ std::find(numbers.begin(), numbers.end(), search) };

	// check if found element
	if (found == numbers.end()) {
		std::cout << "Could not find " << search << '\n';
	}

	// check if string array contains string
	std::array<std::string_view, 4> arr{ "apple", "banana", "orange", "lemon" };
	bool contains = arr[0].find("nana") != std::string_view::npos;

	// use std::for_each to apply a function to each element in array
	// std::for_each(arr.begin(), arr.end(), doubleNum);

	// vector used for dynamic arrays
	std::vector someVec{ "hi", "there" };
}

/*
 * Chapter F.7.4
 * Passing arguments by value, reference and address
 * (https://www.learncpp.com/cpp-tutorial/74-passing-arguments-by-address/)
 */
void chapFpoint4() {
	// pass by value
	//  - copies value from parameter and is destroyed after function call
	//  - best used for passing primitive data types
	//  - e.g:  void func(int val);

	// pass by reference
	//  - uses actual value from parameter, so changing param is possible
	//  - best used for passing non-primitive data types and to change parameter
	//  - e.g:  void func(std::array &arr);

	// pass by address
	//  - uses the address of the value as a parameter (actually decays to pass-by-value)
	//  - prefer pass-by-reference instead
	//  - e.g:  void func(int *x);


	// return by value
	//  - best used when returning variables that were declared inside function
	//  - e.g:  int func(int val);

	// return by reference
	//  - best used when returning variables that were passed by reference or when returning a struct/class
	//  - e.g:  std::array& func(std::array &arr);

	// return by address
	//  - best used when returning dynamically allocated memory
	//  - e.g:  int* func(int *val);

	// `static` inside function ensures variable is not destroyed when function ends
}

