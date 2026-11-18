#include <stdio.h>

// Variable declarations // Nafis
int OrderNum, ClothingType, Quantity;
double UnitPrice, Subtotal, Discount, Total;

// Function prototypes // Rayem
void banner(void);
void read_order(void);
int select_clothing_type(void);
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

    // Category-specific quantity and revenue accumulators
    int count_panjabi = 0, count_sherwani = 0, count_kurta = 0, count_salwar = 0;
    double rev_panjabi = 0.0, rev_sherwani = 0.0, rev_kurta = 0.0, rev_salwar = 0.0;

    banner();

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            read_order();

            Subtotal = calculate_subtotal(Quantity, UnitPrice);
            Discount = calculate_discount(Subtotal);
            Total = Subtotal - Discount;

            print_order_record(Subtotal, Discount, Total);

            cumulative_revenue += Total;
            cumulative_discount += Discount;
            total_orders++;

            switch (ClothingType) {
                case 1:
                    count_panjabi += Quantity;
                    rev_panjabi += Total;
                    break;
                case 2:
                    count_sherwani += Quantity;
                    rev_sherwani += Total;
                    break;
                case 3:
                    count_kurta += Quantity;
                    rev_kurta += Total;
                    break;
                case 4:
                    count_salwar += Quantity;
                    rev_salwar += Total;
                    break;
            }
            break;

        case 2:
            printf("\n================================================================================\n");
            printf("                     ACCUMULATED TOTALS & CLOTHING BREAKDOWN                    \n");
            printf("================================================================================\n");
            printf("Total orders entered\t: %d\n", total_orders);
            printf("--------------------------------------------------------------------------------\n");
            
            if (total_orders == 0) {
                printf("No orders have been entered yet.\n");
            } else {
                printf("Clothing Type breakdown (Only purchased items shown):\n");
                
                if (count_panjabi > 0) {
                    printf("  - Panjabi     : Qty Sold = %-3d | Total Revenue = %.2f BDT\n", count_panjabi, rev_panjabi);
                }
                if (count_sherwani > 0) {
                    printf("  - Sherwani    : Qty Sold = %-3d | Total Revenue = %.2f BDT\n", count_sherwani, rev_sherwani);
                }
                if (count_kurta > 0) {
                    printf("  - Kurta       : Qty Sold = %-3d | Total Revenue = %.2f BDT\n", count_kurta, rev_kurta);
                }
                if (count_salwar > 0) {
                    printf("  - Salwar Kam. : Qty Sold = %-3d | Total Revenue = %.2f BDT\n", count_salwar, rev_salwar);
                }
            }
            
            printf("--------------------------------------------------------------------------------\n");
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

int select_clothing_type(void) { // Nafis
    int cloth_choice;
    
    printf("\n--- SELECT CLOTHING TYPE ---\n");
    printf("1. Panjabi\n");
    printf("2. Sherwani\n");
    printf("3. Kurta\n");
    printf("4. Salwar Kameez\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &cloth_choice);

    switch (cloth_choice) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        default:
            printf(">> Invalid selection. default to panjabi\n");
            return 1;
    }
}

void read_order(void) { // Rabby
    printf("\nEnter order num\t\t: ");
    scanf("%d", &OrderNum);
    
    ClothingType = select_clothing_type();

    printf("Enter Quantity\t\t: ");
    scanf("%d", &Quantity);
    
    if (Quantity < 0) {
        printf(">>> Quantity cannot be negative - set to 0.\n");
        Quantity = 0;
    }

    printf("Enter unit price\t: ");
    scanf("%lf", &UnitPrice);

    if (UnitPrice < 0.0) {
        printf(">>> Unit price cannot be negative - set to 0.00.\n");
        UnitPrice = 0.0;
    }
}

void print_order_record(double subtotal, double discount, double total) { // Rabby
    printf("================================================================================\n");
    printf("                     ORDER RECORD                                               \n");
    printf("================================================================================\n");

    printf(" Order No.\t: %d\n", OrderNum);
    
    printf("Clothing Type\t: ");
    switch (ClothingType) {
        case 1:
            printf("Panjabi\n");
            break;
        case 2:
            printf("Sherwani\n");
            break;
        case 3:
            printf("Kurta\n");
            break;
        case 4:
            printf("Salwar Kameez\n");
            break;
        default: 
            printf("Custom / Other\n");
    }

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
        return subtotal * 0.25;
    } else if (subtotal >= 2000.0) {
        return subtotal * 0.15;
    } else if (subtotal >= 1000.0) {
        return subtotal * 0.10;
    } else {
        return 0.0;
    }
}