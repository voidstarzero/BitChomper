// =======================================================================
//
//  page.cpp -- A container managing a page of vCPU memory
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

#include "./defs.hpp"
#include "./page.hpp"

using namespace Memory;

Error::Code Page::create_system_page()
{
    if (pdata != nullptr) {
        return Error::Code::PCOND;
    }

    pdata = new Cell[PAGE_SIZE];
    ptype = Type::SYSTEM;

    return Error::Code::NOERR;
}

Error::Code Page::delete_system_page()
{
    if (ptype != Type::SYSTEM) {
        return Error::Code::PCOND;
    }

    delete[] pdata;
    pdata = nullptr;

    return Error::Code::NOERR;
}

Error::Code Page::install_device_page(Cell* dev_mem)
{
    if (pdata != nullptr) {
        return Error::Code::PCOND;
    }

    pdata = dev_mem;
    ptype = Type::DEVICE;

    return Error::Code::NOERR;
}

Error::Code Page::remove_device_page()
{
    if (ptype != Type::DEVICE) {
        return Error::Code::PCOND;
    }

    pdata = nullptr;
    return Error::Code::NOERR;
}
