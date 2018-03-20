#include <BnHelloWorldService.h>
#include <binder/Parcel.h>
namespace android {
// 重新定义处理RPC代码的onTransact()方法
status_t BnHelloWorldService::onTransact(uint32_t code,
                            const Parcel& data,
                            Parcel* reply,
                            uint32_t flags)
{
    switch(code) {
    case HW_HELLOWORLD: {
        // 确认为正确的服务请求
        CHECK_INTERFACE(IHelloWorldService, data, reply);
        const char * str;
        str = data.readCString();
        reply->writeInt32(helloWorld(str));
        return NO_ERROR;
    } break;
    default:
        return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android