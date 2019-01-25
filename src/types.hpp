#ifndef SHA256GUARD_8a9eb92f620774060220ef6287ac1762945ba5ef2e9e38314c395812b5530463
#define SHA256GUARD_8a9eb92f620774060220ef6287ac1762945ba5ef2e9e38314c395812b5530463

// =======================================================================
//
//  types.hpp -- Important typedefs for the whole project
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

#include <cstdint>

namespace Types
{
    using Byte = uint8_t;
    using Dbyte = uint16_t;
    using Qbyte = uint32_t;

    // Used by the vCPU and registers for native-sized data
    using Word = Qbyte; // vCPU uses 32-bit words
    constexpr int WORD_BITS = sizeof(Word) * 8;

    // Used to refer to individual vRAM units
    using Cell = Byte; // vCPU memory is byte-addressable
    using Address = Word;
    constexpr int ADDRESS_BITS = sizeof(Address) * 8;

    using Size = Word; // Size type for objects in vCPU memory
}

#endif // SHA256GUARD
