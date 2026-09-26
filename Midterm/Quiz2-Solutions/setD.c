/*
SET D - Laundry Service Billing
Write a C program that calculates laundry charges and summarizes completed orders.
Menu: 1 - Wash only | 2 - Wash and dry | 0 - Close shop
Rates per kilogram: Wash only PHP 40.00; Wash and dry PHP 65.00. For each order, ask for the laundry
weight in kilograms and processing option: 1 - Regular or 2 - Express. Weight may include decimals and
must be greater than zero and no more than 20 kilograms. Reject invalid choices, weights, or options;
display an error and return to the main menu without recording an order.
Every order has a minimum billable weight of 3 kilograms. Below 3 kilograms, charge for 3; otherwise,
charge for the actual weight without rounding it up. Basic charge equals billable weight multiplied by the
service rate. Express processing adds 25% of the basic charge; Regular has no surcharge. Total charge
equals basic charge plus surcharge.
After each completed order: display service, actual weight, billable weight, basic charge, express
surcharge, and total charge. Assume every valid order is accepted and paid immediately. Record it once,
then return to the menu.
Closing summary (numerical totals only): number of completed orders (one per valid order), total actual
laundry weight (sum of entered weights, not billable weights), total express surcharges collected, total
collection including surcharges, and number of Express orders. Names and IDs are not required. If no orders
were completed, display No orders recorded and zero totals.

*/

#include <stdio.h>

int main(void)
{
    int choice, processingOption;
    int orderCount = 0;
    int expressCount = 0;

    double actualWeight, billableWeight, rate;
    double basicCharge, expressSurcharge, totalCharge;

    double totalActualWeight = 0.0;
    double totalExpressSurcharges = 0.0;
    double totalCollection = 0.0;

    do
    {
        printf("\nLAUNDRY SERVICE BILLING\n");
        printf("1. Wash only\n");
        printf("2. Wash and dry\n");
        printf("0. Close shop\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            rate = 40.0;
            break;
        case 2:
            rate = 65.0;
            break;
        default:
            printf("Invalid service choice.\n");
            continue;
        }

        printf("Laundry weight in kilograms: ");
        scanf("%lf", &actualWeight);

        if (actualWeight <= 0.0 || actualWeight > 20.0)
        {
            printf("Weight must be above 0 and at most 20 kilograms.\n");
            continue;
        }

        printf("Processing option (1 - Regular, 2 - Express): ");
        scanf("%d", &processingOption);

        if (processingOption != 1 && processingOption != 2)
        {
            printf("Invalid processing option.\n");
            continue;
        }

        if (actualWeight < 3.0)
        {
            billableWeight = 3.0;
        }
        else
        {
            billableWeight = actualWeight;
        }

        basicCharge = billableWeight * rate;

        if (processingOption == 2)
        {
            expressSurcharge = basicCharge * 0.25;
        }
        else
        {
            expressSurcharge = 0.0;
        }

        totalCharge = basicCharge + expressSurcharge;

        orderCount++;
        totalActualWeight += actualWeight;
        totalExpressSurcharges += expressSurcharge;
        totalCollection += totalCharge;

        if (processingOption == 2)
        {
            expressCount++;
        }

        printf("\nLAUNDRY RECEIPT\n");

        if (choice == 1)
        {
            printf("Service: Wash only\n");
        }
        else
        {
            printf("Service: Wash and dry\n");
        }

        if (processingOption == 1)
        {
            printf("Processing: Regular\n");
        }
        else
        {
            printf("Processing: Express\n");
        }

        printf("Actual weight: %.2f kg\n", actualWeight);
        printf("Billable weight: %.2f kg\n", billableWeight);
        printf("Basic charge: PHP %.2f\n", basicCharge);
        printf("Express surcharge: PHP %.2f\n", expressSurcharge);
        printf("Total charge: PHP %.2f\n", totalCharge);

    } while (choice != 0);

    printf("\nLAUNDRY SHOP SUMMARY\n");

    if (orderCount == 0)
    {
        printf("No orders recorded.\n");
    }

    printf("Completed orders: %d\n", orderCount);
    printf("Total actual laundry weight: %.2f kg\n", totalActualWeight);
    printf("Total express surcharges: PHP %.2f\n",
           totalExpressSurcharges);
    printf("Total collection: PHP %.2f\n", totalCollection);
    printf("Express orders: %d\n", expressCount);

    return 0;
}