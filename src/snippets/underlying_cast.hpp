#ifndef SHA256GUARD_2577fa774009057533feeb5b12bcb57fd4de09ab6f30f48794f0254460c55b99
#define SHA256GUARD_2577fa774009057533feeb5b12bcb57fd4de09ab6f30f48794f0254460c55b99

// =======================================================================
//
//  underlying_cast.hpp -- A clean interface for casting an enum class to
//                         its underlying integral type
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

#include <type_traits>

template <typename Enum>
constexpr auto underlying_cast(Enum val)
{
    return std::underlying_type_t<Enum>(val);
}

#endif // SHA256GUARD
