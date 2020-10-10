//#define LOG_NDEBUG 0
#define LOG_TAG "main_server"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <HelloWorldService.h>

using namespace android;

int main(int argc, char *agrv[])
{
    
    fprintf(stderr, "--------------------------------------------\n");
    fprintf(stderr, "server run on process(pid=%d)\n", getpid());
    fprintf(stderr, "--------------------------------------------\n\n");
    
    HelloWorldService::instantiate();
    ProcessState::self()->startThreadPool();
    ALOGI("HelloWorldService server is starting now");
    IPCThreadState::self()->joinThreadPool();
    
    
    
    return 0;
}