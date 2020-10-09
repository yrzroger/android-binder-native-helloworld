#ifndef ANDROID_HELLOWORLDSERVICE_H
#define ANDROID_HELLOWORLDSERVICE_H

#include <IHelloWorldService.h>
#include <utils/Log.h>

namespace android {
// ����HelloWorldService����
class HelloWorldService : public BnHelloWorldService
{
public:
    // ��ʼ��HelloWorldService����ϵͳע�����
    static void instantiate();
    
    // ����ʵ�ַ���ӿڵķ���
    virtual status_t helloWorld(const char *str);
    virtual status_t foo();
    
    // ����BnHelloWorldService��onTransact����
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags);
private:
    // �����캯������Ϊ˽�к�������ֹʹ��new�����ֱ�Ӵ�������
    HelloWorldService();
    virtual ~HelloWorldService();
};

}; // namespace android

#endif // ANDROID_HELLOWORLDSERVICE_H
