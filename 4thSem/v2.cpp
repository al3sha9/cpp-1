#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

using namespace std;

void showMenu() {
    cout << "\nLinux Command Helper with Pipes\n";
    cout << "1. List contents of the folder (ls)\n";
    cout << "2. Search for a term in listed files (ls | grep)\n";
    cout << "3. Show processes and filter by name (ps aux | grep)\n";
    cout << "4. Check if internet is working (ping google.com)\n";
    cout << "5. Show current directory (pwd)\n";
    cout << "6. Show disk usage (df -h)\n";
    cout << "7. Show free memory (free -h)\n";
    cout << "8. Show system uptime (uptime)\n";
    cout << "9. Show network configuration (ifconfig)\n";
    cout << "10. Show file permissions in the current directory (ls -l)\n";
    cout << "11. Count number of lines in a file (wc -l <filename>)\n";
    cout << "12. Display file contents (cat <filename>)\n";
    cout << "13. Search for a pattern in a file (grep <pattern> <filename>)\n";
    cout << "14. List mounted file systems (mount | grep)\n";
    cout << "15. Display last system reboot (last reboot)\n";
    cout << "16. Show active internet connections (netstat)\n";
    cout << "17. List open files (lsof)\n";
    cout << "18. Display system hostname (hostname)\n";
    cout << "19. Show logged-in users (who)\n";
    cout << "20. Exit\n";
    cout << "Choose an option: ";
}

void executeCommand(const char* command, char* const args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        cerr << "Failed to fork process" << endl;
        exit(1);
    } else if (pid == 0) {
        execvp(command, args);
        cerr << "Failed to execute command" << endl;
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

void executeWithPipeManualIO(const char* command1, char* const args1[], const char* command2, char* const args2[]) {
    int pipefd[2];
    pipe(pipefd);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execvp(command1, args1);
        cerr << "Failed to execute command1" << endl;
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(pipefd[1]);
        char buffer[1024];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytesRead] = '\0';
            if (strstr(buffer, args2[1]) != nullptr) {
                write(STDOUT_FILENO, buffer, bytesRead);
            }
        }
        close(pipefd[0]);
        exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, nullptr, 0);
    waitpid(pid2, nullptr, 0);
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                char* args[] = {(char*)"ls", nullptr};
                executeCommand("ls", args);
                break;
            }
            case 2: {
                string term;
                cout << "Enter term to search in listed files: ";
                getline(cin, term);
                char* args1[] = {(char*)"ls", nullptr};
                char* args2[] = {(char*)"grep", (char*)term.c_str(), nullptr};
                executeWithPipeManualIO("ls", args1, "grep", args2);
                break;
            }
            case 3: {
                string processName;
                cout << "Enter process name to filter: ";
                getline(cin, processName);
                char* args1[] = {(char*)"ps", (char*)"aux", nullptr};
                char* args2[] = {(char*)"grep", (char*)processName.c_str(), nullptr};
                executeWithPipeManualIO("ps", args1, "grep", args2);
                break;
            }
            case 4: {
                char* args[] = {(char*)"ping", (char*)"-c", (char*)"4", (char*)"google.com", nullptr};
                executeCommand("ping", args);
                break;
            }
            case 5: {
                char* args[] = {(char*)"pwd", nullptr};
                executeCommand("pwd", args);
                break;
            }
            case 6: {
                char* args[] = {(char*)"df", (char*)"-h", nullptr};
                executeCommand("df", args);
                break;
            }
            case 7: {
                char* args[] = {(char*)"free", (char*)"-h", nullptr};
                executeCommand("free", args);
                break;
            }
            case 8: {
                char* args[] = {(char*)"uptime", nullptr};
                executeCommand("uptime", args);
                break;
            }
            case 9: {
                char* args[] = {(char*)"ifconfig", nullptr};
                executeCommand("ifconfig", args);
                break;
            }
            case 10: {
                char* args[] = {(char*)"ls", (char*)"-l", nullptr};
                executeCommand("ls", args);
                break;
            }
            case 11: {
                string filename;
                cout << "Enter filename: ";
                getline(cin, filename);
                char* args[] = {(char*)"wc", (char*)"-l", (char*)filename.c_str(), nullptr};
                executeCommand("wc", args);
                break;
            }
            case 12: {
                string filename;
                cout << "Enter filename: ";
                getline(cin, filename);
                char* args[] = {(char*)"cat", (char*)filename.c_str(), nullptr};
                executeCommand("cat", args);
                break;
            }
            case 13: {
                string term, filename;
                cout << "Enter pattern to search: ";
                getline(cin, term);
                cout << "Enter filename: ";
                getline(cin, filename);
                char* args[] = {(char*)"grep", (char*)term.c_str(), (char*)filename.c_str(), nullptr};
                executeCommand("grep", args);
                break;
            }
            case 14: {
                char* args[] = {(char*)"mount", nullptr};
                executeWithPipeManualIO("mount", args, "grep", args);
                break;
            }
            case 15: {
                char* args[] = {(char*)"last", (char*)"reboot", nullptr};
                executeCommand("last", args);
                break;
            }
            case 16: {
                char* args[] = {(char*)"netstat", nullptr};
                executeCommand("netstat", args);
                break;
            }
            case 17: {
                char* args[] = {(char*)"lsof", nullptr};
                executeCommand("lsof", args);
                break;
            }
            case 18: {
                char* args[] = {(char*)"hostname", nullptr};
                executeCommand("hostname", args);
                break;
            }
            case 19: {
                char* args[] = {(char*)"who", nullptr};
                executeCommand("who", args);
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
