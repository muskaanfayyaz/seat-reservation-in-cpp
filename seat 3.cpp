#include<iostream>
using namespace std;
int checkAvailableSeats(int Seats[][7], int rows , int cols){
    int availableSeats = 0;
    // Iterate over each row
    for (int i = 0; i < rows; i++) {
        // Iterate over each column in the current row
        for (int j = 0; j < cols; j++) {
            // If the seat is available (represented by 0)
            if (Seats[i][j] == 0) {
                // Increment the count of available seats
                availableSeats++;
            }
        }
    }
    // Return the total number of available seats
    return availableSeats;
}
bool bookFirstClass(int Seats[][7], int rows , int cols, int noOfSeats){
     // Check if there are enough available seats in the first class
    if (checkAvailableSeats(Seats, 2, cols) < noOfSeats) {
        return false; // Not enough seats available
    }

    // Find and reserve available seats
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) { // If the seat is available
                Seats[i][j] = 1; // Reserve the seat
                noOfSeats--; // Decrease the number of seats to reserve
                if (noOfSeats == 0) { // If all seats have been reserved
                    return true; // Reservation was successful
                }
            }
        }
    }
    return false; // This line should never be reached
}
bool bookBusinessClass(int Seats[][7], int rows , int cols, int noOfSeats){
    // Check if there are enough available seats in the business class
    if (checkAvailableSeats(Seats, 4, cols) - checkAvailableSeats(Seats, 2, cols) < noOfSeats) {
        return false; // Not enough seats available
    }
    // Find and reserve available seats
    for (int i = 2; i < 4; i++) { // Business class is in rows 2 and 3
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) { // If the seat is available
                Seats[i][j] = 1; // Reserve the seat
                noOfSeats--; // Decrease the number of seats to reserve
                if (noOfSeats == 0) { // If all seats have been reserved
                    return true; // Reservation was successful
                }
            }
        }
    }
    return false; // This line should never be reached
}
bool bookEconomyClass(int Seats[][7], int rows , int cols, int noOfSeats){
    // Check if there are enough available seats in the economy class
    if (checkAvailableSeats(Seats, rows, cols) - checkAvailableSeats(Seats, 4, cols) < noOfSeats) {
        return false; // Not enough seats available
    }

    // Find and reserve available seats
    for (int i = 4; i < rows; i++) { // Economy class is in rows 4 to 11
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) { // If the seat is available
                Seats[i][j] = 1; // Reserve the seat
                noOfSeats--; // Decrease the number of seats to reserve
                if (noOfSeats == 0) { // If all seats have been reserved
                    return true; // Reservation was successful
                }
            }
        }
    }
    return false; // This line should never be reached
}
    void getFare(){
    // Print the fare for each class
    cout << "First class fare is Rs. 18,000\n";
    cout << "Business class fare is Rs. 14,000\n";
    cout << "Economy class fare is Rs. 10,000\n";
}void viewSeatingPlan(int Seats[][7], int rows , int cols){
    // Iterate over each row
    for (int i = 0; i < rows; i++) {
        // Iterate over each column in the current row
        for (int j = 0; j < cols; j++) {
            // Print the status of the seat
            cout << Seats[i][j] << " ";
        }
        // Print a newline character at the end of each row
        cout << "\n";
    }
}
bool systemReset(int Seats[][7], int rows , int cols){
    // Iterate over each row
    for (int i = 0; i < rows; i++) {
        // Iterate over each column in the current row
        for (int j = 0; j < cols; j++) {
            // Set the status of the seat to 0 (available)
            Seats[i][j] = 0;
        }
    }
    // Return true to indicate that the operation was successful
    return true;
}
int main ()
{
	int Seats[12][7] = {0}; 
    int choice;int cols = 7; // Initialize the number of columns
    int noOfSeats, rows = 12; // Initialize the number of rows

    cout<<"-----------------------------------------------------"<<"\n"
           <<"Welcome to Airplane Reservation System \n"
           <<"----------------------------------------------------- \n"
           <<"1. Book First Class Seats\n"
           <<"2. Book Business Class Seats\n"
           <<"3. Book Economy Class Seats\n"
           <<"4. View Airplane Seating Plan\n"
           <<"5. View Fare(s)\n"
           <<"6. System Reset\n"
           <<"7. Exit from The Booking System\n";
           // Take input for the number of seats
          cout << "Enter the number of seats: ";
                cin >> noOfSeats;
    do{
           
      cout << "Enter your choice: ";
      cin >> choice;
	  switch(choice) {
            case 1:
                // Call  for bookFirstClass function
             cout<<(bookFirstClass(Seats, 2, cols, noOfSeats)) <<endl;
        if ((bookFirstClass(Seats, 2, cols, noOfSeats))==1){
            cout<<"booked successfully"<<endl;
        } 
        else
        cout<<"failed to book"<<endl;
        break;
            case 2:
                // Call for bookBusinessClass function 
				cout<< (bookBusinessClass(Seats, 4, cols, noOfSeats))<<endl; 
           	if((bookBusinessClass(Seats, 4, cols, noOfSeats))==1) {
           		 cout<<"booked successfully"<<endl;
            }
            else
            cout<<"failed to book"<<endl;
                break;
            case 3:
                // Call for bookEconomyClass function
                cout<<(bookEconomyClass(Seats, 8, cols, noOfSeats)) <<endl;
              if ((bookEconomyClass(Seats, 8, cols, noOfSeats))==1)   
			  {
           		 cout<<"booked successfully"<<endl;
            }
            else
            cout<<"failed to book"<<endl;
			  break;
            case 4:
                // Call for viewSeatingPlan function
                viewSeatingPlan(Seats, rows, cols);
                break;
            case 5:
                // Call for getFare function
                getFare();
                break;
            case 6:
                // Call for systemReset function(systemReset
                cout<<(systemReset(Seats, rows, cols)) <<endl;
				if ((systemReset(Seats, rows, cols)) ==1) 
			  {
           		 cout<<"booked successfully"<<endl;
            }
                else
            cout<<"failed to book"<<endl;
                break;
            case 7:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        
    }
}
	while(choice != 7);
	return 0;
	  }
