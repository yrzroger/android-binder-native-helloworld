#ifndef ANDROID_HELLOWORLDSERVICE_H
#define ANDROID_HELLOWORLDSERVICE_H

#include <IHelloWorldService.h>
#include <utils/Log.h>

namespace android {
// 定义HelloWorldService服务
class HelloWorldService : public BnHelloWorldService
{
public:
    // 初始化HelloWorldService并向系统注册服务
    static void instantiate();
    
    // 具体实现服务接口的方法
    virtual status_t helloWorld(const char *str);
    virtual status_t foo();
    
    // 调用BnHelloWorldService的onTransact方法
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags);
private:
    // 将构造函数设置为私有函数，防止使用new运算符直接创建对象
    HelloWorldService();
    virtual ~HelloWorldService();
};

}; // namespace android

#endif // ANDROID_HELLOWORLDSERVICE_H
