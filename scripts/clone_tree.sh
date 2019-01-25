#!/bin/sh

# =======================================================================
#
#  clone_tree.sh -- Build script to clone source directory tree
#
# -----------------------------------------------------------------------
#
#  Part of the BitChomper project.
#  Copyright (C) 2019 voidstarzero <https://github.com/voidstarzero>.
#
# -----------------------------------------------------------------------
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program. If not, see <https://www.gnu.org/licenses/>.
#
# =======================================================================

SRCDIR=src
OBJDIR=obj
DEPDIR=dep

echo "mkdir -p $OBJDIR/ $DEPDIR/"
mkdir -p $OBJDIR/ $DEPDIR/

echo "cd $SRCDIR/"
cd $SRCDIR/

echo "find * -type d -exec mkdir -p -- ../$DEPDIR/{} ../$OBJDIR/{} \;"
find * -type d -exec mkdir -p -- ../$DEPDIR/{} ../$OBJDIR/{} \;
