#include <stdio.h>

#define MONTHS 12 //define amount of months as 12

const char *month_names[] = { //make an array with the month names
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void read_sales(const char *filename, double sales[]) { //define a function to read sales input file
    printf("Attempting to open file: %s\n", filename); //print to let user know we are trying to open file
    FILE *file = fopen(filename, "r"); //open the file
    if (file == NULL) { //if it is null
        printf("Error opening file: %s\n", filename); //tell user there was an error
        for (int i = 0; i < MONTHS; i++) { //if there was an error opening the file, dont accept bad values as that could crash something, just fill in with zeros
            sales[i] = 0.0; //set each array element to 0.0
        }
        return; //return
    }

    printf("File opened successfully. Reading sales data...\n"); //let user know file was opened right

    // Read sales data from the file
     for (int i = 0; i < MONTHS; i++) { //iterate through the amount of months (one line per month)
        fscanf(file, "%lf", &sales[i]); //read the line and put it into the array
    }
    fclose(file); //close the file
    printf("Sales data read successfully.\n"); //let user know it read the sales data fine
}

void print_monthly_sales(const double sales[]) { //define a function to print the monthly sales
    for (int i = 0; i < MONTHS; i++) { //iterate through amount of months
        printf("%s %.2f\n", month_names[i], sales[i]); //print out the month name and sales
    }
}

void print_sales_summary(const double sales[]) { //define function to print out sales summary
    double min = sales[0], max = sales[0], sum = 0; //define doubles for the minimum and maximum as just the first element of array to start with and sum as 0 (double for precision)
    int min_index = 0, max_index = 0; //set integers for the min and max index

    for (int i = 0; i < MONTHS; i++) { //iterate through the amount of months
        sum += sales[i]; //add month i's sales data to the sum
        if (sales[i] < min) { //if this months sales are less than the minimum (the minimum is default the first value of array to start)
            min = sales[i]; //set the minimum to the current months sales data
            min_index = i; //set the index of the minimum to the current one
        }
        if (sales[i] > max) { //if this months sales are more than the maximum (the maximum is default the first value of array to start)
            max = sales[i]; //set the max to the current months data
            max_index = i; //set the max index to current
        }
    }
    
    double average = sum / MONTHS; //calculate the average as a double for precision
    printf("Minimum sales: %.2f (%s)\n", min, month_names[min_index]); //print out the minimum sales with 2 decimal places because it is a currency
    printf("Maximum sales: %.2f (%s)\n", max, month_names[max_index]); //print out the maximum sales with 2 decimal places because it is a currency
    printf("Average sales: %.2f\n", average); //print out the average sales with 2 decimal places because it is a currency
}

void print_moving_average(const double sales[]) { //define function to print the moving average
    for (int i = 0; i <= MONTHS - 6; i++) { //iterate through from 0-6 as 6 month moving average can only be calculated 6 times per year
        double sum = 0; //define the sum as a double initialized to 0
        for (int j = 0; j < 6; j++) { //iterate from  0-5
            sum += sales[i + j]; //add to the sum shifted by i
        }
        printf("%s-%s %.2f\n", month_names[i],month_names[i+5], sum / 6); //print out the month names and the 6 month moving average
    }
}

void print_sales_report(const double sales[]) { //define a function to print out the sales report
    double sorted_sales[MONTHS]; //define an array for the sorted sales
    int indices[MONTHS]; //define an array to hold the indices

    for (int i = 0; i < MONTHS; i++) { //iterate through the amount of months
        sorted_sales[i] = sales[i]; //set sorted sales i to sales i
        indices[i] = i; //mark the indices in our indices array
    }

    for (int i = 0; i < MONTHS - 1; i++) { //iterate through the months -1
        for (int j = 0; j < MONTHS - i - 1; j++) { //iterate through unsorted part of array
            if (sorted_sales[j] < sorted_sales[j + 1]) { //compare current element with next
                double temp = sorted_sales[j]; //store current element in temp
                sorted_sales[j] = sorted_sales[j + 1]; //put next element in current spot
                sorted_sales[j + 1] = temp; //put temp value in next

                int temp_index = indices[j]; //store index temporarily
                indices[j] = indices[j + 1]; //put next index in current spot
                indices[j + 1] = temp_index; //put the temp value in next
            }
        }
    }

    for (int i = 0; i < MONTHS; i++) { //iterate through the amount of months
        printf("%s $%.2f\n", month_names[indices[i]], sorted_sales[i]); //print out the month name and the months sales 
    }
}

int main() { //main function
    double sales[MONTHS]; //define an array sales
    char filename[100]; //define a variable for the filename
    printf("Enter the filename: "); // Prompt the user to enter the filename
    scanf("%99s", filename); // Read the filename not exceeding our character limit
    read_sales(filename, sales); // Read sales figures from the users file
    printf("Sales data:\n"); //print out "header" for sales data
    printf("Monthly Sales Report\n"); //print "header" for the monthly sales report
    print_monthly_sales(sales); //call function
    printf("\nSales Summary Report:\n"); //print "header" for the sales summary report
    print_sales_summary(sales); //call function
    printf("\nSix-Month Moving Average Report:\n"); //print "header" for the 6 month moving average report
    print_moving_average(sales); //call function
    printf("\nSales Report (Highest to Lowest):\n"); //print "header" for the final sales report report
    print_sales_report(sales); //call function

    return 0; //return 0 to end program
}