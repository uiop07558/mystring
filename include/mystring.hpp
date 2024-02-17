#pragma once

#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <string>
#include <locale>

using std::string;
using std::collate;
using std::locale;
using std::use_facet;

class MyString {
 private:
  char* buf;
  size_t len;

 public:
  // MyString();
  explicit MyString(const char* str);
  explicit MyString(string str);
  MyString(const MyString& str);
  MyString(MyString&& str);
  ~MyString();
  size_t length();
  char* get();

  MyString operator+(const MyString& str1);
  MyString operator-(const MyString& excl);
  MyString operator*(size_t n);
  bool operator==(const MyString& str1);
  bool operator!=(const MyString& str1);
  bool operator>(const MyString& str1);
  bool operator<(const MyString& str1);
  bool operator>=(const MyString& str1);
  bool operator<=(const MyString& str1);
  MyString operator!();
  char operator[](size_t i);
  int64_t operator()(const MyString& substr);
  void operator=(const MyString& str);
  void operator=(MyString&& str);
};
