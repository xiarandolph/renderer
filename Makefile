SYSCONF_LINK = g++
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./
TARGET  = main.exe

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	-del $(OBJECTS)
	-del $(TARGET)
	-del *.tga

