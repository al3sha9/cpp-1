#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <semaphore.h>
#include <vector>
#include <algorithm>
using namespace std;

sem_t sem;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

void showMenu() {
    cout << "\n\n_____________________________" << endl;
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

    cout<<"\n\n Algorithm Showcase\n";
    cout << "\t10. Banker's Algorithm\n";
    cout << "\t11. Shortest Job First (SJF) Scheduling\n";
    cout << "\t12. First Come First Serve (FCFS) Scheduling\n";
    cout << "\t13. Thread Example\n";
    cout << "\t14. Semaphore Example\n";
    cout << "\t15. Exit\n";
    cout << "_____________________________" << endl;
    cout << "\nChoose an option: ";
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

void* threadFunction(void* arg) {
    cout << "Thread ID: " << pthread_self() << " is running." << endl;
    pthread_exit(nullptr);
}

void* semaphoreFunction(void* arg) {
    sem_wait(&sem);
    cout << "Entering Critical Section (Thread ID: " << pthread_self() << ")\n";
    sleep(1);
    cout << "Leaving Critical Section (Thread ID: " << pthread_self() << ")\n";
    sem_post(&sem);
    pthread_exit(nullptr);
}

void sjf(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.burst < b.burst;
    });
    int time = 0;
    for (auto& p : processes) {
        p.waiting = time - p.arrival;
        time += p.burst;
        p.turnaround = time - p.arrival;
    }
    cout << "SJF Scheduling Results:\n";
    for (auto& p : processes) {
        cout << "Process " << p.id << ": Waiting Time: " << p.waiting << ", Turnaround Time: " << p.turnaround << endl;
    }
}

void fcfs(vector<Process>& processes) {
    int time = 0;
    for (auto& p : processes) {
        p.waiting = time - p.arrival;
        time += p.burst;
        p.turnaround = time - p.arrival;
    }
    cout << "FCFS Scheduling Results:\n";
    for (auto& p : processes) {
        cout << "Process " << p.id << ": Waiting Time: " << p.waiting << ", Turnaround Time: " << p.turnaround << endl;
    }
}

const int P = 5;
const int R = 3;

void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R]) {
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}

bool isSafe(int processes[], int avail[], int maxm[][R], int allot[][R]) {
    int need[P][R];
    calculateNeed(need, maxm, allot);
    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == R) {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false) {
            cout << "System is not in safe state";
            return false;
        }
    }
    cout << "System is in safe state.\nSafe sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << safeSeq[i] << " ";
    return true;
}

void bankersAlgorithm() {
 int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {3, 3, 2};
    int maxm[][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allot[][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    isSafe(processes, avail, maxm, allot);
}

int main() {
    int choice;
    sem_init(&sem, 0, 1);

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
                bankersAlgorithm();
                break;
            }
            case 11: {
                int n;
                cout << "Enter number of processes: ";
                cin >> n;
                vector<Process> processes(n);
                for (int i = 0; i < n; ++i) {
                    processes[i].id = i + 1;
                    cout << "Enter burst time for process " << i + 1 << ": ";
                    cin >> processes[i].burst;
                    processes[i].arrival = i * 2;
                }
                sjf(processes);
                break;
            }
            case 12: {
                int n;
                cout << "Enter number of processes: ";
                cin >> n;
                vector<Process> processes(n);
                for (int i = 0; i < n; ++i) {
                    processes[i].id = i + 1;
                    cout << "Enter burst time for process " << i + 1 << ": ";
                    cin >> processes[i].burst;
                    processes[i].arrival = i * 2;
                }
                fcfs(processes);
                break;
            }
            case 13: {
                pthread_t thread;
                pthread_create(&thread, nullptr, threadFunction, nullptr);
                pthread_join(thread, nullptr);
                break;
            }
            case 14: {
                pthread_t threads[3];
                for (int i = 0; i < 3; ++i) {
                    pthread_create(&threads[i], nullptr, semaphoreFunction, nullptr);
                }
                for (int i = 0; i < 3; ++i) {
                    pthread_join(threads[i], nullptr);
                }
                break;
            }
            case 15:
                cout << "Exiting...\n";
                sem_destroy(&sem);
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}

