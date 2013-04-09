#include "gmock/gmock.h"

#include <vector>
#include <string>

using namespace ::testing;
using namespace std;

// START:convert
string convert(unsigned int arabic) 
{
// START:convertTable
   static auto arabicToRomanConversions = {
      make_pair(100u, "C"), 
      make_pair(50u, "L"), 
      make_pair(10u, "X"), 
      make_pair(5u, "V"), 
// START_HIGHLIGHT
      make_pair(4u, "IV"), 
// END_HIGHLIGHT
      make_pair(1u, "I") };
// END:convertTable

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
// START:convert4
   EXPECT_THAT(convert(4), Eq("IV"));
// END:convert4
   EXPECT_THAT(convert(5), Eq("V"));
   EXPECT_THAT(convert(10), Eq("X"));
   EXPECT_THAT(convert(11), Eq("XI"));
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
   EXPECT_THAT(convert(20), Eq("XX"));
   EXPECT_THAT(convert(50), Eq("L"));
   EXPECT_THAT(convert(80), Eq("LXXX"));
   EXPECT_THAT(convert(100), Eq("C"));
   EXPECT_THAT(convert(288), Eq("CCLXXXVIII"));
}
// END:test
