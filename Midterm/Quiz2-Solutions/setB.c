/*
SET B - Store Cashier Checkout
Write a C program that processes customer purchases and maintains store sales totals.
Menu: 1 - Add item | 2 - Checkout customer | 0 - Close store
Start with an empty purchase. For each item, ask for a positive unit price and positive whole-number quantity.
Calculate its cost, add it to the purchase, and display the updated subtotal. Count units purchased, not merely
item entries. Reject invalid entries without changing totals.
At checkout, reject an empty purchase. Otherwise, apply a 10% discount if the subtotal is at least PHP
1,000.00, then ask for payment. If payment is insufficient, reject it and return to the menu while retaining the
purchase. Rejected payments are not accumulated.
After sufficient payment: display item quantity, subtotal, discount, final bill, payment, and change. Add the
completed sale to store totals once, then clear the purchase for the next customer.
Reject unsupported menu choices and return to the menu. Do not allow closing while a purchase contains
unchecked-out items.
Closing summary (numerical totals only): number of completed customer purchases (one per successful
checkout), total units sold (sum of quantities), total discounts given, and total sales (sum of final bills after
discounts, excluding excess payment and change). Include completed purchases only; failed checkout
attempts add nothing. Do not ask for or display customer names or IDs. If no purchases were completed,
display No completed sales and zero totals
*/

#include <stdio.h>

int main(void)
{
    int choice;
    int quantity;
    int currentUnits = 0;

    int completedPurchases = 0;
    int totalUnitsSold = 0;
    int storeOpen = 1;

    double unitPrice, itemCost;
    double subtotal = 0.0;
    double discount, finalBill, payment, change;

    double totalDiscounts = 0.0;
    double totalSales = 0.0;

    while (storeOpen)
    {
        printf("\nSTORE CASHIER\n");
        printf("1. Add item\n");
        printf("2. Checkout customer\n");
        printf("0. Close store\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Unit price: ");
            scanf("%lf", &unitPrice);

            printf("Quantity: ");
            scanf("%d", &quantity);

            if (unitPrice <= 0.0 || quantity <= 0)
            {
                printf("Price and quantity must be positive.\n");
                break;
            }

            itemCost = unitPrice * quantity;
            subtotal += itemCost;
            currentUnits += quantity;

            printf("Item cost: PHP %.2f\n", itemCost);
            printf("Current subtotal: PHP %.2f\n", subtotal);
            break;

        case 2:
            if (currentUnits == 0)
            {
                printf("No items to check out.\n");
                break;
            }

            discount = 0.0;

            if (subtotal >= 1000.0)
            {
                discount = subtotal * 0.10;
            }

            finalBill = subtotal - discount;

            printf("Amount due: PHP %.2f\n", finalBill);
            printf("Payment: ");
            scanf("%lf", &payment);

            if (payment < finalBill)
            {
                printf("Insufficient payment. Payment rejected.\n");
                printf("Current purchase has been retained.\n");
                break;
            }

            change = payment - finalBill;

            printf("\nCUSTOMER RECEIPT\n");
            printf("Item quantity: %d\n", currentUnits);
            printf("Subtotal: PHP %.2f\n", subtotal);
            printf("Discount: PHP %.2f\n", discount);
            printf("Final bill: PHP %.2f\n", finalBill);
            printf("Payment: PHP %.2f\n", payment);
            printf("Change: PHP %.2f\n", change);

            completedPurchases++;
            totalUnitsSold += currentUnits;
            totalDiscounts += discount;
            totalSales += finalBill;

            /* Prepare an empty purchase for the next customer. */
            currentUnits = 0;
            subtotal = 0.0;
            break;

        case 0:
            if (currentUnits > 0)
            {
                printf("Complete the current purchase before closing.\n");
            }
            else
            {
                storeOpen = 0;
            }
            break;

        default:
            printf("Invalid menu choice.\n");
        }
    }

    printf("\nSTORE SUMMARY\n");

    if (completedPurchases == 0)
    {
        printf("No completed sales.\n");
    }

    printf("Completed customer purchases: %d\n", completedPurchases);
    printf("Total units sold: %d\n", totalUnitsSold);
    printf("Total discounts: PHP %.2f\n", totalDiscounts);
    printf("Total sales after discounts: PHP %.2f\n", totalSales);

    return 0;
}