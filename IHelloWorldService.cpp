#include <IHelloWorldService.h>
#include <BpHelloWorldService.h>

namespace android {
// 实现服务接口类
IMPLEMENT_META_INTERFACE(HelloWorldService, "android.native.helloworld");
}; // namespace android