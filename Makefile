CC = g++

SRCDIR = src
OBJDIR = obj

SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
DEPENDENCIES := $(OBJECTS:.o=.d)

TARGET = out/aoc.exe

# Compiler flags
INCLUDES = -Idependencies -Idependencies/include
STANDARD = -std=c++20
WARNINGS = # -Wno-missing-field-initializers, example warning
ERRORFLAGS = -Werror -Wall -Wextra -pedantic-errors
CFLAGS = -MMD -MP -g $(INCLUDES) $(STANDARD) $(WARNINGS) $(ERRORFLAGS)

# Linker flags
LDFLAGS = -Ldependencies/lib

# Libraries
LIBS = #-lgdi32 -lshell32 -lopengl32 -lwinmm -lraylibdll

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Building $@..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)
	@echo "Build complete."
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

-include $(DEPENDENCIES)