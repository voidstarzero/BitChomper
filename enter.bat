@echo off

REM =======================================================================
REM
REM  enter.bat -- Configures Windows CMD for the build/dev environment
REM
REM -----------------------------------------------------------------------
REM
REM  Part of the BitChomper project.
REM  Copyright (C) 2019 voidstarzero <https://github.com/voidstarzero>.
REM
REM -----------------------------------------------------------------------
REM
REM  This program is free software: you can redistribute it and/or modify
REM  it under the terms of the GNU General Public License as published by
REM  the Free Software Foundation, either version 3 of the License, or
REM  (at your option) any later version.
REM
REM  This program is distributed in the hope that it will be useful,
REM  but WITHOUT ANY WARRANTY; without even the implied warranty of
REM  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM  GNU General Public License for more details.
REM
REM  You should have received a copy of the GNU General Public License
REM  along with this program. If not, see <https://www.gnu.org/licenses/>.
REM
REM =======================================================================

set old_path=%path%
set path=%cd%\scripts;%path%

set old_prompt=%prompt%
prompt $LBC$G %prompt%
