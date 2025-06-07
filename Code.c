#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct bill
{
    int id;
    char prod_name[50];
    int qty;
    int price;
};

struct bill b[20] = {{1, "Sandisk 16 GB ", 0, 355},
              {2, "Logitech Mouse", 0, 500},
              {3, "RGB keyboard  ", 0, 700},
              {4, "APPLE Macbook ", 0, 100000},
              {5, "DELL          ", 0, 50000},
              {6, "Lenovo        ", 0, 28000},
              {7, "Iphone 11     ", 0, 50000},
              {8, "Nokia 8       ", 0, 15000},
              {9, "Samsung  Fold ", 0, 120000},
              {10, "Fastrack      ", 0, 5000},
              {11, "Casio         ", 0, 18000},
              {12, "Titan         ", 0, 10000},
              {13, "Sonata        ", 0, 2500},
              {14, "Canon         ", 0, 85000},
              {15, "Nikon         ", 0, 65000},
              {16, "Sony          ", 0, 90000},
              {17, "GOPRO         ", 0, 25000},
              {18, "Apple AirPods ", 0, 20000},
              {19, "Boat Bassheads", 0, 6900},
              {20, "Noise neckband", 0, 4900}};

char name[20];
int totalCost = 0;
int choice_id;

void buy_product()
{
    printf("\nEnter quantity you want to buy : ");
    scanf("%d", &b[choice_id].qty);
    totalCost += b[choice_id].qty * b[choice_id].price;
    printf("\nYour cart costs Rs.  %d .\n", totalCost);
}

void add_product()
{
    int extra_qty;
    printf("\nEnter quantity you want to buy more : ");
    scanf("%d", &extra_qty);
    b[choice_id].qty += extra_qty;
    totalCost += extra_qty * b[choice_id].price;
    printf("\nYour cart costs Rs.  %d .\n", totalCost);
}

void delete_product()
{
    int extra_qty;
    printf("\nEnter quantity you want to remove : ");
    scanf("%d", &extra_qty);
    b[choice_id].qty -= extra_qty;
    totalCost -= extra_qty * b[choice_id].price;
    printf("\nYour cart costs Rs.  %d .\n", totalCost);
}

void print_bill()
{
    totalCost = 0;
    printf("%s's cart\n", name);
    printf("Id\t\t\tProduct Name\t\t\tQuantity\t\tTotal Cost\n\n");
    for (int i = 0; i < 20; i++)
    {
        if (b[i].qty != 0)
        {
            int cost = b[i].qty * b[i].price;
            printf("%d\t\t\t%s\t\t\t%d\t\t\t%d\n", b[i].id, b[i].prod_name, b[i].qty, cost);
            totalCost += cost;
        }
    }
    if (totalCost > 100000 && totalCost <= 199999)
        totalCost -= 0.1 * totalCost;
    else if (totalCost > 200000)
        totalCost -= 0.2 * totalCost;
    printf("\n\nYour total bill is : Rs. %d \n", totalCost);
}

int main()
{
    printf("                             ====================================     \n");
    printf("                                    ONLINE ELECTRONIC STORE           \n");
    printf("                             ====================================     \n\n");
    printf("Please Enter Your Name - ");
    scanf("%s", name);
    for (int i = 0; i < strlen(name); i++)
        name[i] = toupper(name[i]);

    int choice;
    printf("\nHello %s, Welcome to our Online Store .\n\n", name);
    do
    {
        printf("\t\t------------->MENU<-------------\n");
        printf("1->Buy a product!\n2->Add a product!\n3->Delete a product!\n4->Print the bill!\n0->Exit the Program!\nPlease give your choice  : ");
        scanf("%d", &choice);
        int temp;
        if (choice == 1 || choice == 2 || choice == 3)
        {
            printf("\t\t------------->MENU<-------------\n");
            printf("ID\t\t\tProduct Name\t\t\tPrice\n\n");
            for (int i = 0; i < 20; i++)
                printf("%d\t\t\t%s\t\t\t%d\n", b[i].id, b[i].prod_name, b[i].price);
            printf("\n10%%discount will be applied if total amount is above Rs.1 Lakh!\n");
            printf("\n20%%discount will be applied if total amount is above Rs.2 Lakh!\n");
            printf("\nPlease enter your choice - ");
            scanf("%d", &temp);
            choice_id = temp - 1;
            printf("\nYou chose %s with price Rs.  %d .", b[choice_id].prod_name, b[choice_id].price);
        }
        switch (choice)
        {
        case 1:
            buy_product();
            break;
        case 2:
            add_product();
            break;
        case 3:
            delete_product();
            break;
        case 4:
            print_bill();
            exit(4);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Wrong choice !!");
            break;
        }

    } while (choice != 0);
}

