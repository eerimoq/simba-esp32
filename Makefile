PHONY: all

all:
	+make -C app V=1 all
	cp $$(find app -name "*.a" | grep -v bootloader | grep -v main | xargs) lib

clean:
	+make -C app clean
