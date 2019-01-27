#ifndef SHA256GUARD_aeaadddd2db0d90f5d6d7e7b6384f27d9e594dd0b99d87ef27ec8d5ab91d6e30
#define SHA256GUARD_aeaadddd2db0d90f5d6d7e7b6384f27d9e594dd0b99d87ef27ec8d5ab91d6e30

// =======================================================================
//
//  page.hpp -- A container managing a page of vCPU memory
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

#include "../error.hpp"
#include "../types.hpp"

namespace Memory
{
    using namespace Types;

    class Page
    {
    public:
        enum class Type
        {
            SYSTEM,
            DEVICE,
        };

        Error::Code create_system_page();
        Error::Code delete_system_page();

        Error::Code install_device_page(Cell* dev_mem);
        Error::Code remove_device_page();

        Cell* data() const
        {
            return pdata;
        }

    private:
        Type ptype = Type::SYSTEM;
        Cell* pdata = nullptr;
    };
}

#endif // SHA256GUARD
