CppParser
=========

[![Build Status](https://travis-ci.com/satya-das/cppparser.svg?branch=master)](https://travis-ci.com/satya-das/cppparser)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/e2a1f6c5c8c149be816f1514ec491c98)](https://www.codacy.com/app/satya-das/cppparser?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=satya-das/cppparser&amp;utm_campaign=Badge_Grade)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An easy, fast, and robust library to parse C/C++ source.

## Features
- No pre-processing, and preprocessors are part of the ast.
- Most comments are preserved too.
- Developed from scratch and uses back-tracking yacc (BtYacc) to write C++ grammer, that means **no dependency on libclang**.
- The result of parsing is an AST where elements of a file are arranged in a tree.
- Minimum dependency. Only external dependency is a [lexer](https://github.com/westes/flex) which is by default available on unix like platforms and can be easily [get on Windows](http://gnuwin32.sourceforge.net/packages/flex.htm).
- Parsing of multi-file program is supported too.

## Motivation 
CppParser can be used to build tools that need parsing of C/C++ files.
I am using it to develop [cib](https://github.com/satya-das/cib/) which implements ABI stable SDK architecture for C++ library.

## Example

To begin with we will see an example of parsing a hello-world program and see what is the AST that `CppParser` creates:
```c++
#include <iostream>

int main()
{
  std::cout << "Hello World!\n";

  return 0;
}

```

For the above hello-world program we can expect that when it is parsed the generated AST should look like following:
![AST for Hello World program](https://github.com/satya-das/cppparser/blob/master/src/readme-assets/HelloWorldAST.svg "AST for Hello World program")

So, how we are going to access these elements of AST using `CppParser`?
Below is the program written as unit-test for validating the correctness of generated AST:

```c++
#include <catch/catch.hpp>

#include "cppparser.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

TEST_CASE("Parsing hello world program")
{
  CppParser  parser;
  const auto testFilePath = fs::path(__FILE__).parent_path() / "test-files/hello-world.cpp";
  const auto ast          = parser.parseFile(testFilePath.string());
  REQUIRE(ast != nullptr);

  const auto& members = ast->members();
  REQUIRE(members.size() == 2);

  CppIncludeEPtr hashInclude = members[0];
  REQUIRE(hashInclude);
  CHECK(hashInclude->name_ == "<iostream>");

  CppFunctionEPtr func = members[1];
  REQUIRE(func);
  CHECK(func->name_ == "main");

  REQUIRE(func->defn());
  const auto& mainBodyMembers = func->defn()->members();
  REQUIRE(mainBodyMembers.size() == 2);

  CppExprEPtr coutHelloWorld = mainBodyMembers[0];
  REQUIRE(coutHelloWorld);
  CHECK(coutHelloWorld->oper_ == CppOperator::kInsertion);
}

```

**This example is a real one and is part of actual unit test of CppParser**.

## Building CppParser

### Get the source

```sh
git clone https://github.com/agladilin/cpppqqarser.git
```

## Configure and build

### Windows Visual Studio

[Install vcpkg](https://vcpkg.io/en/getting-started) to fetch boost

```powershell
vcpkg install boost-filesystem boost-program-options boost-system boost-date-time
cd cppparser
mkdir build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="[path to vcpkg]/scripts/buildsystems/vcpkg.cmake"
#cd build
#msbuild cppparser.sln
cmake --build . --config Debug
.\build\Debug\cppparsertest.exe
.\build\Debug\cppparserunittest.exe
cmake --build . --config Debug --target install  # requires administrator privileges
vcpkg install cppparser --overlay-ports=c:\dev\custom-overlay
```

To remove

```powershell
vcpkg remove cppparser
del $VCPKG_ROOT\buildtrees\cppparser
del $VCPKG_ROOT\packages\cppparser_x64-windows
del $VCPKG_ROOT\downloads\agladilin-cppparser-0.1.0.tar.gz
del C:\Users\<user>\AppData\Local\vcpkg\archives\19 # or whatever corresponding to package ABI hash in install log
```

### Linux and others

*For Ubuntu to fetch boost:*

```sh
sudo apt install libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev
```

```sh
cd cppparser
mkdir builds
cd builds
cmake ..
make && make test
```

*Alternatively, if you prefer `Ninja` instead of `make`*:

```sh
cd cppparser
mkdir builds
cd builds
cmake -G Ninja ..
ninja && ninja test
```

