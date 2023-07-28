LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/hatget/src/include

LOCAL_MODULE := hatget
LOCAL_SRC_FILES := \
	hatget/src/util.cpp \
	hatget/src/configfsisomanager.cpp \
	hatget/src/main.cpp

include $(BUILD_EXECUTABLE)
