#ifndef ANDROID_BPHELLOWORLDSERVICE_H
#define ANDROID_BPHELLOWORLDSERVICE_H

#include <binder/Parcel.h>
#include <IHelloWorldService.h>

namespace android {
// 定义HelloWorldService服务代理
class BpHelloWorldService : public BpInterface<IHelloWorldService>
{
public:
    BpHelloWorldService(const sp<IBinder>& impl);
    virtual status_t helloWorld(const char *str);
};

}; // namespace android

#endif // ANDROID_BPHELLOWORLDSERVICE_H