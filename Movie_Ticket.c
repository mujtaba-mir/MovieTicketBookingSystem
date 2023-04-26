#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie
{
    char code[20];
    char name[20];
    char date[20];
    int cost;
} m;

int seat = 60;


int signup(){
	
    char username[20];
    char password[10];
    char filePath[50] = "./UserData/";
    
        printf("\n==============================================================\n");
        printf("\t			Movie Ticket Booking\n			");
        printf("\n==============================================================\n");
    printf("\nEnter user name: ");
    fflush(stdin);
    gets(username);
    printf("Enter password: ");
    fflush(stdin);
    gets(password);

    strcat(filePath, username);
    strcat(filePath, ".txt");
    if (fopen(filePath, "r") == NULL)
    {
        FILE *fp = fopen(filePath, "w");
        fprintf(fp, password);
        fclose(fp);
        puts("\n******** User created. ********\n");
        return 1;
    }
    else
    {
        puts("\n******** User already exists! Change username. ********\n");
        signup();
    }
}

void view_all();
void book_ticket();
void cancel_ticket();


void view_all()
{

	char movies[20][70] = {"The Shawshank Redemption ------------", "The Godfather ------------", 
	"The Godfather: Part II ------------", "The Dark Knight ------------", "12 Angry Men ------------",
	 "Schindler's List ------------", "The Lord of the Rings: The Return of the King ------------", "Pulp Fiction ------------", 
	 "The Lord of the Rings ------------", "Forrest Gump ------------"};
   
    int duration[10] = {142, 175, 202, 152, 96, 195, 201, 154, 178, 142};

    printf("Movie---------\t\t----------Duration\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t%d\n", movies[i], duration[i]);
    }
	printf("\n\n");
}

void book_ticket()
{
    int seats[10] = {0};
    int option, num_tickets, seat_num[10];

    while (1)
    {
        printf("\n\n1. Book ticket\n2. Go Back\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter number of tickets to book: ");
            scanf("%d", &num_tickets);

            if (num_tickets <= 0 || num_tickets > 10)
            {
                printf("Invalid number of tickets. Please try again.\n");
                break;
            }

            int num_available = 0;
            printf("Available seats: ");
            for (int i = 0; i < 10; i++)
            {
                if (seats[i] == 0)
                {
                    printf("%d,", i + 1);
                    num_available++;
                }
            }

            printf("\nEnter seat number(s): ");
            for (int i = 0; i < num_tickets; i++)
            {
                scanf("%d", &seat_num[i]);

                if (seat_num[i] < 1 || seat_num[i] > 10 || seats[seat_num[i] - 1] == 1)
                {
                    printf("Invalid seat number or seat already booked. Please try again.\n");
                    i--;
                    continue;
                }

                seats[seat_num[i] - 1] = 1;
            }

            printf("\nTicket(s) booked successfully! Seat numbers: ");
            for (int i = 0; i < num_tickets; i++)
            {
                printf("%d ", seat_num[i]);
            }
            
            
            int total_cost = num_tickets * 100;
            printf("\n\n");
				printf("\nYour total is Rs: %d\n", total_cost);
            printf("\n\n");
            
            payment_option();
            break;
        case 2:
            printf("\nExiting...\n");
            return;

        default:
            printf("\nInvalid option. Please try again.\n");
            break;
        }
    }
}

void payment_option() {
    int option;
    
    printf("Choose a payment option:\n");
    printf("1. UPI\n");
    printf("2. Card\n");
    
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("You have chosen UPI payment.\n");
            upi_payment();
            break;
        case 2:
            printf("You have chosen card payment.\n");
            card_payment();
            break;
        default:
            printf("Invalid option. Please choose again.\n");
            payment_option();
            break;
    }
}
void upi_payment() {
    char upi_id[50];
    
    printf(" Enter UPI ID: ");
    scanf("%s", upi_id);
    
    printf("Processing UPI payment for ID: %s\n", upi_id);
    return 0;
}
void card_payment() {
    char card_number[20], expiry_date[10], cvv[5];
    
    printf("Enter your card number: ");
    scanf("%s", card_number);
    
    printf("Enter expiry date (MM/YY): ");
    scanf("%s", expiry_date);
    
    printf("Enter CVV: ");
    scanf("%s", cvv);
    
    printf("Processing card payment for card number: %s\n", card_number);
}

void cancel_ticket()
{
    int seats[10] = {0};
    int option, num_tickets, seat_num[10], cancel_seat_num;
    int total_cost = 0, cancel_cost = 0;
    char seatNumber[20];

    printf("Enter number of tickets to cancel: ");
    scanf("%d", &num_tickets);

    if (num_tickets <= 0 || num_tickets > 10)
    {
        printf("Invalid number of tickets. Please try again.\n");
        return;
    }
    else
    {

        printf("Enter the seats numbers to delete seperated by comas(,): \n");
        scanf("%s", seatNumber);
        printf("Seats canceled succesfully!");
    }
}



int main()
{	
	
	signup();
	
    int ch;
    do
    {
        printf("\n==============================================================\n");
        printf("\t			Movie Ticket Booking\n			");
        printf("\n==============================================================\n");


        printf("\nPress <1> Display Movies");
        printf("\nPress <2> Ticket Booking");
        printf("\nPress <3> Cancel Ticket");
        printf("\nPress <0> Exit");

        printf("\nEnter your Choice :: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            view_all();
            break;
        case 2:
            book_ticket();
            break;
        case 3:
            cancel_ticket();
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong choice!\n");
            break;
        }
    } while (ch != 0);

    return 0;
}
