#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void showMenu() {
    cout << "\nLinux Command Helper\n";
    cout << "1. List contents of the folder (ls)\n";
    cout << "2. Check if internet is working (ping google.com)\n";
    cout << "3. Show current directory (pwd)\n";
    cout << "4. Show disk usage (df -h)\n";
    cout << "5. Show memory usage (free -h)\n";
    cout << "6. View running processes (top)\n";
    cout << "7. Show current date and time (date)\n";
    cout << "8. Display network configuration (ifconfig or ip a)\n";
    cout << "9. Search for a file (find)\n";
    cout << "10. Display file content (cat)\n";
    cout << "11. Create a directory (mkdir)\n";
    cout << "12. Remove a file (rm)\n";
    cout << "13. Copy a file (cp)\n";
    cout << "14. Move or rename a file (mv)\n";
    cout << "15. Display last few lines of a file (tail)\n";
    cout << "16. Display first few lines of a file (head)\n";
    cout << "17. Show command history (history)\n";
    cout << "18. Edit a file with nano (nano)\n";
    cout << "19. List all installed packages (depending on distro)\n";
    cout << "20. Exit\n";
    cout << "Choose an option: ";
}

void executeCommand(const char* command, char* const args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        cerr << "Failed to fork process" << endl;
        exit(1);
    } else if (pid == 0) {
        // In child process
        execvp(command, args);
        cerr << "Failed to execute command" << endl;
        exit(1);
    } else {
        // In parent process, wait for child to complete
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                char* args[] = {(char*)"ls", (char*)"-l", nullptr};
                executeCommand("ls", args);
                break;
            }
            case 2: {
                char* args[] = {(char*)"ping", (char*)"-c", (char*)"4", (char*)"google.com", nullptr};
                executeCommand("ping", args);
                break;
            }
            case 3: {
                char* args[] = {(char*)"pwd", nullptr};
                executeCommand("pwd", args);
                break;
            }
            case 4: {
                char* args[] = {(char*)"df", (char*)"-h", nullptr};
                executeCommand("df", args);
                break;
            }
            case 5: {
                char* args[] = {(char*)"free", (char*)"-h", nullptr};
                executeCommand("free", args);
                break;
            }
            case 6: {
                char* args[] = {(char*)"top", nullptr};
                executeCommand("top", args);
                break;
            }
            case 7: {
                char* args[] = {(char*)"date", nullptr};
                executeCommand("date", args);
                break;
            }
            case 8: {
                char* args[] = {(char*)"ifconfig", nullptr}; // Alternatively, use "ip", "a" if ip is preferred
                executeCommand("ifconfig", args);
                break;
            }
            case 9: {
                char filename[256];
                cout << "Enter filename to search: ";
                cin >> filename;
                char* args[] = {(char*)"find", (char*)".", (char*)"-name", filename, nullptr};
                executeCommand("find", args);
                break;
            }
            case 10: {
                char filename[256];
                cout << "Enter filename to display: ";
                cin >> filename;
                char* args[] = {(char*)"cat", filename, nullptr};
                executeCommand("cat", args);
                break;
            }
            case 11: {
                char dirname[256];
                cout << "Enter directory name to create: ";
                cin >> dirname;
                char* args[] = {(char*)"mkdir", dirname, nullptr};
                executeCommand("mkdir", args);
                break;
            }
            case 12: {
                char filename[256];
                cout << "Enter filename to remove: ";
                cin >> filename;
                char* args[] = {(char*)"rm", filename, nullptr};
                executeCommand("rm", args);
                break;
            }
            case 13: {
                char src[256], dest[256];
                cout << "Enter source file to copy: ";
                cin >> src;
                cout << "Enter destination: ";
                cin >> dest;
                char* args[] = {(char*)"cp", src, dest, nullptr};
                executeCommand("cp", args);
                break;
            }
            case 14: {
                char src[256], dest[256];
                cout << "Enter source file to move/rename: ";
                cin >> src;
                cout << "Enter destination: ";
                cin >> dest;
                char* args[] = {(char*)"mv", src, dest, nullptr};
                executeCommand("mv", args);
                break;
            }
            case 15: {
                char filename[256];
                cout << "Enter filename to show last few lines: ";
                cin >> filename;
                char* args[] = {(char*)"tail", filename, nullptr};
                executeCommand("tail", args);
                break;
            }
            case 16: {
                char filename[256];
                cout << "Enter filename to show first few lines: ";
                cin >> filename;
                char* args[] = {(char*)"head", filename, nullptr};
                executeCommand("head", args);
                break;
            }
            case 17: {
                char* args[] = {(char*)"history", nullptr};
                executeCommand("history", args);
                break;
            }
            case 18: {
                char filename[256];
                cout << "Enter filename to edit with nano: ";
                cin >> filename;
                char* args[] = {(char*)"nano", filename, nullptr};
                executeCommand("nano", args);
                break;
            }
            case 19: {
                char* args[] = {(char*)"dpkg", (char*)"--list", nullptr}; // Use apt or other manager as per the distro
                executeCommand("dpkg", args);
                break;
            }
            case 20:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}
