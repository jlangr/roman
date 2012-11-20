#include "gmock/gmock.h"

#include <vector>
#include <string>

using namespace ::testing;
using namespace std;

string convert(unsigned int arabic) 
{
   static auto arabicToRomanConversions = {
      make_pair(1000, "M"), 
      make_pair(900, "CM"), 
      make_pair(500, "D"), 
      make_pair(400, "CD"), 
      make_pair(100, "C"), 
      make_pair(90, "XC"), 
      make_pair(50, "L"), 
      make_pair(40, "XL"), 
      make_pair(10, "X"), 
      make_pair(9, "IX"), 
      make_pair(5, "V"), 
      make_pair(4, "IV"), 
      make_pair(1, "I") };

   string roman("");
   for (auto arabicToRoman: arabicToRomanConversions) 
      while (arabic >= arabicToRoman.first)
      {
         roman += arabicToRoman.second;
         arabic -= arabicToRoman.first;
      }
   return roman;
}

TEST(RomanConverter, CanConvertPositiveDigits) {
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
   EXPECT_THAT(convert(3), Eq("III"));
   EXPECT_THAT(convert(4), Eq("IV"));
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
   EXPECT_THAT(convert(2999), Eq("MMCMXCIX"));
   EXPECT_THAT(convert(3447), Eq("MMMCDXLVII"));
   EXPECT_THAT(convert(1513), Eq("MDXIII"));
}

