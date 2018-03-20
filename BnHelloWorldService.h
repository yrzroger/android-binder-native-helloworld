#ifndef ANDROID_BNHELLOWORLDSERVICE_H
#define ANDROID_BNHELLOWORLDSERVICE_H

#include <IHelloWorldService.h>
#include <binder/Parcel.h>

namespace android {
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

#endif // ANDROID_BNHELLOWORLDSERVICE_H