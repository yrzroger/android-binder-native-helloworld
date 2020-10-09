#ifndef ANDROID_IHELLOWORLDSERVICE_H
#define ANDROID_IHELLOWORLDSERVICE_H

#include <binder/IInterface.h>

namespace android {

// ����HelloWorldService����ӿ�
class IHelloWorldService : public IInterface {
public:
    // ��������ӿ���
    DECLARE_META_INTERFACE(HelloWorldService);
    
    // ��������ӿں���
    virtual status_t helloWorld(const char *str) = 0;
    
    virtual status_t foo() = 0;
};


// ����HelloWorldService����Stub
class BnHelloWorldService : public BnInterface<IHelloWorldService> {
public:
    // ���¶��崦��RPC�����onTransact()����
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_IHELLOWORLDSERVICE_H