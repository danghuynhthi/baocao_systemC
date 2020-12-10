#include "systemc.h" // khai báo thư viện systemc

SC_MODULE (hello_world) { // khai báo module hello_world
 SC_CTOR (hello_world) { // hàm SC_CTOR dùng để khởi tạo các module trong bộ nhớ
 }
 void say_hello() { // viết hàm say_hello()
 cout << "Hello World.\n";// in chuỗi Hello World
 }
};
int sc_main(int argc, char* argv[]) {// hàm main chạy chương trình
 hello_world hello("hello"); // khởi tạo module hello_world tên hello
 hello.say_hello(); // thực hiện hàm say_hello trong module hello
 system("pause");
 return(0); // dừng chuong trình ở dòng này
}