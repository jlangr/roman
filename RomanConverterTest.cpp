#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
   string roman("");
   if (arabic >= 10)
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
// START:assert11
   EXPECT_THAT(convert(11), Eq("XI"));
// END:assert11
// START:assert12and13
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
// END:assert12and13
}
// END:test
