// khai báo file module add1, testbench add1_tsl và vector
// dùng để kết nối các module lại với nhau
#include "add4bit.cpp"
#include "testbench.cpp"
#include "vector.cpp"
int sc_main(int argc, char* argv[])
{
/* Khai báo các tín hiệu được gắn với các module
sc_logic: 1bit
sc_lv: số bit tùy ý
*/
	sc_signal<sc_lv<4> > A_s,B_s,SUM_s;
	sc_signal<sc_logic> A3,A2,A1,A0,B3,B2,B1,B0,S3,S2,S1,S0;
	sc_signal<sc_logic> CIN_s,cout1,cout2,cout3,COUT_s;
// đưa vào hàm để tách giá trị 4bit ra thành từng bit và dán vao các biến 
	vectorIn vector2bits1("Vector_2_BITS1");
	vector2bits1 << A_s << A3 << A2 << A1 << A0;
	vectorIn vector2bits2("Vector_2_BITS2");
	vector2bits2 << B_s << B3 << B2 << B1 << B0;
// khỏi tạo 4 module add1 truyền vào các tín hiệu 1 bit được tách ra ở	module vectorIn, với bit nhớ CIN_s
	BIT_ADDER adder1("BitAdder1");
	adder1 << A0 << B0 << CIN_s << S0 << cout1;
	BIT_ADDER adder2("BitAdder2");
	adder2 << A1 << B1 << cout1 << S1 << cout2;
	BIT_ADDER adder3("BitAdder3");
	adder3 << A2 << B2 << cout2 << S2 << cout3;
	BIT_ADDER adder4("BitAdder4");
	adder4 << A3 << B3 << cout3 << S3 << COUT_s;
// lấy các kết quả 1bit của 4 bộ module add1, nối lại thành SUM_s 4bit
	vectorOut bits2vector("bits2vector");
	bits2vector << S3 << S2 << S1 << S0 << SUM_s;
// khỏi tạo module testbech, thiết lập các giá trị đầu vào để tính toán	hiển thị kết quả
	testbench test1("TestBench1");
	test1 << A_s << B_s << CIN_s << SUM_s << COUT_s;
// chạy mô phỏng trong 200ns
	sc_start(200,SC_NS);
	system("pause");
	return(0);
}