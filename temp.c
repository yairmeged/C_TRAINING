#include <stdio.h>
#include <stdbool.h>

double getValidDoubleInput();
bool emptyStdin ();



int main() {
    double num = getValidDoubleInput("hii enter double 1\n");
    
    printf("the num is : %lf", num);
    return 0;
}

// gets "   454" but not "455   "
// not dealing big num
double getValidDoubleInput (char* enterDoubleMess) {
    bool validInput = false;
    double userInput;
    int scanfResult;

    do{
        printf("%15s", enterDoubleMess);
        scanfResult = scanf("%lf", &userInput);
        printf("scanfResult : %d \n", scanfResult);
        printf("sizeof  : %d \n", sizeof(userInput));
        
        bool isEmpty = emptyStdin();
        printf("isEmpty : %d \n", isEmpty);

        if (scanfResult == 1 && isEmpty == true) {
            validInput = true;
        }
        else {
            printf("invalid input \n");
        }
        
    } while (validInput == false);

    return userInput;
}



bool emptyStdin () {

    int c;
    int count = 0;
    // while((c = getchar()) != '\n' && c != EOF );

    do{
        c = getchar();
        count++;
    } while(c != '\n' && c != EOF);

    printf("count = %d \n",count);

    return count == 1? true : false;
}




// #include <stdio.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <string.h>

// int main() {
//     char *endptr;
//     double value;

//     // Trying to convert a string to double
//     value = strtod("1.7976931348623157e+308", &endptr); // A very large number

//     // Check if conversion was successful
//     if (endptr == "1.7976931348623157e+308" || *endptr != '\0') {
//         printf("Conversion failed: %s\n", strerror(errno));
//     } else if (errno == ERANGE) {
//         printf("Overflow occurred: value is out of range.\n");
//     } else {
//         printf("Converted value: %lf\n", value);
//     }

//     return 0;
// }