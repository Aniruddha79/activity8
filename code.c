#include <stdio.h>
#include <string.h>

struct Flower {
    int srNo;
    int quantity;
    int type;
    int price;
};

const char* getFlowerName(int type) {
    switch (type) {
        case 1: return "Rose";
        case 2: return "Marigold";
        case 3: return "Lotus";
        case 4: return "Mogra";
        default: return "Others";
    }
}

int getFlowerPrice(int type) {
    switch (type) {
        case 1: return 40;
        case 2: return 35;
        case 3: return 30;
        case 4: return 45;
        default: return 25;
    }
}

int main() {
    int n, totalAmount = 0;

    printf("Enter how many types of flowers you take: ");
    scanf("%d", &n);

    struct Flower flowers[n];

    for (int i = 0; i < n; i++) {
        printf("Enter sr.no:\n");
        scanf("%d", &flowers[i].srNo);

        printf("Enter quantity:\n");
        scanf("%d", &flowers[i].quantity);

        printf("Enter number of flower (1-Rose, 2-Marigold, 3-Lotus, 4-Mogra, else-Others):\n");
        scanf("%d", &flowers[i].type);

        flowers[i].price = getFlowerPrice(flowers[i].type);
        totalAmount += flowers[i].price * flowers[i].quantity;
    }

    FILE *fptr;
    fptr = fopen("code.txt", "w");

    fprintf(fptr, "\n\t                          SHRI FLOWER SHOP\n");
    fprintf(fptr, "                NEAR KARVENAGAR ROAD, SHOP NO:-420, PIN:-416704\n");
    fprintf(fptr, "                         TAL-HAWELI , DIST:PUNE\n");
    fprintf(fptr, "\t\t\t\t\t\t PHONE:-7499026578 \n");
    fprintf(fptr, "\t\t\t\t\t\t\t ||श्री गणेशाया नमः||\n");
    fprintf(fptr, "\t-----------------------------BILL-----------------------------\n");
    fprintf(fptr, "\tNAME:-ANIRUDDHA TADAVALE          \t\tCUSTOMER NO:-202589552\n");
    fprintf(fptr, "\t--------------------------------------------------------------\n");
    fprintf(fptr, "\tSR.NO\tFLOWER\tQUANTITY\tAMOUNT\n");

    for (int i = 0; i < n; i++) {
        fprintf(fptr, "\t%d\t%s\t\t%d\t\t₹%d\n",
                flowers[i].srNo,
                getFlowerName(flowers[i].type),
                flowers[i].quantity,
                flowers[i].price * flowers[i].quantity);
    }

    fprintf(fptr, "\t--------------------------------------------------------------\n");
    fprintf(fptr, "\t\t\t\t\tTOTAL AMOUNT: ₹%d\n", totalAmount);

    fclose(fptr);

    printf("\nBill successfully generated in 'code.txt'\n");

    return 0;
}
