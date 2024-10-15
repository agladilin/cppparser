// Copyright (C) 2022 Satya Das and CppParser contributors
// SPDX-License-Identifier: MIT

#ifndef CAE7C5FE_5296_490E_A123_C4C1BD3C662B
#define CAE7C5FE_5296_490E_A123_C4C1BD3C662B

#include <cstdint>

namespace cppast {

enum class CppUnaryOperator : std::uint8_t
{
  UNARY_PLUS,
  UNARY_MINUS,
  PREFIX_INCREMENT,
  PREFIX_DECREMENT,
  BIT_TOGGLE,
  LOGICAL_NOT,
  DEREFER,
  REFER,
  POSTFIX_INCREMENT,
  POSTFIX_DECREMENT,
  PARENTHESIZE,
  VARIADIC,
  NEW,
  DELETE,
  DELETE_AARAY,
  SIZE_OF,
  VARIADIC_SIZE_OF,
};

enum class CppBinaryOperator : std::uint8_t
{
  PLUS,
  MINUS,
  MUL,
  DIV,
  PERCENT,
  LOGICAL_AND,
  LOGICAL_OR,
  AND,
  OR,
  XOR,
  ASSIGN,
  LESS,
  GREATER,
  PLUS_ASSIGN,
  MINUS_ASSIGN,
  MUL_ASSIGN,
  DIV_ASSIGN,
  PERCENT_ASSIGN,
  LOGICAL_AND_ASSIGN,
  LOGICAL_OR_ASSIGN,
  XOR_ASSIGN,
  AND_ASSIGN,
  OR_ASSIGN,
  LEFT_SHIFT,
  INSERTION = LEFT_SHIFT,
  RIGHT_SHIFT,
  EXTRACTION,
  LSHIFT_ASSIGN,
  RSHIFT_ASSIGN,
  EQUAL,
  NOT_EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  THREE_WAY_CMP,
  COMMA,
  DOT,
  ARROW,
  ARROW_STAR, // TODO: Do we need it? If yes, then why not DOT_ARROW too?
  ARRAY_INDEX,
  PLACEMENT_NEW,
  GLOBAL_PLACEMENT_NEW,
  USER_LITERAL,
};

enum class CppTernaryOperator : std::uint8_t
{
  CONDITIONAL,
};

} // namespace cppast

#endif /* CAE7C5FE_5296_490E_A123_C4C1BD3C662B */
