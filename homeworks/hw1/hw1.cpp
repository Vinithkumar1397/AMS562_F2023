#include <iostream>
#include <string>
#include <limits> 

int main() {
    // Variables to store user input
    std::string title, firstName, lastName, dob, bio;

    // Ask the user for their title
    std::cout << "Enter your title: ";
    std::cin >> title;

    // Ask the user for their first name and last name
    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    // Ask the user for their date of birth
    std::cout << "Enter your date of birth (format: month/day/year): ";
    std::cin >> dob;

    // Consume the newline character left in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ask the user for their brief bio using getline
    std::cout << "Enter a brief bio: ";
    std::getline(std::cin, bio);

    // Print the user's information in the specified format
    std::cout << "<" << title << "> " << firstName << " " << lastName << std::endl;
    std::cout << "\tDOB: " << dob << std::endl;
    std::cout << "\tBio: " << bio << std::endl;

    return 0;
}

