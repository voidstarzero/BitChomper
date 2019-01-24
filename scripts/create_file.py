#!/usr/bin/env python

# =======================================================================
#
#  create_file.py -- A tool to assist with creating new project files
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

from __future__ import print_function
from datetime import datetime
import hashlib
import os
import sys

# Analogous to print() for stderr
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

# Version of print() taking file handle as first argument
def fprint(f, *args, **kwargs):
    print(*args, file=f, **kwargs)

# Display usage information for the script
# prog_name: name of the program as invoked
def usage(prog_name):
    eprint("usage:", prog_name, "language-name new-file-path")

# One class for each language supported
# Handler.__init__: passed the output file name to allow output customization
# Handler.preheader: output for before the copyright section
# Handler.postheader: output for after the copyright section
# Handler.commentchars: symbols to precede every line in the copyright section

class PythonHandler(object):
    def __init__(self, fname):
        self.preheader = "#!/usr/bin/env python\n"
        self.postheader = (
            "\nfrom __future__ import print_function\n\n# TODO: File contents..."
        )
        self.commentchars = "#"

class ShellHandler(object):
    def __init__(self, fname):
        self.preheader = "#!/bin/sh\n"
        self.postheader = "\n# TODO: File contents..."
        self.commentchars = "#"

class MsBatchHandler(object):
    def __init__(self, fname):
        self.preheader = "@echo off\n"
        self.postheader = "\nREM TODO: File contents..."
        self.commentchars = "REM"

class CxxHeaderHandler(object):
    def __init__(self, fname):
        timestamp = str(datetime.now())

        h = hashlib.sha256()
        h.update(fname)
        h.update(timestamp)

        digest = h.hexdigest()
        template = "#ifndef SHA256GUARD_{}\n#define SHA256GUARD_{}\n"

        self.preheader = template.format(digest, digest)
        self.postheader = "\n// TODO: File contents...\n\n#endif // SHA256GUARD"
        self.commentchars = "//"

class CxxSourceHandler(object):
    def __init__(self, fname):
        self.preheader = ""
        self.postheader = "\n// TODO: File contents..."
        self.commentchars = "//"

# A file that uses # comments but requires no preambles of any kind
class BareHandler(object):
    def __init__(self, fname):
        self.preheader = ""
        self.postheader = "\n# TODO: File contents..."
        self.commentchars = "#"


SUPPORTED_LANGS = {
    "sh": ShellHandler,
    "shell": ShellHandler,
    "python": PythonHandler,
    "c++hdr": CxxHeaderHandler,
    "cxxhdr": CxxHeaderHandler,
    "c++": CxxSourceHandler,
    "cxx": CxxSourceHandler,
    # C99 onwards allows // comments, so can use unchanged
    "chdr": CxxHeaderHandler,
    "c": CxxSourceHandler,
    "bat": MsBatchHandler,
    "batch": MsBatchHandler,
    "bare": BareHandler,
}

# Responsible for the writing of the template to the file
# f: file handle to write
# lang: on of SUPPORTED_LANGS
# name: the name of the file referred to by f
def write_file(f, lang, fname):
    lang_handler = SUPPORTED_LANGS[lang](fname)

    if lang_handler.preheader != "":
        fprint(f, lang_handler.preheader)

    for line in HEADER_TEMPLATE.split('\n'):
        line = line.replace("{}", fname)
        if line == "":
            fprint(f, lang_handler.commentchars)
        else:
            fprint(f, lang_handler.commentchars, line)

    fprint(f, lang_handler.postheader)

# Semi-standard exit codes taken from <sysexits.h>
ERR_USAGE = 64
ERR_DATAERR = 65
ERR_IOERR = 74

def main():
    if len(sys.argv) != 3:
        eprint("error: incorrect number of arguments: got {}, expected 2"
               .format(len(sys.argv) - 1))
        usage(sys.argv[0])
        sys.exit(ERR_USAGE)

    lang = sys.argv[1].lower()
    path = sys.argv[2]

    if lang not in SUPPORTED_LANGS:
        eprintf("error: language not supported:", lang)
        sys.exit(ERR_DATAERR)

    try:
        f = open(path, 'w')
    except IOError:
        eprint("error: couldn't open file for writing:", path)
        sys.exit(ERR_IOERR)

    with f:
        fname = os.path.basename(path)
        write_file(f, lang, fname)

HEADER_TEMPLATE = """=======================================================================

 {} -- TODO: File description...

-----------------------------------------------------------------------

 Part of the BitChomper project.
 Copyright (C) 2019 voidstarzero <https://github.com/voidstarzero>.

-----------------------------------------------------------------------

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>.

======================================================================="""

if __name__ == "__main__":
    main()
