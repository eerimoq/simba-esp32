PHONY: all

all:
	rm -rf bin lib inc
	+make -C app V=1 all
	mkdir bin lib inc
	cp app/build/bootloader/bootloader.bin bin
	cp app/build/partitions_singleapp.bin bin
	cp $$(find app esp-idf/components -name "*.a" | grep -v bootloader | grep -v main | xargs) lib
	cd esp-idf/components && find . -name "*.h" | cpio -pdm ../../inc
	./redefine-symbols.py --find-symbols-in-libraries
	./redefine-symbols.py

clean:
	+make -C app clean
