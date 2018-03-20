# android-binder-native-helloworld
build binder service（HelloWorldService）based on Android Native Service Framework

工程简介：
在Android平台中，Service Framework大致由两大部分构成，一部分是使用C++语言编写的本地服务框架，另一部分是使用Java语言编写的Java服务框架。该工程基于本地服务框架写作了HelloWorldService，基于Binder IPC机制实现Android平台中的进程间通信。

使用方法：
1. 将工程源码拷贝到Android源码android\external目录下；

2. 编译后生成
        HelloWorldService动态库：libhelloworld.so
        客户端可执行档： main_client
        服务端可执行档： main_server
        
3. 将上一步骤中生成的动态库push到android平台/system/lib目录下
   将上一步骤中生成的执行档push到android平台/system/bin目录下
   
4. 在command line下执行main_server，启动服务
   # main_server
   
5. 在另一个session中command line下执行main_client，呼叫服务
   # main_client
   
   可以看到执行main_server的一端会输出 Hello world !
