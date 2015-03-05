LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../Android/GbombSDKWrapper)
#$(call import-add-path,$(LOCAL_PATH)/../../../android/jni)

#NDK_MODULE_PATH := ../libs/$(TARGET_ARCH_ABI)/

#$(info, ${NDK_MODULE_PATH})
#$(info ${TARGET_ARCH_ABI})

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
	#$(LOCAL_PATH)/../../../GbombSDKWrapper/jni/include
	#$(LOCAL_PATH)/../../cocos2d/extensions \

LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_SHARED_LIBRARIES := gbombsdk_share

LOCAL_CPPFLAGS := -std=c++11 -fexceptions
LOCAL_LDLIBS := -llog -lz -landroid

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,jni)
