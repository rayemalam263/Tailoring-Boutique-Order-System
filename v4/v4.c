#include <stdio.h>

// Variable declarations // Nafis
int OrderNum, ClothingType, Quantity;
double UnitPrice, Subtotal, Discount, Total;

// Function prototypes // Rayem
void banner(void);
void read_order(void);
void print_order_record(double subtotal, double Discount, double Total);
void menu(void);
double calculate_subtotal(int quantity, double price);
double calculate_discount(double subtotal);


// MAIN FUNCTION
int main(void) // Rayem
{
    int choice;
    int total_orders = 0;
    double cumulative_revenue = 0.0;
    double cumulative_discount = 0.0;

    banner();

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Adding an order
            read_order();

            Subtotal = calculate_subtotal(Quantity, UnitPrice);
            Discount = calculate_discount(Subtotal);
            Total = Subtotal - Discount;

            print_order_record(Subtotal, Discount, Total);

            cumulative_revenue += Total;
            cumulative_discount += Discount;
            total_orders++;
            break;

        case 2: // Show total summary
            printf("\n================================================================================\n");
            printf("                     ACCUMULATED TOTALS SUMMARY                                 \n");
            printf("================================================================================\n");
            printf("Total orders entered\t: %d\n", total_orders);
            printf("Total discount given\t: %.2f BDT\n", cumulative_discount);
            printf("Total net revenue\t: %.2f BDT\n", cumulative_revenue);
            printf("================================================================================\n");
            break;

        case 3:
            printf("Exiting system. Goodbye!\n");
            break;

        default:
            printf(">>> Invalid choice. Choose 1, 2 or 3.\n");
        }
    } while (choice != 3);

    return 0;
}


// ALL THE FUNCTIONS
void banner(void) { // Rabby
    printf("================================================================================\n");
    printf("                  TAILORING & BOUTIQUE ORDER BOOK SYSTEM (V4)                   \n");
    printf("================================================================================\n");
}

void read_order(void) { // Rabby
    printf("Enter order num\t\t: ");
    scanf("%d", &OrderNum);
    
    printf("Enter cloth type (1 = panjabi)\t: ");
    scanf("%d", &ClothingType);

    printf("Enter Quantity\t\t: ");
    scanf("%d", &Quantity);
    
    if (Quantity < 0) {
        printf("> Quantity cannot be negative\n");
        Quantity = 0;
    }

    printf("Enter unit price\t: ");
    scanf("%lf", &UnitPrice);

    if (UnitPrice < 0.0) {
        printf("> Unit price cannot be negative - set to 0.00.\n");
        UnitPrice = 0.0;
    }
}

void print_order_record(double subtotal, double discount, double total) { // Rabby
    printf("================================================================================\n");
    printf("                     ORDER RECORD                                               \n");
    printf("================================================================================\n");

    printf(" Order No.\t: %d\n", OrderNum);
    printf("Clothing Type\t: %d\n", ClothingType);
    printf("Quantity\t: %d\n", Quantity);
    printf("Unit price\t: %.2f BDT\n", UnitPrice);
    printf("--------------------------------------------------------------------------------\n");
    printf("Subtotal\t: %.2f BDT\n", subtotal);
    printf("Discount\t: %.2f BDT\n", discount);
    printf("Total\t\t: %.2f BDT\n", total);
}

void menu(void) // Nafis
{
    printf("\n================================================================================\n");
    printf("1. Add an order\n");
    printf("2. Show accumulated totals\n");
    printf("3. Exit\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Choice: ");
}

double calculate_subtotal(int quantity, double price) // Rayem
{
    return quantity * price;
}

double calculate_discount(double subtotal) // Rayem
{
    if (subtotal >= 5000.0) {
        return subtotal * 0.25; // 25% off for 5000+ BDT
    } else if (subtotal >= 2000.0) {
        return subtotal * 0.15; // 15% off for 2000-4999 BDT
    } else if (subtotal >= 1000.0) {
        return subtotal * 0.10; // 10% off for 1000-1999 BDT
    } else {
        return 0.0; // No discount below 1000 BDT
    }
}