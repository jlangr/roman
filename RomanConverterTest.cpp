#include "gmock/gmock.h"

#include <vector>
#include <string>

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
// START:convertTable
   const auto arabicToRomanConversions = {
      make_pair(10u, "X"), 
// START_HIGHLIGHT
      make_pair(5u, "V"), 
// END_HIGHLIGHT
      make_pair(1u, "I") };
// END:convertTable

   string roman{""};
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
// START:additionalAsserts
   EXPECT_THAT(convert(5), Eq("V"));
// END:additionalAsserts
   EXPECT_THAT(convert(10), Eq("X"));
   EXPECT_THAT(convert(11), Eq("XI"));
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
   EXPECT_THAT(convert(20), Eq("XX"));
}
// END:test
