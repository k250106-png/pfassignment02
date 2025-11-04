#include <stdio.h>
#include <string.h>

char *productCodes[] = {"001", "002", "003", "004"};
int stockQuantity[] = {50, 10, 20, 8};
float price[] = {100.0, 200.0, 300.0, 150.0};
int num_product = 4;

float finalBill = 0.0; // moved to global scope for access in showInvoice

void displayInventory();
void addToCart();
float calculateTotalBill();
void showInvoice(char customerName[], char customerCNIC[]);

int main() {
    int choice;
    char customerName[50], customerCNIC[50];

    printf("Customer Information\n");
    printf("Enter your Name: ");
    fgets(customerName, 50, stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; // remove newline from name

    printf("Enter your CNIC: ");
    scanf("%s", customerCNIC);

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Display Inventory\n");
        printf("2. Add new item to cart\n");
        printf("3. Display total bill\n");
        printf("4. Display invoice\n");
        printf("5. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- Displaying Inventory ---\n");
                printf("Code --- Quantity --- Price\n");
                displayInventory(); // ✅ fixed function call
                break;
            case 2:
                printf("\n--- Add New Item to cart ---\n");
                addToCart(); // ✅ fixed function call
                break;
            case 3:
                printf("\n--- Calculating Total Bill ---\n");
                finalBill = calculateTotalBill(); // ✅ save returned value
                break;
            case 4:
                printf("\n--- Displaying Invoice ---\n");
                showInvoice(customerName, customerCNIC); // ✅ pass arguments
                break;
            case 5:
                printf("Thank you for using.\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);

    return 0;
}

void displayInventory() {
    for (int i = 0; i < num_product; i++) {
        printf("%s\t%d\t%.2f\n", productCodes[i], stockQuantity[i], price[i]);
    }
}

void addToCart() {
    char pCode[4];
    int pQuantity;
    float pPrice;

    printf("You can enter 1 product at a time\n");
    printf("Enter the Product Code Id: ");
    scanf("%s", pCode);

    printf("Enter the quantity of product: ");
    scanf("%d", &pQuantity);

    printf("Enter the price per product: ");
    scanf("%f", &pPrice);

    printf("Added %d of product %s at %.2f each.\n", pQuantity, pCode, pPrice);
}

float calculateTotalBill() {
    float last_bill = 0.0;
    float final_price;
    char code[] = "Eid2025";
    char promoCode[10];

    for (int i = 0; i < num_product; i++) {
        int quantity;
        printf("Enter the product quantity for %s: ", productCodes[i]);
        scanf("%d", &quantity);

        last_bill += quantity * price[i];
        stockQuantity[i] -= quantity;
    }

    printf("If you know promo code, enter it for discount: ");
    scanf("%s", promoCode);

    if (strcmp(promoCode, code) == 0) {
        final_price = 0.75 * last_bill;
        printf("Promo code applied! 25%% discount given.\n");
    } else {
        final_price = last_bill;
        printf("No discount applied.\n");
    }

    printf("Your final price is %.2f\n", final_price);

    return final_price;
}

void showInvoice(char customerName[], char customerCNIC[]) {
    printf("\n--- INVOICE ---\n");
    printf("NAME : %s\n", customerName);
    printf("CNIC : %s\n", customerCNIC);
    printf("Your final price after discount is %.2f\n", finalBill);
}
