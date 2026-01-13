#include <stdio.h>   // Thư viện chuẩn input/output (printf, scanf, ...)
#include <string.h>  // Thư viện xử lý chuỗi (strlen, strcpy, strcat, strcmp, ...)

int main() {
    // Khai báo các chuỗi
    char str1[50] = "Hello";    // Chuỗi 1
    char str2[50] = "World";    // Chuỗi 2
    char str3[100];             // Chuỗi dùng để lưu kết quả
    char *ptr;                  // Con trỏ dùng để tìm ký tự hoặc substring

    // 1️⃣ strlen() - tính độ dài chuỗi
    // Trả về số ký tự trước ký tự null '\0', không tính '\0'
    printf("Length of str1: %zu\n", strlen(str1));

    // 2️⃣ strcpy() - sao chép chuỗi
    // sao chép nội dung str1 vào str3, ghi đè toàn bộ str3
    strcpy(str3, str1);
    printf("After strcpy, str3: %s\n", str3);

    // 3️⃣ strcat() - nối chuỗi
    // Nối thêm str2 vào cuối str3
    strcat(str3, " ");       // thêm dấu cách trước khi nối str2
    strcat(str3, str2);      // nối str2 vào str3
    printf("After strcat, str3: %s\n", str3);

    // 4️⃣ strcmp() - so sánh chuỗi
    // trả về:
    // 0 nếu 2 chuỗi bằng nhau
    // <0 nếu str1 < str2 (theo bảng ASCII)
    // >0 nếu str1 > str2
    int cmp = strcmp(str1, str2);
    printf("strcmp(str1, str2): %d\n", cmp);

    // 5️⃣ strchr() - tìm ký tự trong chuỗi
    // trả về con trỏ tới ký tự đầu tiên tìm thấy
    // hoặc NULL nếu không tìm thấy
    ptr = strchr(str3, 'o');  // tìm ký tự 'o' trong str3
    if(ptr)
        printf("First occurrence of 'o' in str3: %s\n", ptr); 
        // in ra từ vị trí ký tự tìm thấy đến hết chuỗi

    // 6️⃣ strstr() - tìm substring (chuỗi con)
    // trả về con trỏ tới vị trí xuất hiện đầu tiên của chuỗi con
    // hoặc NULL nếu không tìm thấy
    ptr = strstr(str3, "World"); 
    if(ptr)
        printf("Substring 'World' found in str3: %s\n", ptr);

    // 7️⃣ sprintf() - in ra chuỗi theo định dạng
    // giống printf nhưng ghi vào buffer thay vì in ra terminal
    sprintf(str3, "%s %s %d", str1, str2, 2026); 
    // tạo chuỗi "Hello World 2026" trong str3
    printf("After sprintf, str3: %s\n", str3);

    // 8️⃣ strncpy() - sao chép một phần chuỗi
    // chỉ sao chép tối đa 3 ký tự từ str1 sang str4
    char str4[10];
    strncpy(str4, str1, 3); // copy 3 ký tự đầu
    str4[3] = '\0';         // phải tự thêm null terminate
    printf("After strncpy, str4: %s\n", str4);

    return 0; // kết thúc chương trình
}
