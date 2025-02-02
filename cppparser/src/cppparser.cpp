// Copyright (C) 2022 Satya Das and CppParser contributors
// SPDX-License-Identifier: MIT

#include "cppparser/cppparser.h"
#include "cppast/cppast.h"
#include "parser.h"
#include "utils.h"

#include <algorithm>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

// Unfortunately parser is not reentrant and has no way as of now to inject parameters.
// So, we need globals.

// Globals to help parse when preprocessors are used
std::set<std::string>      gMacroNames;
std::set<std::string>      gKnownApiDecorNames;
std::map<std::string, int> gDefinedNames;
std::set<std::string>      gUndefinedNames;
std::set<std::string>      gIgnorableMacroNames;
std::map<std::string, int> gRenamedKeywords;

bool gParseEnumBodyAsBlob     = false;
bool gParseFunctionBodyAsBlob = false;

extern int GetKeywordId(const std::string& keyword);

namespace cppparser {

void CppParser::addKnownMacro(std::string knownMacro)
{
  gMacroNames.insert(std::move(knownMacro));
}

void CppParser::addKnownMacros(const std::vector<std::string>& knownMacros)
{
  for (auto& macro : knownMacros)
    gMacroNames.insert(macro);
}

void CppParser::addDefinedName(std::string definedName, int value)
{
  gDefinedNames[std::move(definedName)] = value;
}

void CppParser::addUndefinedName(std::string undefinedName)
{
  gUndefinedNames.insert(std::move(undefinedName));
}

void CppParser::addUndefinedNames(const std::vector<std::string>& undefinedNames)
{
  for (auto& macro : undefinedNames)
    gUndefinedNames.insert(macro);
}

void CppParser::addIgnorableMacro(std::string ignorableMacro)
{
  gIgnorableMacroNames.insert(std::move(ignorableMacro));
}

void CppParser::addIgnorableMacros(const std::vector<std::string>& ignorableMacros)
{
  for (auto& macro : ignorableMacros)
    gIgnorableMacroNames.insert(macro);
}

void CppParser::addKnownApiDecor(std::string knownApiDecor)
{
  gKnownApiDecorNames.insert(std::move(knownApiDecor));
}

void CppParser::addKnownApiDecors(const std::vector<std::string>& knownApiDecor)
{
  for (auto& apiDecor : knownApiDecor)
    gKnownApiDecorNames.insert(apiDecor);
}

bool CppParser::addRenamedKeyword(const std::string& keyword, std::string renamedKeyword)
{
  auto id = GetKeywordId(keyword);
  if (id == -1)
    return false;
  gRenamedKeywords.emplace(std::make_pair(std::move(renamedKeyword), id));

  return true;
}

void CppParser::parseEnumBodyAsBlob()
{
  gParseEnumBodyAsBlob = true;
}

void CppParser::parseFunctionBodyAsBlob(bool asBlob)
{
  gParseFunctionBodyAsBlob = asBlob;
}

std::unique_ptr<cppast::CppCompound> CppParser::parseFile(const std::string& filename)
{
  auto stm         = ReadFile(filename);
  auto cppCompound = ParseStream(stm.data(), stm.size());
  if (!cppCompound)
    return cppCompound;
  cppCompound->name(filename);
  return cppCompound;
}

std::unique_ptr<cppast::CppCompound> CppParser::parseStream(char* stm, size_t stmSize)
{
  if ((stm == nullptr) || (stmSize < 2) || (stm[stmSize - 1] != '\0') || (stm[stmSize - 2] != '\0'))
    throw std::invalid_argument("Stream must be valid and it must terminate with double null characters");
  return ::ParseStream(stm, stmSize);
}

void CppParser::setErrorHandler(ErrorHandler errorHandler)
{
  ::SetErrorHandler(errorHandler);
}

void CppParser::resetErrorHandler()
{
  ::ResetErrorHandler();
}

} // namespace cppparser
