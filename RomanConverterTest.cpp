#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
   string roman{""};
   while (arabic >= 10)
   {
      roman += "X";
      arabic -= 10;
   }
   while (arabic-- > 0)
      roman += "I";
   return roman;
}
// END:convert

// START:test
TEST(RomanConverter, CanConvertPositiveDigits) {
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
   EXPECT_THAT(convert(3), Eq("III"));
   EXPECT_THAT(convert(10), Eq("X"));
   EXPECT_THAT(convert(11), Eq("XI"));
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
// START:assert20
   EXPECT_THAT(convert(20), Eq("XX"));
// END:assert20
}
// END:test
