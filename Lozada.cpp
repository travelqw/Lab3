#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <conio.h>

void setFilePermissions(const char* filename, mode_t mode) {
    if (chmod(filename, mode) != 0) {  
        perror("Error setting file permissions");
    } else {
        std::cout << "Permissions updated successfully for file: " << filename << std::endl;
    }
}

int main() {
    char filename[50];  
    int choice;

    while (true) {
        std::cout << "\t\tMAIN MENU OF PERMISSION\n";
        std::cout << "\t----------------------------------\n";  
        std::cout << "1. Only Read\n";  
        std::cout << "2. Only Write\n"; 
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter the file name: ";
                std::cin >> filename;
                setFilePermissions(filename, S_IRUSR);  
                break;

            case 2:
                std::cout << "Enter the file name: ";
                std::cin >> filename;
                setFilePermissions(filename, S_IWUSR);  
                break;

            case 3:
                exit(0); 
                break;

            default:
                std::cout << "Invalid choice." << std::endl;  
        }

        std::cout << "Press any key to continue...\n";
        getch(); 
        std::cout << "\n";
    }

    return 0;
}
