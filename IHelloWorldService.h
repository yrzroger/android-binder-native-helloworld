#ifndef ANDROID_IHELLOWORLDSERVICE_H
#define ANDROID_IHELLOWORLDSERVICE_H

#include <binder/IInterface.h>

namespace android {

// 定义HelloWorldService使用的RPC代码
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
};

// 定义HelloWorldService服务接口
class IHelloWorldService : public IInterface {
public:
    // 声明服务接口类
    DECLARE_META_INTERFACE(HelloWorldService);
    
    // 声明服务接口函数
    virtual status_t helloWorld(const char *str) = 0;
};

}; // namespace android

#endif // ANDROID_IHELLOWORLDSERVICE_H