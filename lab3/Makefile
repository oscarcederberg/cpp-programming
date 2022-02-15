# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS =  html_tag_test sieve_erat_test date_test to_string_test string_cast_test

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
html_tag_test: html_tag_test.o html_tag.o
sieve_erat_test: sieve_erat_test.o sieve_erat.o
date_test: date_test.o date.o
to_string_test: to_string_test.o
string_cast_test: string_cast_test.o

# Phony targets
.PHONY: all clean

clean:
	rm -f *.o *.d $(PROGS)

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
