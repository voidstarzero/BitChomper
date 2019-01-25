# =======================================================================
#
#  Main project Makefile
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

CXX = g++
FLAGS = -std=c++14 -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion

EXEC = bitchomper.out

################################################################

SRCDIR = src
OBJDIR = obj
DEPDIR = dep

SOURCES = $(shell find $(SRCDIR)/ -name '*.cpp')
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
DEPENDS = $(patsubst $(SRCDIR)/%.cpp,$(DEPDIR)/%.d,$(SOURCES))

################################################################

.PHONY: release debug

release: FLAGS += -DNDEBUG -O2 # CHANGE (if needed)
release: post-build

debug: FLAGS += -g # CHANGE (if needed)
debug: post-build

pre-build:
	scripts/clone_tree.sh

post-build: main-build
	@echo Done.

main-build: pre-build
	@$(MAKE) --no-print-directory $(EXEC)

################################################################

# Filter is needed to removed the directories from the list
# of files to be built
$(EXEC): $(OBJECTS)
	$(CXX) $(FLAGS) $(filter %.o,$^) -o $@

################################################################

# This automatically includes the generated dependency file for
# each source file
-include $(DEPENDS)

################################################################

# The -MF option specifies the name of each dependency file
# that gcc automatically creates for each object file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(FLAGS) -MMD -MF \
	$(patsubst $(OBJDIR)/%.o,$(DEPDIR)/%.d,$@) -c $< -o $@

################################################################

.PHONY: clean

clean:
	rm -rf $(EXEC) $(OBJDIR)/* $(DEPDIR)/* $(OBJDIR) $(DEPDIR)
