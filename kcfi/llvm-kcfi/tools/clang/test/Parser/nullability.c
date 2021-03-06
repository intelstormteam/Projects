// RUN: %clang_cc1 -fsyntax-only -std=c99 -Wno-nullability-declspec -pedantic %s -verify

__nonnull int *ptr; // expected-warning{{type nullability specifier '__nonnull' is a Clang extension}}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-extension"
__nonnull int *ptr2; // no-warning
#pragma clang diagnostic pop

#if __has_feature(nullability)
#  error Nullability should not be supported in C under -pedantic -std=c99
#endif

#if !__has_extension(nullability)
#  error Nullability should always be supported as an extension
#endif
