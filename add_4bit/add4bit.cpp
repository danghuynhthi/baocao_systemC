// khai báo thư viện systemc
#include "systemc.h"
// khai báo một bộ cộng ADDER 1-bit là SC_MODULE với ngõ vào a,b,cin và ngõ ra sum,cout
SC_MODULE (BIT_ADDER)
{
// sc_in <kiểu dữ liệu> tên cổng 
	sc_in<sc_logic> a,b,cin;
// sc_out <kiểu dữ liệu> tên cổng
	sc_out<sc_logic> sum,cout;
/*
 khối khởi tạo các module, khai báo một phương thức "process" với kiểu SC_METHOD, khác với SC_THREAD  kiểu SC_METHOD ko có wait trong nó
 với danh sách nhạy là các ngõ vào a, b, cin. Process sẽ được thực hiện khi các tín hiệu này thay đổi.
*/
	SC_CTOR (BIT_ADDER)
	{
		SC_METHOD (process);
		sensitive << a << b << cin;
	}
// hàm xử lý chức năng của module ADDER_1B
	void process()
	{
// khai báo các biến kiểu "logic" được sử dụng trong tính toán
		sc_logic aANDb,aXORb,cinANDaXORb,aORb,aORbANDc;
// thực hiện các phép tính trung gian cho bộ cộng 1-BIT với các biến aANDb, aXORb, cinANDaXORb
// để đọc đầu vào từ một cổng, người ta phải sử dụng định dạng: "port_name.read ()"
		aANDb = a.read() & b.read();
// dấu ^ là phép XOR, tức là phép cộng không dấu a và b (a XOR b)
		aXORb = a.read() ^ b.read();
// tính (a XOR b) XOR cin lưu vào sum
		sum = aXORb ^ cin.read();
		aORb=a.read()|b.read();
		aORbANDc=aORb & cin.read();

// số nhớ: (a AND b) OR cin
		cout = aANDb | aORbANDc;
	}
};

