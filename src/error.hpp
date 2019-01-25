#ifndef SHA256GUARD_4c9db84747a766839fd3bf26b833b3ffa46faa6e7cb3093563a363ef5649f21b
#define SHA256GUARD_4c9db84747a766839fd3bf26b833b3ffa46faa6e7cb3093563a363ef5649f21b

// =======================================================================
//
//  error.hpp -- Services related to error codes
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

#include "./snippets/noreturn.hpp"

namespace Error
{
    enum class Code
    {
        NOERR,  // No error, success
        PCOND,  // A precondition of the called function was violated
        NOMEM,  // Out of memory
        INVAL,  // An argument to the function was invalid
        AGAIN,  // The request could not be fulfilled when asked
        EXTERN, // An error occurred in an external function or system
        FILE,   // A problem occurred whilst reading or writing files
        PORT,   // There was a problem assigning internal ports

        COUNT  // Shortcut for number of different error codes
    };

    noreturn void die(Code err, const char* file, int line, const char* info);
}

#define DIE_ON(expr) \
    do { \
        using namespace Error; \
        Code err = (expr); \
        if (err != Code::NOERR) { \
            die(err, __FILE__, __LINE__, nullptr); \
        } \
    } while (false)

#endif // SHA256GUARD
