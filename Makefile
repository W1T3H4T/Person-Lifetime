#	--------------------------------------------------
#	File	:	Makefile
#	Target	:	person
#	Who		:	David Means
#	--------------------------------------------------

TARGET 		= person
SRCS 		= $(wildcard *.c) $(wildcard *.cc) $(wildcard *.cpp)
CFLAGS 		= -Wall -O -g 
CXXFLAGS	= -std=c++20 -Wall -Wextra -Wpedantic
CPPFLAGS	=
INCLUDE		= -I. 
LDFLAGS		=
DATE		= /bin/date
UNAME		= /bin/uname
GETOSVER	= $(UNAME) -s
LIBS		= 
CC			= gcc
CXX			= g++ 

# Shouldn't need to edit below this line except to customize

BNAMES 	= $(basename $(SRCS))
OBJS 	= $(addsuffix .o, $(BNAMES))
DEPS 	= $(addsuffix .d, $(BNAMES))

CFLAGS+=$(INCLUDE)
CXXFLAGS+=$(INCLUDE)

.PHONY: all clean distclean package

all: $(TARGET)

package: clean
	strip $(TARGET)

clean:
	-rm -f *.o *.d *.exe $(TARGET) $(TARGET).exe

distclean: clean
	-rm -f core *~ $(TARGET) $(TARGET).exe

$(TARGET): $(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

# Create dependency files foo.d for each source file foo.c.

%.d: %.c
	@echo Creating dependencies for $<. 
	@$(SHELL) -ec '$(CC) -MM $(INCLUDE) $(CPPFLAGS) $< \
    | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
    [ -s $@ ] || rm -f $@'

%.d: %.cc
	@echo Creating dependencies for $<.
	@$(SHELL) -ec '$(CXX) -MM $(INCLUDE) $(CPPFLAGS) $< \
	| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
	[ -s $@ ] || rm -f $@'

%.d: %.cpp
	@echo Creating dependencies for $<. 
	@$(SHELL) -ec '$(CC) -MM $(INCLUDE) $(CPPFLAGS) $< \
    | sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
    [ -s $@ ] || rm -f $@'

-include $(DEPS)

