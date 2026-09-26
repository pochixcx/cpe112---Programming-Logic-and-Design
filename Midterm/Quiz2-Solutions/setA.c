/*
SET A - Parking Fee Collection
Write a C program that helps a parking attendant process vehicles and summarize collections during a shift.
Menu: 1 - Motorcycle | 2 - Car | 3 - Van | 0 - Close shift
Hourly rates are PHP 10.00 for motorcycles, PHP 20.00 for cars, and PHP 30.00 for vans.
For each vehicle, ask for its parking duration in whole minutes, from 1 to 1,440. Charge every started hour as
one full hour: 60 minutes equals one billable hour, while 61 minutes equals two. Calculate the basic fee using
the vehicle's rate. Add a one-time PHP 50.00 surcharge if the actual duration exceeds 480 minutes.
After each valid transaction: display the vehicle type, billable hours, basic fee, surcharge, and total fee.
Assume the fee is paid immediately, then return to the menu.
Reject invalid menu choices or durations without recording a transaction. On closing: display the total
vehicles processed, total fees collected including surcharges, and number of vehicles charged a surcharge,
then end. If none were processed, display No transactions recorded and zero totals.
*/

#include <stdio.h>

int main(void)
{
    int choice;
    int minutes, billableHours;
    int vehicleCount = 0;
    int surchargeCount = 0;

    double hourlyRate, basicFee, surcharge, totalFee;
    double totalCollection = 0.0;

    do
    {
        printf("\nPARKING FEE COLLECTION\n");
        printf("1. Motorcycle\n");
        printf("2. Car\n");
        printf("3. Van\n");
        printf("0. Close shift\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            hourlyRate = 10.0;
            break;
        case 2:
            hourlyRate = 20.0;
            break;
        case 3:
            hourlyRate = 30.0;
            break;
        default:
            printf("Invalid vehicle type.\n");
            continue;
        }

        printf("Parking duration in whole minutes: ");
        scanf("%d", &minutes);

        if (minutes < 1 || minutes > 1440)
        {
            printf("Duration must be from 1 to 1440 minutes.\n");
            continue;
        }

        billableHours = minutes / 60;

        if (minutes % 60 != 0)
        {
            billableHours++;
        }

        basicFee = billableHours * hourlyRate;
        surcharge = 0.0;

        if (minutes > 480)
        {
            surcharge = 50.0;
        }

        totalFee = basicFee + surcharge;

        vehicleCount++;
        totalCollection += totalFee;

        if (surcharge > 0.0)
        {
            surchargeCount++;
        }

        printf("\nPARKING RECEIPT\n");
        printf("Vehicle type: ");

        switch (choice)
        {
        case 1:
            printf("Motorcycle\n");
            break;
        case 2:
            printf("Car\n");
            break;
        case 3:
            printf("Van\n");
            break;
        }

        printf("Parking duration: %d minutes\n", minutes);
        printf("Billable hours: %d\n", billableHours);
        printf("Basic fee: PHP %.2f\n", basicFee);
        printf("Surcharge: PHP %.2f\n", surcharge);
        printf("Total fee: PHP %.2f\n", totalFee);

    } while (choice != 0);

    printf("\nSHIFT SUMMARY\n");

    if (vehicleCount == 0)
    {
        printf("No transactions recorded.\n");
    }

    printf("Vehicles processed: %d\n", vehicleCount);
    printf("Total fees collected: PHP %.2f\n", totalCollection);
    printf("Vehicles charged a surcharge: %d\n", surchargeCount);

    return 0;
}