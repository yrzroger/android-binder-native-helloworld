//#define LOG_NDEBUG 0
#define LOG_TAG "IHelloWorldService"

#include <binder/Parcel.h>
#include <IHelloWorldService.h>

namespace android {

// ����HelloWorldServiceʹ�õ�RPC����
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
    HW_FOO,
};

// ����HelloWorldService�������
class BpHelloWorldService : public BpInterface<IHelloWorldService>
{
public:
    BpHelloWorldService(const sp<IBinder>& impl)
        : BpInterface<IHelloWorldService>(impl)
    {
    }

    virtual status_t helloWorld(const char *str) {
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
    
    virtual status_t foo() {
        Parcel data, reply;
        data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor()); // ���������Ʊ��浽����������
        status_t status = remote()->transact(HW_FOO, data, &reply); // ����BpBinder��transact����
        if(status != NO_ERROR) {
            ALOGE("call foo error: %s", strerror(-status));
        } else {
            status = reply.readInt32();
        }
        return status;
    }
};


// ʵ�ַ���ӿ���
IMPLEMENT_META_INTERFACE(HelloWorldService, "android.native.helloworld");

// ���¶��崦��RPC�����onTransact()����
status_t BnHelloWorldService::onTransact(uint32_t code,
                            const Parcel& data,
                            Parcel* reply,
                            uint32_t flags)
{
    switch(code) {
        case HW_HELLOWORLD: 
        {
            // ȷ��Ϊ��ȷ�ķ�������
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char * str;
            str = data.readCString();
            reply->writeInt32(helloWorld(str));
            return NO_ERROR;
        }
        case HW_FOO:
        {
            // ȷ��Ϊ��ȷ�ķ�������
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            reply->writeInt32(foo());
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android