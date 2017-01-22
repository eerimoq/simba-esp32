PHONY: all

all:
	rm -rf bin lib inc
	+make -C application V=1 all
	+make -C bootloader_application V=1 all
	mkdir bin lib inc
	cp application/build/bootloader/bootloader.bin bin
	cp application/build/partitions_singleapp.bin bin
	cp bootloader_application/build/partitions_bootloader_application.bin bin
	cp $$(find application esp-idf/components -name "*.a" | grep -v bootloader | grep -v main | xargs) lib
	cd esp-idf/components && find . -name "*.h" | cpio -pdm ../../inc
	./redefine-symbols.py --find-symbols-in-libraries
	./redefine-symbols.py

clean:
	+make -C application clean
	+make -C bootloader_application clean
