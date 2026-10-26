#include <stdio.h>
#define D 0.25 //D is the discount

// Variable decrarations // Nafis
int OrderNum, ClothingType, Quantity;
double UnitPrice, Subtotal, Discount, Total;

// Function prototypes // Rabby
void banner(void);
void read_order(void);
void print_order_record(double subtotal, double Discount, double Total);
void menu(void);
double calculate_subtotal(int quantity, double price);
double calculate_discount(double subtotal);


// MAIN FUNCTION
int main(void) // Rayem
{
    banner();
    menu();
    read_order();

    Subtotal = calculate_subtotal(Quantity, UnitPrice);
    Discount = calculate_discount(Subtotal);
    Total = Subtotal - Discount;

    print_order_record(Subtotal, Discount, Total);

    return 0;
}


// ALL THE FUNCTIONS
void banner(void) { // Rabby

    printf("================================================================================\n");
    printf("                  TAILORING & BOUTIQUE ORDER BOOK SYSTEM                        \n");
    printf("================================================================================\n");

}

void read_order(void){ //Rabby

    printf("Enter order num.\t: ");
    scanf("%d", &OrderNum);
    
    printf("Enter cloth type (1 = panjabi)\t: ");
    scanf("%d", &ClothingType);

    printf("Enter Quantity\t: ");
    scanf("%d", &Quantity);

    printf("Enter unit price\t: ");
    scanf("%lf", &UnitPrice);


}

void print_order_record(double subtotal, double Discount, double Total){ //Rabby

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

}

void menu(void) // Nafis
{
    printf("   Enter details of one order below \n");
    printf("--------------------------------------------------------------------------------\n");
}

double calculate_subtotal(int quantity, double price) // Rayem
{
    return quantity * price;
}

double calculate_discount(double subtotal) //Rayem
{
    return subtotal * D;
}
