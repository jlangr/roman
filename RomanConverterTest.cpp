#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

string convert(unsigned int arabic)
{
   return "I";
}

// START:test
TEST(RomanConverter, CanConvertPositiveDigits) {
   EXPECT_THAT(convert(1), Eq("I"));
}
// END:test
