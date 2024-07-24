#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// public attributes
int userchoice = 0; // selection for place, stocks and items or selection for size, flavor and city
int cash = 0;       // user money
int charge = 0;     // total
int cashadditional; // if user money is insufficient

int selection = 0;

// task 1

// global attributes
int usercity = 0; // user city - plus charge if not within cebu city
int size, flavor, deliverymethod, deliverycharge, friescharge;
/*
    cashadditional - if user money is insufficient
    size - fries size
    flavor - fries flavor
    delivery method - check if dine in, take out or pickup
*/
void sizestrings(), flavorstrings(), delivery(), grabcharge(), foodpcharge(), city(), stocks(), stocksupdate();

// stocks memory
int storereg, storelarge, storejumbo, storemega, storegiga, storetera;

// task 2

int place, barangay, placefee, stocksfee, itemsfee, kitchenscale, strainer, cookingoil, butanegas;
/*
    place - desired location
    barangay - location to determine if it is available or not
    placefee - price of the location
    stocksfee - price of the stocks
    itemsfee - price of the materials
    kitchenscale, strainer, cookingoil, butanegas - items
*/

void locationquestion(), placestrings(), barangayavailability(), locationprice();

// stocks
int stocksreg, stockslarge, stocksjumbo, stocksmega, stocksgiga, stockstera;

// stockprices
int pricereg, pricelarge, pricejumbo, pricemega, pricegiga, pricetera;

// array database of barangays
char barangaylist[25][20] = {"Apas", "Bacayan", "Banilad", "Pit-os", "Talamban", "Danglag", "Jugan", "Nangka", "Tayud", "Tilhaong", "Agus", "Babag", "Gun-ob", "Looc", "Pajo", "Catarman", "Jubay", "San Vicente", "Tayud", "Yati", "Bakilid", "Cabancalan", "Casuntingan", "Maguikay", "Paknaan"};

