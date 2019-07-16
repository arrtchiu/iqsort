CONFIG=MinSizeRel
BUILD_DIR=_build
PREFIX=_install

.PHONY: all
all:
	cmake . -B$(BUILD_DIR) -DCMAKE_INSTALL_PREFIX=$(PREFIX) -DCMAKE_BUILD_TYPE=$(CONFIG) && cd $(BUILD_DIR) && make && make install
