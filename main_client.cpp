//#define LOG_NDEBUG 0
#define LOG_TAG "main_client"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <utils/RefBase.h>
#include <IHelloWorldService.h>

using namespace android;

int main(int argc, char *argv[])
{
    ALOGI("HelloWorldService client is starting now");
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> b;
    sp<IHelloWorldService> sHelloWorldService;
    
    do {
        b = sm->getService(String16("android.native.helloworld"));
        if(b != 0)
            break;
        ALOGI("HelloWorldService is not working, waiting...");
        usleep(500000);
    } while(true);
    
    sHelloWorldService = interface_cast<IHelloWorldService>(b);
    
    if(argc == 1)
        sHelloWorldService->helloWorld("Hello world !");
    else
        sHelloWorldService->helloWorld(argv[1]);
    
    
    sHelloWorldService->foo();
    
    return 0;
}