#include <stdio.h>

int main(void) {

    // WELCOME SCREEN

    printf("================================================================================\n");
    printf("                  TAILORING & BOUTIQUE ORDER BOOK SYSTEM                        \n");
    printf("================================================================================\n");
    printf("  Welcome to the Tailoring Order Management System!                             \n");
    printf("  Track customer measurements, fabric requirements.\n");
    printf("--------------------------------------------------------------------------------\n\n");

    // MAIN MENU      

    printf("+------------------------------------------------------------------------------+\n");
    printf("|                                  MAIN MENU                                   |\n");
    printf("+---+--------------------------------------------------------------------------+\n");
    printf("| 1 | Take a New Order                                                         |\n");
    printf("| 2 | Mark Order Delivered                                                     |\n");
    printf("| 3 | Calculate Fabric Required Today                                          |\n");
    printf("| 4 | Search Orders by Customer Name                                           |\n");
    printf("| 5 | View Overdue Orders                                                      |\n");
    printf("| 6 | Save & Load Order Book                                                   |\n");
    printf("| 0 | Exit System                                                              |\n");
    printf("+---+--------------------------------------------------------------------------+\n\n");

    // SPECIMEN ORDER RECORD

    printf("================================================================================\n");
    printf("                            SPECIMEN ORDER RECORD                               \n");
    printf("================================================================================\n");
    printf("  Order No.         : 0065\n");
    printf("  Customer Name     : Rijvi Ahammed Rabby\n");
    printf("  Garment Type      : 2 (Panjabi)\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  Chest Size        : 42 in\n");
    printf("  Garment Length    : 40 in\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  Promised Delivery : Day 15\n");
    printf("  Days Remaining    : 3 Days (Rush Surcharge Applied)\n");
    printf("  Fabric Required   : 2.60 m\n");
    printf("--------------------------------------------------------------------------------\n");

    return 0;
}