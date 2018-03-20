#ifndef ANDROID_BNHELLOWORLDSERVICE_H
#define ANDROID_BNHELLOWORLDSERVICE_H

#include <IHelloWorldService.h>
#include <binder/Parcel.h>

namespace android {
// 定义HelloWorldService服务Stub
class BnHelloWorldService : public BnInterface<IHelloWorldService> {
public:
    // 重新定义处理RPC代码的onTransact()方法
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_BNHELLOWORLDSERVICE_H