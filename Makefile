PHONY: all

all:
	+make -C app V=1 all
	cp $$(find app -name "*.a" | grep -v bootloader | grep -v main | xargs) lib
	cp app/build/bootloader/bootloader.bin bin
	cp app/build/partitions_singleapp.bin bin

clean:
	+make -C app clean
