TARGET := iphone:clang:latest:7.0
ARCHS := arm64 arm64e armv7 armv7s
INSTALL_TARGET_PROCESSES = SpringBoard


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = WAStatusColor

WAStatusColor_FILES = Tweak.xm $(wildcard ./*.m)
WAStatusColor_FRAMEWORKS = Foundation UIKit CoreGraphics
WAStatusColor_CFLAGS = -fobjc-arc -Wno-error -Wno-deprecated-declarations -Wno-unsupported-availability-guard -Wno-unused-variable -Wno-unused-function

include $(THEOS_MAKE_PATH)/tweak.mk
include $(THEOS_MAKE_PATH)/aggregate.mk