int main()
{
    printf("WELCOME TO POTATO CORNER - CEBU CITY!\n");
    printf("--------------------------\n");
    while (userchoice < 1 || userchoice > 2)
    {
        printf("Select Option:\n  1. Buy a Fries\n  2. Avail a Franchise\n");
        printf("Your selected option: ");
        scanf("%d", &userchoice);
        selection = userchoice;
        while (userchoice < 1 || userchoice > 2)
        {
            printf("Please select the proper option!");
            scanf("%d", &userchoice);
            selection = userchoice;
        }
    }
    if (selection == 1)
    {
        printf("--------------------------\n");
        userchoice = 0;
        printf("Our available menu for today:\n");
        stocks();
        printf("\n--------------------------\n");
        // fries size
        while (userchoice < 1 || userchoice > 6)
        {
            printf("Select Fries Size: \n  1. Regular - 40 PHP\n  2. Large - 60 PHP\n  3. Jumbo - 90 PHP\n  4. Mega - 120 PHP\n  5. Giga - 190 PHP\n  6. Tera - 220 PHP\n");
            printf("Your preferred Fries Size: ");
            scanf("%d", &userchoice);
            size = userchoice;
            while (userchoice < 1 || userchoice > 6)
            {
                printf("Select the approriate sizes! ");
                scanf("%d", &userchoice);
                size = userchoice;
            }
        }

        printf("--------------------------\n");
        sizestrings();  // declaration on what fries size
        userchoice = 0; // reset for new set of choice

        // flavor
        while (userchoice < 1 || userchoice > 4)
        {
            printf("Select Fries Flavor: \n  1. Cheese\n  2. Sour Cream\n  3. Barbecue\n  4. Chili BBQ\n");
            printf("Your preferred Fries Flavor: ");
            scanf("%d", &userchoice);
            flavor = userchoice;
            while (userchoice < 1 || userchoice > 4)
            {
                printf("Select the approriate flavor! ");
                scanf("%d", &userchoice);
                flavor = userchoice;
            }
        }

        printf("--------------------------\n");
        flavorstrings(); // declaration on what fries flavor
        userchoice = 0;  // reset for new set of choice

        // delivery method
        while (userchoice < 1 || userchoice > 3)
        {
            printf("Select Delivery Method: \n  1. Walk-In\n  2. Pick-up\n  3. Rider Delivery\n");
            printf("Your preferred Delivery Method: ");
            scanf("%d", &userchoice);
            deliverymethod = userchoice;
            while (userchoice < 1 || userchoice > 3)
            {
                printf("Select the approriate delivery method! ");
                scanf("%d", &userchoice);
                deliverymethod = userchoice;
            }
        }

        printf("--------------------------\n");
        delivery();
        if (userchoice == 1)
        {
            grabcharge();
        }
        else if (userchoice == 2)
        {
            foodpcharge();
        }

        printf("\nYour total purchase is %d PHP\n", charge);
        printf("--------------------------\n");
        printf("Enter PHP: ");
        scanf("%d", &cash);
        while (cash < charge)
        {
            printf("Insufficient funds, please add more.\n");
            printf("You need to add %d PHP\n", (cash - charge) * -1);
            printf("Enter additional PHP: ");
            scanf("%d", &cashadditional);
            cash += cashadditional;
        }
        printf("--------------------------\n");
        printf("POTATO CORNER PURCHASE RECIEPT - CEBU CITY, PHILIPPINES\n");
        time_t currentdate = time(0);
        struct tm tm = *gmtime(&currentdate);

        printf("Date: %02d-%02d-%02d %02d:%02d\n\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour + 8, tm.tm_min);

        printf("Fries Information\n\n");

        char sizelibrary[6][20] = {"Regular", "Large", "Jumbo", "Mega", "Giga", "Tera"};
        char flavorlibrary[4][20] = {"Cheese", "Sour Cream", "Barbecue", "Chili BBQ"};

        size -= 1;
        flavor -= 1;
        printf("Order Details\nSize: %s Size\nFlavor: %s\nFries Charge: %d\n\n", sizelibrary[size], flavorlibrary[flavor], friescharge);

        // delivery
        char deliverylibrary[5][20] = {"Walk-In", "Pick-up", "Rider Delivery -", "Grab Food", "Food Panda"};
        deliverymethod -= 1;
        printf("Delivery Information\n\n");
        if (deliverymethod == 3)
        {
            printf("Mode: %s %s", deliverylibrary[2], deliverylibrary[3]);
        }
        else if (deliverymethod == 4)
        {
            printf("Mode: %s %s", deliverylibrary[2], deliverylibrary[4]);
        }
        else
        {
            printf("Mode: %s", deliverylibrary[deliverymethod]);
        }
        printf("\nDelivery Charge: %d\n", deliverycharge);

        printf("--------------------------\n");
        printf("Total: %d PHP\n", charge);
        printf("Cash: %d PHP\n", cash);
        printf("Change: %d PHP\n", cash - charge);
        printf("--------------------------\n");
        printf("Thank you for Purchasing in Potato Corner! Please come again!\n");
        printf("--------------------------\n");
        printf("Fries Stocks Left: \n");
        stocksupdate();
        return 0;
    }
    else
    {
        printf("--------------------------\n");
        locationquestion();
        locationprice();
        printf("--------------------------\n");
        userchoice = 0; // reset the value to make it reusable
        printf("STOCKS:\n\n");
        printf("Enter the number of regular size fries stocks: ");
        scanf("%d", &stocksreg);
        while (stocksreg < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of regular size fries stocks: ");
            scanf("%d", &stocksreg);
        }

        printf("Enter the number of large size fries stocks: ");
        scanf("%d", &stockslarge);
        while (stockslarge < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of large size fries stocks: ");
            scanf("%d", &stockslarge);
        }

        printf("Enter the number of jumbo size fries stocks: ");
        scanf("%d", &stocksjumbo);
        while (stocksjumbo < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of jumbo size fries stocks: ");
            scanf("%d", &stocksjumbo);
        }

        printf("Enter the number of mega size fries stocks: ");
        scanf("%d", &stocksmega);
        while (stocksmega < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of mega size fries stocks: ");
            scanf("%d", &stocksmega);
        }

        printf("Enter the number of giga size fries stocks: ");
        scanf("%d", &stocksgiga);
        while (stocksgiga < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of giga size fries stocks: ");
            scanf("%d", &stocksgiga);
        }

        printf("Enter the number of tera size fries stocks: ");
        scanf("%d", &stockstera);
        while (stockstera < 0)
        {
            printf("Error: Number of stocks cannot be negative.\n");
            printf("Enter the number of tera size fries stocks: ");
            scanf("%d", &stockstera);
        }

        pricereg = stocksreg * 40;
        pricelarge = stockslarge * 60;
        pricejumbo = stocksjumbo * 90;
        pricemega = stocksmega * 120;
        pricegiga = stocksgiga * 190;
        pricetera = stockstera * 220;

        stocksfee = pricereg + pricelarge + pricejumbo + pricemega + pricegiga + pricetera;

        printf("--------------------------\n");

        printf("ITEMS:\n\n");

        userchoice = 0;
        while (userchoice < 1 || userchoice > 2)
        {
            printf("Do you need a Kitchen Scale?\n  1. Yes\n  2. No\n");
            printf("Your answer: ");
            scanf("%d", &userchoice);
            kitchenscale = userchoice;
            while (userchoice < 1 || userchoice > 2)
            {
                printf("Select only the options above!");
                scanf("%d", &userchoice);
                kitchenscale = userchoice;
            }
        }
        if (kitchenscale == 1)
        {
            kitchenscale = 500;
        }
        userchoice = 0;
        while (userchoice < 1 || userchoice > 2)
        {
            printf("Do you need a Strainer\n  1. Yes\n  2. No\n");
            printf("Your answer: ");
            scanf("%d", &userchoice);
            strainer = userchoice;
            while (userchoice < 1 || userchoice > 2)
            {
                printf("Select only the options above!");
                scanf("%d", &userchoice);
                strainer = userchoice;
            }
        }
        if (strainer == 1)
        {
            strainer = 250;
        }
        userchoice = -1;
        while (userchoice < 0)
        {
            printf("How many 500kg cooking oil bags do you need? ");
            scanf("%d", &userchoice);
            cookingoil = 110 * userchoice;
            while (userchoice < 0)
            {
                printf("Negative Numbers are not allowed!");
                scanf("%d", &userchoice);
                cookingoil = 110 * userchoice;
            }
        }
        userchoice = -1;
        while (userchoice < 0)
        {
            printf("How many butane gas cans do you need? ");
            scanf("%d", &userchoice);
            butanegas = 110 * userchoice;
            while (userchoice < 0)
            {
                printf("Negative Numbers are not allowed!");
                scanf("%d", &userchoice);
                butanegas = 75 * userchoice;
            }
        }

        itemsfee = kitchenscale + strainer + cookingoil + butanegas;
        charge = placefee + stocksfee + itemsfee;

        printf("--------------------------\n");
        printf("PRICE SUMMARY: \n\n");

        printf("Franchise Location Fee: %d\n", placefee);
        printf("Franchise Fries Stocks Fee: %d\n", stocksfee);
        printf("Franchise Materials Fee: %d\n", itemsfee);
        printf("TOTAL: %d", charge);

        printf("\n--------------------------\n");
        printf("PAYMENT: \n\n");
        printf("Enter PHP: ");
        scanf("%d", &cash);
        while (cash < charge)
        {
            printf("Insufficient funds, please add more.\n");
            printf("You need to add %d PHP\n", (cash - charge) * -1);
            printf("Enter additional PHP: ");
            scanf("%d", &cashadditional);
            cash += cashadditional;
        }
        printf("--------------------------\n");
        printf("Total: %d PHP\n", charge);
        printf("Cash: %d PHP\n", cash);
        printf("Change: %d PHP\n", cash - charge);
        printf("--------------------------\n");
        printf("Thank you for Purchasing in Potato Corner! Process takes to 3-7 days, we will inform you right ahead!\n");
        return 0;
    }
}

void sizestrings()
{
    printf("You have selected ");
    if (size == 1)
    {
        printf("Regular Size\n");
        charge += 40;
        friescharge = 40;
    }
    else if (size == 2)
    {
        printf("Large Size\n");
        charge += 60;
        friescharge = 60;
    }
    else if (size == 3)
    {
        printf("Jumbo Size\n");
        charge += 90;
        friescharge = 90;
    }
    else if (size == 4)
    {
        printf("Mega Size\n");
        charge += 120;
        friescharge = 120;
    }
    else if (size == 5)
    {
        printf("Giga Size\n");
        charge += 190;
        friescharge = 190;
    }
    else if (size == 6)
    {
        printf("Tera Size\n");
        charge += 220;
        friescharge = 220;
    }
}
void flavorstrings()
{
    printf("You have selected ");
    if (flavor == 1)
    {
        printf("Cheese\n");
    }
    else if (flavor == 2)
    {
        printf("Sour Cream\n");
    }
    else if (flavor == 3)
    {
        printf("Barbecue\n");
    }
    else if (flavor == 4)
    {
        printf("Chili BBQ\n");
    }
}

void delivery()
{
    if (deliverymethod == 1)
    {
        printf("You have selected Walk-In");
    }
    else if (deliverymethod == 2)
    {
        printf("You have selected Pick-up");
    }
    else if (deliverymethod == 3)
    {
        userchoice = 0;
        while (userchoice < 1 || userchoice > 2)
        {
            printf("Select Delivery Courier:\n  1. Grab Food\n  2. Food Panda\n");
            printf("Your preferred delivery courier: ");
            scanf("%d", &userchoice);
            while (userchoice < 1 || userchoice > 2)
            {
                printf("Select the correct delivery courier! ");
                scanf("%d", &userchoice);
            }
            if (userchoice == 1)
            {
                deliverymethod = 4;
                city();
                printf("You have selected Rider Delivery - Grab Food");
            }
            else if (userchoice == 2)
            {
                deliverymethod = 5;
                city();
                printf("You have selected Rider Delivery - Food Panda");
            }
        }
    }
}

void grabcharge()
{
    if (usercity == 1)
    {
        charge += 25;
        deliverycharge = 25;
    }
    else if (usercity == 2)
    {
        charge += 50;
        deliverycharge = 50;
    }
    else if (usercity == 3)
    {
        charge += 100;
        deliverycharge = 100;
    }
}

void foodpcharge()
{
    if (usercity == 1)
    {
        charge += 30;
        deliverycharge = 30;
    }
    else if (usercity == 2)
    {
        charge += 60;
        deliverycharge = 60;
    }
    else if (usercity == 3)
    {
        charge += 120;
        deliverycharge = 120;
    }
}

void city()
{
    while (usercity < 1 || usercity > 3)
    {
        printf("Select Where to Deliver:\n  1. Cebu City\n  2. Mandaue City\n  3. Lapu-Lapu City\n");
        printf("Your selection: ");
        scanf("%d", &usercity);
        while (usercity < 1 || usercity > 3)
        {
            printf("Select the appropriate choices of City! ");
            scanf("%d", &usercity);
        }
    }
}

void stocks()
{
    srand(time(0));
    int reg = rand() % 100 + 5;
    int large = rand() % 100 + 5;
    int jumbo = rand() % 100 + 5;
    int mega = rand() % 100 + 5;
    int giga = rand() % 100 + 5;
    int tera = rand() % 100 + 5;

    storereg = reg;
    storelarge = large;
    storejumbo = jumbo;
    storemega = mega;
    storegiga = giga;
    storetera = tera;
    printf("  Regular: %d Stocks Left\n  Large: %d Stocks Left\n  Jumbo: %d Stocks Left\n  Mega: %d Stocks Left\n  Giga: %d Stocks Left\n  Tera: %d Stocks Left", reg, large, jumbo, mega, giga, tera);
}

void stocksupdate()
{
    size++;
    if (size == 1)
    {
        storereg -= 1;
    }
    else if (size == 2)
    {
        storelarge -= 1;
    }
    else if (size == 3)
    {
        storejumbo -= 1;
    }
    else if (size == 4)
    {
        storemega -= 1;
    }
    else if (size == 5)
    {
        storegiga -= 1;
    }
    else if (size == 6)
    {
        storetera -= 1;
    }
    printf("  Regular: %d Stocks Left\n  Large: %d Stocks Left\n  Jumbo: %d Stocks Left\n  Mega: %d Stocks Left\n  Giga: %d Stocks Left\n  Tera: %d Stocks Left", storereg, storelarge, storejumbo, storemega, storegiga, storetera);
}

void locationquestion()
{
    userchoice = 0;
    while (userchoice < 1 || userchoice > 5)
    {
        printf("Select municipality/city you want to build the franchise: \n  1. Cebu City\n  2. Consolacion\n  3. Lapu-Lapu City\n  4. Lilo-an\n  5. Mandaue City\n");
        printf("Your selected place: ");
        scanf("%d", &userchoice);
        place = userchoice;
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select only the listed places! ");
            scanf("%d", &userchoice);
            place = userchoice;
        }
    }

    printf("--------------------------\n");
    userchoice = 0;
    placestrings();
    barangayavailability();
}

