#ifndef ANDROID_IHELLOWORLDSERVICE_H
#define ANDROID_IHELLOWORLDSERVICE_H

#include <binder/IInterface.h>

namespace android {

// 定义HelloWorldService服务接口
class IHelloWorldService : public IInterface {
public:
    // 声明服务接口类
    DECLARE_META_INTERFACE(HelloWorldService);
    
    // 声明服务接口函数
    virtual status_t helloWorld(const char *str) = 0;
    
    virtual status_t foo() = 0;
};


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

#endif // ANDROID_IHELLOWORLDSERVICE_H