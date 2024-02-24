// Copyright [2024] <>
#include "../include/mystring.hpp"

char* MyString::get() {
  return this->buf;
}

size_t MyString::length() {
  return this->len;
}

MyString::MyString(const char* str) {
  if (str == NULL) {
    this->len = 0;
    this->buf = nullptr;
    return;
  }
  this->len = strlen(str);
  this->buf = new char[this->len];
  memcpy_s(this->buf, this->len, str, this->len);
}

MyString::MyString(string str) {
  this->len = str.length();
  this->buf = new char[this->len];
  const char* ptr = str.data();
  memcpy_s(this->buf, this->len, ptr, this->len);
}

MyString::MyString(const MyString& str) {
  this->len = str.len;
  this->buf = new char[this->len];
  memcpy_s(this->buf, this->len, str.buf, this->len);
}

MyString::MyString(MyString&& str) {
  this->len = str.len;
  this->buf = str.buf;
}

MyString::~MyString() {
  delete[] this->buf;
}

MyString MyString::operator+(const MyString& str1) {
  MyString res;
  res.len = this->len + str1.len;
  res.buf = new char[res.len];
  memcpy_s(res.buf, res.len, this->buf, this->len);
  memcpy_s(res.buf + this->len, res.len - this->len, str1.buf, str1.len);
  return res;
}

MyString MyString::operator-(const MyString& excl) {
  char* tempBuf = new char[this->len];
  size_t tempLen = 0;
  for (size_t i = 0; i < this->len; i++) {
    bool notExcl = true;
    for (size_t j = 0; j < excl.len; j++) {
      if (this->buf[i] == excl.buf[j]) {
        notExcl = false;
        break;
      }
    }
    if (notExcl) {
      tempBuf[tempLen] = this->buf[i];
      tempLen++;
    }
  }

  MyString res;
  if (tempLen == 0) {
    return res;
  }
  res.len = tempLen;
  res.buf = new char[tempLen];
  memcpy_s(res.buf, tempLen, tempBuf, tempLen);
  delete[] tempBuf;
  return res;
}

MyString MyString::operator*(size_t n) {
  MyString res;
  if (n == 0) {
    return res;
  }
  res.len = this->len * n;
  res.buf = new char[res.len];
  for (size_t i = 0; i < n; i++) {
    size_t offset = i*this->len;
    memcpy_s(res.buf + offset, res.len - offset, this->buf, this->len);
  }
  return res;
}

bool MyString::operator==(const MyString& str1) {
  if (this->len != str1.len) {
    return false;
  }

  if (this->len == 0) {
    return true;
  }

  return memcmp(this->buf, str1.buf, this->len) == 0;
}

bool MyString::operator!=(const MyString& str1) {
  if (this->len != str1.len) {
    return true;
  }

  if (this->len == 0) {
    return false;
  }

  return memcmp(this->buf, str1.buf, this->len) != 0;
}

int MyString::compare(const MyString& str1) {
  locale loc;
  const collate<char>& col = use_facet<collate<char>>(loc);
  int res = col.compare(this->buf, this->buf + this->len, str1.buf,
    str1.buf + str1.len);
  return res;
}

bool MyString::operator>(const MyString& str1) {
  int res = this->compare(str1);
  return res == 1;
}

bool MyString::operator<(const MyString& str1) {
  int res = this->compare(str1);
  return res == -1;
}

bool MyString::operator>=(const MyString& str1) {
  int res = this->compare(str1);
  return res >= 0;
}

bool MyString::operator<=(const MyString& str1) {
  int res = this->compare(str1);
  return res <= 0;
}

MyString MyString::operator!() {
  MyString res;
  if (this->len == 0) {
    return res;
  }
  res.len = this->len;
  res.buf = new char[res.len];
  for (size_t i = 0; i < res.len; i++) {
    char c = this->buf[i];
    if (c >= 97 && c <= 122) {
      c -= 32;
    } else if (c >= 65 && c <= 90) {
      c += 32;
    }
    res.buf[i] = c;
  }
  return res;
}

char MyString::operator[](size_t i) {
  return this->buf[i];
}

int64_t MyString::operator()(const MyString& substr) {
  if (substr.len > this->len) {
    return -1;
  }

  size_t* table = new size_t[256];
  for (size_t i = 0; i < 256; i++) {
    table[i] = substr.len;
  }
  for (size_t i = 0; i < substr.len - 1; i++) {
    uint8_t index = *reinterpret_cast<uint8_t*>(&substr.buf[i]);
    table[index] = substr.len - i - 1;
  }

  int64_t skip = 0;
  bool found = false;
  while (this->len - skip >= substr.len) {
    if (memcmp(this->buf + skip, substr.buf, substr.len) == 0) {
      found = true;
      break;
    }
    uint8_t index = *reinterpret_cast<uint8_t*>(
      &this->buf[skip + substr.len - 1]);
    skip += table[index];
  }

  delete[] table;

  if (found) {
    return skip;
  } else {
    return -1;
  }
}

void MyString::operator=(const MyString& str) {
  delete[] this->buf;
  this->len = str.len;
  this->buf = new char[this->len];
  memcpy_s(this->buf, this->len, str.buf, this->len);
}

// void MyString::operator=(MyString&& str) {
//   delete[] this->buf;
//   this->len = str.len;
//   this->buf = str.buf;
// }

ostream& operator<< (ostream& out, const MyString& str) {
  if (str.len == 0) {
    out << "";
    return out;
  }

  for (size_t i = 0; i < str.len; i++) {
    // int n = str.buf[i];
    // out << n << ' ';
    out << str.buf[i];
  }
  return out;
}

istream& operator>> (istream& in, MyString& str) {
  string s;
  in >> s;
  delete[] str.buf;
  str.len = s.length();
  str.buf = new char[str.len];
  memcpy_s(str.buf, str.len, s.data(), str.len);
  return in;
}
