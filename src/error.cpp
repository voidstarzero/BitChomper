// =======================================================================
//
//  error.cpp -- Services related to error codes
//
// -----------------------------------------------------------------------
//
//  Part of the BitChomper project.
//  Copyright (C) 2019 voidstarzero <https://github.com/voidstarzero>.
//
// -----------------------------------------------------------------------
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// =======================================================================

#include "./error.hpp"
#include "./snippets/underlying_cast.hpp"

#include <cstdio>
#include <cstdlib>

using namespace Error;

namespace
{
    constexpr const char* messages[underlying_cast(Code::COUNT)] = {
        "No error occurred",
        "A function's precondition was violated",
        "A memory allocation failed",
        "A function's argument was invalid",
        "A request could not be fulfilled at the required time",
        "An error occurred in an external function or system",
        "An error occurred reading or writing one or more files",
        "An error occurred trying to acquire a port",
    };
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

noreturn void Error::die(Code err, const char* file, int line, const char* info)
{
#ifdef NDEBUG
    (void) file;
    (void) line;
#else
    const char* msg = messages[underlying_cast(err)];
#endif

    using std::fprintf;

    eprintf("Error code %d, aborting...\n", underlying_cast(err));

#ifndef NDEBUG
    eprintf("Note: In %s, on line %d\n", file, line);
    eprintf("Note: %s.\n", msg);
#endif

    if (info != nullptr) {
        eprintf("%s.\n", info);
    }

    std::abort();
}
