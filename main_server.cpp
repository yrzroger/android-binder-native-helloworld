#define LOG_TAG "main_server"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <HelloWorldService.h>

using namespace android;

int main(int argc, char *agrv[])
{
    HelloWorldService::instantiate();
    ProcessState::self()->startThreadPool();
    ALOGI("HelloWorldService server is starting now");
    IPCThreadState::self()->joinThreadPool();
    
    return 0;
}