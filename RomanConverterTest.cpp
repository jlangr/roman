#include "gmock/gmock.h"

#include <vector>
#include <string>

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
   static auto arabicToRomanConversions = {
      make_pair(10u, "X"), 
      make_pair(1u, "I") };

   string roman("");
   for (auto arabicToRoman: arabicToRomanConversions) 
      while (arabic >= arabicToRoman.first)
      {
         roman += arabicToRoman.second;
         arabic -= arabicToRoman.first;
      }
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
