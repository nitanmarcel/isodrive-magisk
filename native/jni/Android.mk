LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/isodrive/src/include

LOCAL_MODULE := isodrive
LOCAL_SRC_FILES := \
	isodrive/src/util.cpp \
	isodrive/src/configfsisomanager.cpp \
	isodrive/src/main.cpp

include $(BUILD_EXECUTABLE)
