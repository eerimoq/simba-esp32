PHONY: all

all:
	+make -C app all
	cp $$(find app -name "*.a" | grep -v bootloader | xargs) lib
