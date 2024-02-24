// Copyright [2024] <>
#include "../include/mystring.hpp"

using std::cout;
using std::cin;

int main() {
  MyString str1 = MyString("abc");
  MyString str2 = MyString(string("def"));
  MyString str3;
  str3 = str3 + str2;
  MyString str4 = str2 + str1;
  MyString str5 = MyString(str4);
  MyString str6 = str1 + str2 + str4;
  MyString str7 = MyString("QWE");

  cout << "Constructors and additions\n";
  cout << "str1 = " << str1 << '\n';
  cout << "str2 = " << str2 << '\n';
  cout << "str3 = " << str3 << '\n';
  cout << "str4 = " << str4 << '\n';
  cout << "str5 = " << str5 << '\n';
  cout << "str6 = " << str6 << '\n';
  cout << "str7 = " << str7 << '\n';

  cout << "\nAdditions\n";
  cout << "str4 + str5 = " << str4 + str5 << '\n';
  cout << "str1 + str2 + str4 = " << str1 + str2 + str4 << '\n';

  cout << "\nSubstructions\n";
  cout << "str4 - str1 = " << str4 - str1 << '\n';
  cout << "str4 - str5 = " << str4 - str5 << '\n';
  cout << "str1 - str5 = " << str1 - str5 << '\n';
  cout << "str6 - str1 = " << str6 - str1 << '\n';

  cout << "\nMultiplications\n";
  cout << "str1 * 10 = " << str1 * 10 << '\n';
  cout << "str1 * 1 = " << str1 * 1 << '\n';
  cout << "str1 * 0 = " << str1 * 0 << '\n';

  cout << "\nEquality tests\n";
  cout << "str1 == str2 = " << (str1 == str2) << '\n';
  cout << "str1 == str1 = " << (str1 == str1) << '\n';
  cout << "str1 != str2 = " << (str1 != str2) << '\n';
  cout << "str1 != str1 = " << (str1 != str1) << "\n";

  cout << "\nLexicographical comparisons\n";
  cout << "str1 > str2 = " << (str1 > str2) << '\n';
  cout << "str1 < str2 = " << (str1 < str2) << '\n';
  cout << "str1 > str1 = " << (str1 > str1) << '\n';
  cout << "str1 < str1 = " << (str1 < str1) << "\n";
  cout << "str1 >= str2 = " << (str1 >= str2) << '\n';
  cout << "str1 <= str2 = " << (str1 <= str2) << '\n';
  cout << "str1 >= str1 = " << (str1 >= str1) << '\n';
  cout << "str1 <= str1 = " << (str1 <= str1) << '\n';

  cout << "\n!\n";
  cout << "!str1 = " << !str1 << '\n';
  cout << "!!str1 = " << !!str1 << '\n';
  cout << "!str7 = " << !str7 << '\n';

  cout << "\nSubstring search\n";
  cout << "str6(str2) = " << str6(str2) << '\n';
  cout << "str1(str6) = " << str1(str6) << '\n';
  cout << "str6(str7) = " << str6(str7) << '\n';

  cout << "\nRandom access\n";
  cout << "str6[0] = " << str6[0] << '\n';
  cout << "str6[3] = " << str6[3] << '\n';

  cout << "\nGetters\n";
  cout << "str6.length() =  " << str6.length() << '\n';
  cout << "str6.get() = " << reinterpret_cast<void*>(str6.get()) << '\n';

  cout << "\nInput\n";
  MyString strin;
  cin >> strin;
  cout << "strin = " << strin << '\n';

  return 0;
}
