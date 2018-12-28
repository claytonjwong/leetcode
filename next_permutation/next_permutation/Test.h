#ifndef TEST_H
#define TEST_H

// Test is a base class for all tests.  It provides a command interface for
// running tests (run) as well as a data member for recording the name of
// the test.
//
// Tests are constructed using the TEST macro.  TEST creates a subclass of
// Test and static instance of that subclass.  If you look at the constructor
// for the Test class, you'll notice that it registers the created object
// with a global TestRegistry.  These features combine to make test creation
// particularly easy.

#include <cmath>
#include <vector>
#include <sstream>
#include <string>

#include "TestResult.h"
#include "Failure.h"

class Test
{
public:
    Test (const std::string& testName,
          std::string fileName,
          long lineNumber);

	virtual ~Test();

    const std::string& getFileName() const;
    const long& getLineNumber() const;
    const std::string& getName() const;
    void run (TestResult& result);
    virtual void runTest (TestResult& result) = 0;

private:
    std::string     myFileName;
    long            myLineNumber;
    std::string     myName;
};

#define TEST(name,classUnderTest)\
    class classUnderTest##name##Test : public Test\
    { \
        public: \
            classUnderTest##name##Test () \
            : \
                Test ("TEST(" #name ", " #classUnderTest ")", \
                      __FILE__, __LINE__) {} \
            void runTest (TestResult& rEsUlT_); \
    } classUnderTest##name##Instance; \
    void classUnderTest##name##Test::runTest (TestResult& rEsUlT_)


// Here is a collection of testing macros that can be used in the
// bodies of tests.  CHECK tests a boolean expression and records
// a failure if the expression evaluates to false.  CHECK_LONGS_EQUAL
// and CHECK_DOUBLES_EQUAL check_equal_compare longs and doubles respectively.
//
// To make this an industrial strength test harness, you should
// add equals macros for various low level types as you develop them.
// If, for instance, you have a daterange class, the ability to check_equal_compare
// them directly and print out their values in the test output is
// invaluable.

#define CHECK(condition) \
{\
    if (!(condition)) { \
        rEsUlT_.addFailure (Failure (#condition, __FILE__, __LINE__)); \
        return; \
    }\
}

#define CHECK_LONGS_EQUAL(expected,actual)\
{\
    long _expected = (expected);\
    long _actual = (actual);\
    if (_expected != _actual) {\
        std::ostringstream message; \
        message << "expected '" << (_expected) << "' but was '" << (_actual) << "'"; \
        rEsUlT_.addFailure (Failure (message.str(), __FILE__, __LINE__));\
        return; \
    }\
}

#define CHECK_DOUBLES_EQUAL(expected,actual,threshold)\
{\
    double _expected = (expected);\
    double _actual = (actual);\
    if (fabs ((_expected)-(_actual)) > (threshold)) {\
        std::ostringstream message; \
        message << "expected '" << (_expected) << "' but was '" << (_actual) << "'"; \
        rEsUlT_.addFailure (Failure (message.str(), __FILE__, __LINE__));\
        return; \
    }\
}

#define CHECK_FAIL(text) \
{\
    rEsUlT_.addFailure (Failure ((text), __FILE__, __LINE__)); \
    return; \
}

// The following check for equality.
//
// The things being check_equal_compared must have an ostream or wostream inserters.
//
// BEWARE: The arguments are evaluated more than once!
//         If this is a problem then use CHECK instead.


// Use this when the things being check_equal_compared have a wostream inserter.


inline void compare(const wchar_t* const expected, const wchar_t* const actual, TestResult& result, const char* file, int line)
{
    if (wcscmp((expected), (actual)) != 0) {
        std::ostringstream message;
        message << "expected '" << (expected) << "' but was '" << (actual) << "'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}

template <typename T, typename U> void check_equal_wcompare(T expected, U actual, TestResult& result, const char* file, int line)
{
    if (! ((expected) == (actual))) {
        std::wostringstream message;
        message << L"expected '" << (expected) << L"' but was '" << (actual) << L"'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}

inline void check_equal_compare(const wchar_t* expected, const wchar_t* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(wchar_t* expected, wchar_t* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(const wchar_t* expected, wchar_t* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(wchar_t* expected, const wchar_t* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

#define CHECK_WEQUAL(expected, actual)\
{\
	check_equal_wcompare(expected, actual, rEsUlT_, __FILE__, __LINE__); \
}

// Use this when the things being check_equal_compared have an ostream inserter.

template <typename T, typename U> void check_equal_compare(T expected, U actual, TestResult& result, const char* file, int line)
{
    if (! ((expected) == (actual))) {
        std::ostringstream message;
        message << "expected '" << (expected) << "' but was '" << (actual) << "'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}

inline void compare(const char* expected, const char* actual, TestResult& result, const char* file, int line)
{
    if (strcmp((expected), (actual)) != 0) {
        std::ostringstream message;
        message << "expected '" << (expected) << "' but was '" << (actual) << "'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}

inline void check_equal_compare(const char* expected, const char* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(char* expected, char* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(const char* expected, char* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

inline void check_equal_compare(char* expected, const char* actual, TestResult& result, const char* file, int line)
{
    compare(expected, actual, result, file, line);
}

#define CHECK_EQUAL(expected, actual)\
{\
	check_equal_compare(expected, actual, rEsUlT_, __FILE__, __LINE__); \
}

#endif
