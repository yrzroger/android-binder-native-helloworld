#include <binder/Parcel.h>
#include <BpHelloWorldService.h>

namespace android {

status_t BpHelloWorldService::helloWorld(const char *str) {
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

BpHelloWorldService::BpHelloWorldService(const sp<IBinder>& impl)
                        : BpInterface<IHelloWorldService>(impl)
{}

}; //namespace android
