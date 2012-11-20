#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
   if (arabic == 2)
      return "II";
   return "I";
}
// END:convert

// START:test
TEST(RomanConverter, CanConvertPositiveDigits) {
   ASSERT_THAT(convert(1), Eq("I"));
   ASSERT_THAT(convert(2), Eq("II"));
}
// END:test
