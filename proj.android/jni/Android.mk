LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/SneakyButton.cpp \
                   ../../Classes/SneakyButtonSkinnedBase.cpp \
                   ../../Classes/SneakyJoystick.cpp \
                   ../../Classes/SneakyJoystickSkinnedBase.cpp \
                   ../../Classes/InputLayer.cpp \
                   ../../Classes/Entity.cpp \
                   ../../Classes/EnemyEntity.cpp \
                   ../../Classes/EnemyCache.cpp \
                   ../../Classes/StandardShootComponent.cpp \
                   ../../Classes/StandardMoveComponent.cpp \
                   ../../Classes/BulletCache.cpp \
                   ../../Classes/DogEntity.cpp \
                   ../../Classes/Bullet.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
