#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <BnHelloWorldService.h>
#include <HelloWorldService.h>
#include <utils/Log.h>

namespace android {

void HelloWorldService::instantiate() {
    defaultServiceManager()->addService(
            String16("android.native.helloworld"), new HelloWorldService());
}

status_t HelloWorldService::helloWorld(const char *str) {
    ALOGI("%s\n", str);
    printf("%s\n", str);
    return NO_ERROR;
}

HelloWorldService::HelloWorldService() {
    ALOGI("HelloWorldService is created");
}

HelloWorldService::~HelloWorldService() {
    ALOGI("HelloWorldService is destroyed");
}

status_t HelloWorldService::onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
            return BnHelloWorldService::onTransact(code, data, reply, flags);
}

}; // namespace android