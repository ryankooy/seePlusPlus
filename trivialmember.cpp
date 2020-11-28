#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
struct optional_storage_base {
  optional_storage_base() : has_value_(false), empty_() {}
  bool has_value_;
  union {
    T value_;
    char empty_;
  };
};

template <class T, bool = is_trivially_copy_constructible_v<T>>
struct optional_copy_base : optional_storage_base<T> {
  optional_copy_base(optional_copy_base const&) = default;
  ~optional_copy_base() = default;
  optional_copy_base() = default;
  optional_copy_base(optional_copy_base&&) = default;
  optional_copy_base& operator=(optional_copy_base const&) = default;
  optional_copy_base& operator=(optional_copy_base &&) = default;
};

template <class T>
struct optional_copy_base<T, false> : optional_storage_base<T> {
  optional_copy_base(optional_copy_base const& rhs)
  {
    if (rhs.has_value_) {
      this->has_value_ = true;
      new (&this->value_) T(rhs.value_);
    }
  }

  ~optional_copy_base() = default;
  optional_copy_base() = default;
  optional_copy_base(optional_copy_base&&) = default;
  optional_copy_base& operator=(optional_copy_base const&) = default;
  optional_copy_base& operator=(optional_copy_base &&) = default;
};

template <typename T>
struct optional : optional_copy_base<T> {
  optional_copy_base() = default;
};
