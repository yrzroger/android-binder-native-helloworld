#include <binder/Parcel.h>
#include <BpHelloWorldService.h>

namespace android {

status_t BpHelloWorldService::helloWorld(const char *str) {
    Parcel data, reply;
    data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor()); // ���������Ʊ��浽����������
    data.writeCString(str); // ������ַ������浽����������
    status_t status = remote()->transact(HW_HELLOWORLD, data, &reply); // ����BpBinder��transact����
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