void placestrings()
{
    printf("You have selected ");
    if (place == 1)
    {
        printf("Cebu City\n");
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select barangay you want to build the franchise: \n  1. Apas\n  2. Bacayan\n  3. Banilad\n  4. Pit-os\n  5. Talamban\n");
            printf("Your selected barangay: ");
            scanf("%d", &userchoice);
            barangay = userchoice - 1;
            while (userchoice < 1 || userchoice > 5)
            {
                printf("Select only the listed barangays! ");
                scanf("%d", &userchoice);
                barangay = userchoice - 1;
            }
        }
    }
    else if (place == 2)
    {
        printf("Municipality of Consolacion\n");
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select barangay you want to build the franchise: \n  1. Danglag\n  2. Jugan\n  3. Nangka\n  4. Tayud\n  5. Tilhaong\n");
            printf("Your selected barangay: ");
            scanf("%d", &userchoice);
            barangay = userchoice + 4;
            while (userchoice < 1 || userchoice > 5)
            {
                printf("Select only the listed barangays! ");
                scanf("%d", &userchoice);
                barangay = userchoice + 4;
            }
        }
    }
    else if (place == 3)
    {
        printf("Lapu-Lapu City\n");
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select barangay you want to build the franchise: \n  1. Agus\n  2. Babag\n  3. Gun-ob\n  4. Looc\n  5. Pajo\n");
            printf("Your selected barangay: ");
            scanf("%d", &userchoice);
            barangay = userchoice + 9;
            while (userchoice < 1 || userchoice > 5)
            {
                printf("Select only the listed barangays! ");
                scanf("%d", &userchoice);
                barangay = userchoice + 9;
            }
        }
    }
    else if (place == 4)
    {
        printf("Municipality of Lilo-an\n");
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select barangay you want to build the franchise: \n  1. Catarman\n  2. Jubay\n  3. San Vicente\n  4. Tayud\n  5. Yati\n");
            printf("Your selected barangay: ");
            scanf("%d", &userchoice);
            barangay = userchoice + 14;
            while (userchoice < 1 || userchoice > 5)
            {
                printf("Select only the listed barangays! ");
                scanf("%d", &userchoice);
                barangay = userchoice + 14;
            }
        }
    }
    else if (place == 5)
    {
        printf("Mandaue City\n");
        while (userchoice < 1 || userchoice > 5)
        {
            printf("Select barangay you want to build the franchise: \n  1. Bakilid\n  2. Cabancalan\n  3. Casuntingan\n  4. Maguikay\n  5. Paknaan\n");
            printf("Your selected barangay: ");
            scanf("%d", &userchoice);
            barangay = userchoice + 19;
            while (userchoice < 1 || userchoice > 5)
            {
                printf("Select only the listed barangays! ");
                scanf("%d", &userchoice);
                barangay = userchoice + 19;
            }
        }
    }
}

void barangayavailability()
{
    printf("You have selected %s", barangaylist[barangay]);
    if (barangay == 2 || barangay == 4 || barangay == 5 || barangay == 7 || barangay == 9 || barangay == 12 || barangay == 14 || barangay == 16 || barangay == 18 || barangay == 20 || barangay == 22)
    {
        printf("\n%s is not available to set franchise store since the location is already occupied. Select another location.\n", barangaylist[barangay]);
        locationquestion();
    }
    else
    {
        printf("\n%s is available.\n", barangaylist[barangay]);
    }
}

void locationprice()
{
    if (barangay == 0 || barangay == 1 || barangay == 3 || barangay == 21 || barangay == 23 || barangay == 24)
    {
        placefee = 500000; // cebu city and mandaue city
    }
    else if (barangay == 6 || barangay == 8 || barangay == 10 || barangay == 11 || barangay == 13 || barangay == 15 || barangay == 17 || barangay == 19)
    {
        placefee = 450000; // consolacion, lapu-lapu city and liloan
    }
}