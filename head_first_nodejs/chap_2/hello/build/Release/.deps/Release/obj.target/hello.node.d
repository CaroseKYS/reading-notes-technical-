cmd_Release/obj.target/hello.node := flock ./Release/linker.lock g++ -shared -pthread -rdynamic -m32   -Wl,-soname=hello.node -o Release/obj.target/hello.node -Wl,--start-group Release/obj.target/hello/src/hello.o -Wl,--end-group 
