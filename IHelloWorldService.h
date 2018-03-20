#ifndef ANDROID_IHELLOWORLDSERVICE_H
#define ANDROID_IHELLOWORLDSERVICE_H

#include <binder/IInterface.h>

namespace android {

// ����HelloWorldServiceʹ�õ�RPC����
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
};

// ����HelloWorldService����ӿ�
class IHelloWorldService : public IInterface {
public:
    // ��������ӿ���
    DECLARE_META_INTERFACE(HelloWorldService);
    
    // ��������ӿں���
    virtual status_t helloWorld(const char *str) = 0;
};

}; // namespace android

#endif // ANDROID_IHELLOWORLDSERVICE_H