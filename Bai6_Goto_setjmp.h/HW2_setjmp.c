#include <stdio.h>
#include <setjmp.h>
#include <string.h>

jmp_buf buf; 
int exception_code;
char* messageError="";

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

#define TRY if ((exception_code = setjmp(buf)) == NO_ERROR) 
#define CATCH(x) else if (exception_code == (x))
#define THROW(x,text) messageError=text ;longjmp(buf, (x))

void readFile() {
    printf("Doc file...\n");
    THROW(FILE_ERROR, "Loi doc file: File khong ton tai.");
}

void networkOperation() {
    printf("Dang ket noi...\n");
    THROW(FILE_ERROR, "Loi mang: Khong the ket noi voi may chu.");
}

void calculateData() {
    printf("Dang thuc hien phep tinh...\n");
    THROW(FILE_ERROR, "Loi: Phep tinh co van de!.");
}

int main() {
    TRY {
         readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {   
        printf("%s\n",messageError);
    } CATCH(NETWORK_ERROR) {
        printf("%s\n",messageError);
    } CATCH(CALCULATION_ERROR) {
        printf("%s\n",messageError);
    }

    printf("Chuong trinh ket thuc\n");
    return 0;
}
