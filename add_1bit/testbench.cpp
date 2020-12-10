// khai báo thư viện systemc
#include "systemc.h"

SC_MODULE (testbench)
{
/* 
khai báo ngõ ra tương ứng với các ngõ vào của SC_MODULE(BIT_ADDER) và ngược lại.
 dùng để kiểm tra các trường hợp tính toán
 sc_out <kiểu dữ liệu> tên cổng
   sc_logic : 1,0,x,z*/
	sc_out<sc_logic> A_p,B_p,CIN_p;
// sc_in <kiểu dữ liệu> tên cổng
	sc_in<sc_logic> SUM_p,COUT_p;
/* Khai báo process kiểu SC_THREAD, giống với SC_METHOD ,đây cũng là 1 kiểu sử dụng bộ nhạy
 khối của testbench. SC_THREAD có khả năng tạm dừng chính nó bằng cách sử dụng câu lệnh wait.
*/
	SC_CTOR (testbench)
	{
		SC_THREAD (process);
	}
// hàm xử lý chức năng
	void process()
	{
// gán giá trị 0 hoặc 1 cho a, b và cin
// trường hợp a=0, b=0, cin=0.
		A_p = SC_LOGIC_0;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_0;

// delay 10ns
		wait (10, SC_NS);
// in kết quả
		print();
// trường hợp a=0, b=0, cin=1
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_0;
// delay 5ns, cho phép cập nhật tín hiệu
		wait (5, SC_NS);

// in kết quả
		print();
// trường hợp a=1, b=0, cin=1
		A_p = SC_LOGIC_1;
		B_p = SC_LOGIC_0;
		CIN_p = SC_LOGIC_1;
// delay 5ns, cho phép cập nhật tín hiệu
		wait (5, SC_NS);

// in kết quả
		print();
// dừng mô phỏng
		sc_stop();
	}
// hàm in kết quả
	void print()
	{
// in thời gian thực hiện từng trường hợp
		cout << "At time " << sc_time_stamp() << "::";
		cout << "(a,b,carry_in): ";
// in giá trị ngõ vào
		cout << A_p.read() << "+" << B_p.read() << "+" << CIN_p.read();
// in giá trị đầu ra
		cout << " (carry_out,sum): " << COUT_p.read() << SUM_p.read() <<
		endl;
	}
};