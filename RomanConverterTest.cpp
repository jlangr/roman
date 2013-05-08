#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
   string roman{""};
   while (arabic-- > 0)
      roman += "I";
   return roman;
}
// END:convert

// START:test
TEST(RomanConverter, CanConvertPositiveDigits) {
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
// START:assert3
   EXPECT_THAT(convert(3), Eq("III"));
// END:assert3
}
// END:test
