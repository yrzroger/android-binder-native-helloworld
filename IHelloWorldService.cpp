//#define LOG_NDEBUG 0
#define LOG_TAG "IHelloWorldService"

#include <binder/Parcel.h>
#include <IHelloWorldService.h>

namespace android {

// 定义HelloWorldService使用的RPC代码
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
    HW_FOO,
};

// 定义HelloWorldService服务代理
class BpHelloWorldService : public BpInterface<IHelloWorldService>
{
public:
    BpHelloWorldService(const sp<IBinder>& impl)
        : BpInterface<IHelloWorldService>(impl)
    {
    }

    virtual status_t helloWorld(const char *str) {
        Parcel data, reply;
        data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor()); // 将服务名称保存到发送数据中
        data.writeCString(str); // 将输出字符串保存到发送数据中
        status_t status = remote()->transact(HW_HELLOWORLD, data, &reply); // 调用BpBinder的transact方法
        if(status != NO_ERROR) {
            ALOGE("call helloword error: %s", strerror(-status));
        } else {
            status = reply.readInt32();
        }
        return status;
    }
    
    virtual status_t foo() {
        Parcel data, reply;
        data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor()); // 将服务名称保存到发送数据中
        status_t status = remote()->transact(HW_FOO, data, &reply); // 调用BpBinder的transact方法
        if(status != NO_ERROR) {
            ALOGE("call foo error: %s", strerror(-status));
        } else {
            status = reply.readInt32();
        }
        return status;
    }
};


// 实现服务接口类
IMPLEMENT_META_INTERFACE(HelloWorldService, "android.native.helloworld");

// 重新定义处理RPC代码的onTransact()方法
status_t BnHelloWorldService::onTransact(uint32_t code,
                            const Parcel& data,
                            Parcel* reply,
                            uint32_t flags)
{
    switch(code) {
        case HW_HELLOWORLD: 
        {
            // 确认为正确的服务请求
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char * str;
            str = data.readCString();
            reply->writeInt32(helloWorld(str));
            return NO_ERROR;
        }
        case HW_FOO:
        {
            // 确认为正确的服务请求
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            reply->writeInt32(foo());
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android