#ifndef SHA256GUARD_e828da8d5a234d604a5c33413553b90cf830e4e5170337606f70431d08237934
#define SHA256GUARD_e828da8d5a234d604a5c33413553b90cf830e4e5170337606f70431d08237934

// =======================================================================
//
//  defs.hpp -- Definitions for the memory subsystem
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

#include "../types.hpp"

namespace Memory
{
    using namespace Types;

    constexpr int PAGE_BITS = 16;
    constexpr Size NUM_PAGES = 1 << PAGE_BITS; // 64 ki pages

    constexpr int OFFSET_BITS = 16;
    constexpr Size PAGE_SIZE = 1 << OFFSET_BITS; // 64 kiB pages

    static_assert(PAGE_BITS + OFFSET_BITS == ADDRESS_BITS,
                  "Address bits must be split between page and offset");

    constexpr inline Size parent_page(Address loc)
    {
        return loc >> OFFSET_BITS;
    }

    constexpr inline Size page_offset(Address loc)
    {
        return loc & (PAGE_SIZE - 1);
    }
}

#endif // SHA256GUARD
