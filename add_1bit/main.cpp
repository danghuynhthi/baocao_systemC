// khai báo file module add1 và file testbench add1_tsl
// dùng để kết nối các module lại với nhau
#include "add1bit.cpp"
#include "testbench.cpp"
int sc_main(int argc, char* argv[])
{

// Khai báo các tín hiệu được gắn với các module
	sc_signal<sc_logic> A_s,B_s,CIN_s,SUM_s,COUT_s;
// Khởi tạo module BIT_ADDER có tên "adder1"
	BIT_ADDER adder1("BitAdder1");
// kết nối các signal với các ngõ vào và ngõ ra của module
// lưu ý phải đặt đúng thứ tự khai báo trong module add1
	adder1 << A_s << B_s << CIN_s << SUM_s << COUT_s;
// Khởi tạo module testbench có tên "test1"
	testbench test1("TestBench1");
// kết nối các signal với các ngõ vào và ngõ ra của module
	test1 << A_s << B_s << CIN_s << SUM_s << COUT_s;
// chạy mô phỏng trong 200ns
	sc_start(200,SC_NS);
// dừng chương trình tại dòng này
	system("pause");
	return(0);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           