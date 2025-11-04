

#include <stdio.h>

#define rows 3
#define cols 3
#define powerbit 0
#define overloadbit 1
#define maintenancebit 2

void updatesector(int grid[rows][cols], int r, int c, int flag, int set);
void querysector(int grid[rows][cols], int r, int c);
void rundiagnostic(int grid[rows][cols]);

int main() {
    int grid[rows][cols] = {0};
    int choice,r,c,flag,set;

    do {
        printf("\n--- IESCO Power Grid Monitoring System ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sector coordinates (row col): ");
                scanf("%d %d", &r, &c);
                printf("Select flag to modify:\n");
                printf("0 - Power\n1 - Overload\n2 - Maintenance\n");
                scanf("%d", &flag);
                printf("Enter 1 to SET or 0 to CLEAR this flag: ");
                scanf("%d", &set);
                updatesector(grid, r, c, flag, set);
                break;

            case 2:
                printf("Enter sector coordinates (row col): ");
                scanf("%d %d", &r, &c);
                querysector(grid, r, c);
                break;

            case 3:
                rundiagnostic(grid);
                break;

            case 4:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void updatesector(int grid[rows][cols], int r, int c, int flag, int set) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        if (set==1){
            grid[r][c] |= (1 << flag);   
        }
        else{
            grid[r][c] &= ~(1 << flag);  
        }
        printf("Sector [%d][%d] updated successfully.\n", r, c);
    } 
    else {
        printf("Invalid coordinates!\n");
    }
}

void querysector(int grid[rows][cols], int r, int c) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        int status = grid[r][c];
        printf("\nSector [%d][%d] Status Report:\n", r, c);
        printf("Power: %s\n", (status & (1 << powerbit)) ? "ON" : "OFF");
        printf("Overload: %s\n", (status & (1 << overloadbit)) ? "YES" : "NO");
        printf("Maintenance: %s\n", (status & (1 << maintenancebit)) ? "REQUIRED" : "NOT REQUIRED");
    } else {
        printf("Invalid coordinates!\n");
    }
}

void rundiagnostic(int grid[rows][cols]) {
    int overloaded = 0, maintenance = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] & (1 << overloadbit))
                overloaded++;
            if (grid[i][j] & (1 << maintenancebit))
                maintenance++;
        }
    }

    printf("\n--- System Diagnostic Report ---\n");
    printf("Total Overloaded Sectors: %d\n", overloaded);
    printf("Total Maintenance Required: %d\n", maintenance);
}