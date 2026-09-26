/*
SET C - Employee Weekly Pay
Write a C program that calculates employee weekly pay and summarizes a payroll session.
Menu: 1 - Process employee | 0 - Close payroll
For each employee, ask for hours worked and hourly rate. Hours may include decimals and must be greater
than zero and no more than 80. The hourly rate must be positive.
The first 40 hours receive the regular hourly rate. Hours beyond 40 receive 1.5 times the hourly rate. Gross
pay equals regular pay plus overtime pay. If gross pay exceeds PHP 5,000.00, deduct 10% of the entire
gross pay; otherwise, deduct nothing. Net pay equals gross pay minus the deduction.
After each employee: display regular and overtime hours, regular pay, overtime pay, gross pay, deduction,
and net pay. Record the results, then return to the menu. Reject invalid menu choices or employee inputs
without recording an employee.
Closing summary (numerical totals only): number of completed employee pay records (one per valid
calculation), sum of gross pay, sum of deductions, sum of net pay, and number of completed records with
more than 40 hours worked. Assume each valid entry is a different employee. Do not ask for or display
employee names or IDs. Invalid entries add nothing to totals. If none were processed, display No employees
processed and zero totals. These are classroom payroll rules, not statutory deduction rules.

*/

#include <stdio.h>

int main(void)
{
    int choice;
    int employeeCount = 0;
    int overtimeCount = 0;

    double hoursWorked, hourlyRate;
    double regularHours, overtimeHours;
    double regularPay, overtimePay;
    double grossPay, deduction, netPay;

    double totalGrossPay = 0.0;
    double totalDeductions = 0.0;
    double totalNetPay = 0.0;

    do
    {
        printf("\nWEEKLY PAY CALCULATOR\n");
        printf("1. Process employee\n");
        printf("0. Close payroll\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        if (choice != 1)
        {
            printf("Invalid menu choice.\n");
            continue;
        }

        printf("Hours worked: ");
        scanf("%lf", &hoursWorked);

        printf("Hourly rate: ");
        scanf("%lf", &hourlyRate);

        if (hoursWorked <= 0.0 || hoursWorked > 80.0 ||
            hourlyRate <= 0.0)
        {
            printf("Invalid input. Hours must be above 0 and at most 80.\n");
            printf("The hourly rate must be positive.\n");
            continue;
        }

        if (hoursWorked > 40.0)
        {
            regularHours = 40.0;
            overtimeHours = hoursWorked - 40.0;
        }
        else
        {
            regularHours = hoursWorked;
            overtimeHours = 0.0;
        }

        regularPay = regularHours * hourlyRate;
        overtimePay = overtimeHours * hourlyRate * 1.5;
        grossPay = regularPay + overtimePay;

        if (grossPay > 5000.0)
        {
            deduction = grossPay * 0.10;
        }
        else
        {
            deduction = 0.0;
        }

        netPay = grossPay - deduction;

        employeeCount++;
        totalGrossPay += grossPay;
        totalDeductions += deduction;
        totalNetPay += netPay;

        if (overtimeHours > 0.0)
        {
            overtimeCount++;
        }

        printf("\nEMPLOYEE PAY RECORD\n");
        printf("Regular hours: %.2f\n", regularHours);
        printf("Overtime hours: %.2f\n", overtimeHours);
        printf("Regular pay: PHP %.2f\n", regularPay);
        printf("Overtime pay: PHP %.2f\n", overtimePay);
        printf("Gross pay: PHP %.2f\n", grossPay);
        printf("Deduction: PHP %.2f\n", deduction);
        printf("Net pay: PHP %.2f\n", netPay);

    } while (choice != 0);

    printf("\nPAYROLL SUMMARY\n");

    if (employeeCount == 0)
    {
        printf("No employees processed.\n");
    }

    printf("Completed employee pay records: %d\n", employeeCount);
    printf("Total gross pay: PHP %.2f\n", totalGrossPay);
    printf("Total deductions: PHP %.2f\n", totalDeductions);
    printf("Total net pay: PHP %.2f\n", totalNetPay);
    printf("Employees with overtime: %d\n", overtimeCount);

    return 0;
}