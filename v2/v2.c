#include <stdio.h>

#define D 0.25

int main(void)
{
    int OrderNum, ClothingType, Quantity;
    double UnitPrice, Subtotal, Discount, Total;

    printf("================================================================================\n");
    printf("                  TAILORING & BOUTIQUE ORDER BOOK SYSTEM                        \n");
    printf("================================================================================\n");
    printf("   Enter details of one order below \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Enter order num.\t: ");
    scanf("%d", &OrderNum);
    
    printf("Enter cloth type (1 = panjabi)\t: ");
    scanf("%d", &ClothingType);

    printf("Enter Quantity\t: ");
    scanf("%d", &Quantity);

    printf("Eeter unit price\t: ");
    scanf("%lf", &UnitPrice);

    Subtotal = Quantity * UnitPrice;
    Discount = Subtotal * D;
    Total = Subtotal - Discount;

    printf("================================================================================\n");
    printf("                     ORDER RECORD                                               \n");
    printf("================================================================================\n");

    printf(" Order No.\t: %d\n", OrderNum);
    printf("Clothing Type\t: %d\n", ClothingType);
    printf("Quantity\t: %d\n", Quantity);
    printf("Unit price\t: %.2f\n", UnitPrice);
    printf("--------------------------------------------------------------------------------\n");
    printf("Subtotal\t: %.2f BDT\n", Subtotal);
    printf("Discount (25%%)\t: %.2f BDT\n", Discount);
    printf("Total\t: %.2f BDT\n", Total);
    
    return 0;
}