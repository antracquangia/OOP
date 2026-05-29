# Bài 2:
Công ty Bất động sản VAKALAND có nhu cầu quản lý danh sách các giao dịch bất 
động sản, hiện tại công ty có 3 loại giao dịch: 

Giao dịch Đất: Mã giao dịch, ngày giao dịch, đơn giá, loại đất (“A”, “B”, “C”), 
diện tích. 
* Nếu là loại B, C thì: thành tiền = diện tích * đơn giá. 
* Nếu là loại A thì: thành tiền = diện tích * đơn giá * 1.5.

 Giao dịch Nhà phố: Mã giao dịch, ngày giao dịch, đơn giá, loại nhà (“cao cấp”, 
“thường”), địa chỉ, diện tích. 
* Nếu là loại nhà cao cấp thì: thành tiền = diện tích * đơn giá. 
* Nếu là loại thường thì: thành tiền = diện tích * đơn giá * 90%.

Giao dịch Căn hộ chung cư: Mã giao dịch, ngày giao dịch, đơn giá, mã căn, vị 
trí tầng, diện tích. 
* Nếu vị trí tầng là 1 thì: thành tiền = diện tích * đơn giá * 2. 
* Nếu vị trí tầng từ 15 trở lên thì: thành tiền = diện tích * đơn giá * 1.2. 
* Các vị trí tầng còn lại thì : thành tiền = diện tích * đơn giá. 

Áp dụng tính kế thừa và đa hình, thiết kế các lớp và xây dựng chương trình cho phép 
thực hiện các yêu cầu sau: 
* Nhập danh sách các giao dịch Đất, Nhà phố, Căn hộ chung cư 
* Tính tổng số lượng cho từng loại. 
* Tính trung bình thành tiền của giao dịch Căn hộ chung cư 
* Cho biết Giao dịch Nhà phố có trị giá cao nhất (thành tiền) 
* Xuất ra danh sách các giao dịch của tháng 12 năm 2024.
