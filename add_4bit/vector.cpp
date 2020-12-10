// khai báo thư viện systemc
#include "systemc.h"
/* khai báo ngõ vào và ngõ ra của SC_MODULE(vectorIn)
dùng tách tín hiệu ngõ vào A và B 4bit từ module testbench thành các tín hiệu
A0, A1, A2, A3 và B0, B1, B2, B3
để đưa vào 4 bộ add1*/
SC_MODULE (vectorIn)
{
	sc_in<sc_lv<4> > I;
	sc_out<sc_logic> O3,O2,O1,O0;
/* khối khởi tạo các module, khai báo một phương thức "process" với kiểu	
 với danh sách nhạy là các ngõ vào I. Process sẽ được thực hiện khi các
 */
	
	SC_CTOR (vectorIn)
	{
		SC_METHOD (process);
		sensitive << I;
	}
	void process()
	{
// đọc I lưu vào biến temp 4 bit
		sc_lv<4> temp = I.read();
// gán từng giá trị của temp vào các ngõ ra
		O3 = temp[3];
		O2 = temp[2];
		O1 = temp[1];
		O0 = temp[0];
	}
};
/* khai báo ngõ vào và ngõ ra của SC_MODULE(vectorOut)
nối các kết quả của 4 bộ add1 thành tín hiệu 4 bit đưa vào testbench để hiển
thị*/
SC_MODULE (vectorOut)
{
	sc_in<sc_logic> O3,O2,O1,O0;
	sc_out<sc_lv<4> > S;
	SC_CTOR (vectorOut)
	{
// khối khởi tạo các module, khai báo một phương thức "process"
		
// với danh sách nhạy là các ngõ vào. Process sẽ được thực hiện
		
		SC_METHOD (process);
		sensitive << O3 << O2 << O1 << O0 ;
		//sensitive << O3 << O2 << O1 << O0 << S;
	}
	void process()
	{
// tạo biến temp 4 bit
		sc_lv<4> temp;
// gán tứng ngõ ra từ add1 vào temp
		temp[3] = O3;
		temp[2] = O2;
		temp[1] = O1;
		temp[0] = O0;
		S = temp;
	}
};