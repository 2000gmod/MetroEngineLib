TARGET = $(OUTDIR)/graph

CC = g++
CFLAGS = -Wall -g -lm `sdl2-config --cflags --libs` -O1 -MMD


OBJDIR = obj
SRCDIR = src

OUTDIR = out

SOURCES := $(shell find . -name '*.cpp')
OBJECTS := $(subst .cpp,.o, $(subst ./src,./$(OBJDIR),$(SOURCES)))
DEPS := $(shell find . -name '*.d')

.PHONY: default
default:
	$(MAKE) $(TARGET)
# 	$(MAKE) run



$(TARGET): $(OBJECTS) | $(OUTDIR)
	$(CC) -o $(TARGET) $^ $(CFLAGS) 


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)


include $(DEPS)

$(OUTDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@
	$(shell rsync -a --include='*/' --exclude='*' $(SRCDIR)/ $(OBJDIR)/)


.PHONY: clean deepclean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OUTDIR)

deepclean: clean
	rm -rf $(OBJDIR)