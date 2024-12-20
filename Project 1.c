#include <stdio.h>

#define MAX_EMPLOYEES 10

typedef struct {
    char name[50];
    float salary;
    float insurance;
} Employee;

void calculateInsurance(Employee *emp) {
    emp->insurance = emp->salary * 0.07; // فرض کنید بیمه 7 درصد از حقوق است
}

void printPayslip(Employee emp) {
    printf("فیش حقوقی کارمند: %s\n", emp.name);
    printf("حقوق: %.2f\n", emp.salary);
    printf("بیمه: %.2f\n", emp.insurance);
    printf("مجموع پرداختی: %.2f\n", emp.salary - emp.insurance);
    printf("------------------------------\n");
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int i;

    // ورود اطلاعات کارمندان
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        printf("وارد کردن اطلاعات کارمند %d:\n", i + 1);
        printf("نام کارمند: ");
        scanf("%s", employees[i].name);
        printf("حقوق کارمند: ");
        scanf("%f", &employees[i].salary);

        // محاسبه بیمه
        calculateInsurance(&employees[i]);
    }

    // نمایش فیش حقوقی
    printf("\nفیش حقوقی تمام کارمندان:\n");
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        printPayslip(employees[i]);
    }

    return 0;
}