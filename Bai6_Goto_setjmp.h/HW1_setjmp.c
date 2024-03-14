#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char* messageError="";

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x,text) messageError=text ;longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1,"Error: Khong duoc chia cho 0"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    if (b == 30) {
        THROW(2,"Error: Anh khong sai, Em khong sai -> 30 Shine"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 30;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("%s\n",messageError);
    } CATCH(2) {
        printf("%s\n",messageError);
    }


    // Các xử lý khác của chương trình
    return 0;
}
