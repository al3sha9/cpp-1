import java.utils.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ATM first = new ATM(9999);

        while (true) {
            System.out.println("\n--- ATM Menu ---");
            System.out.println("1. Check Balance");
            System.out.println("2. Deposit Money");
            System.out.println("3. Withdraw Money");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            if (choice == 1) {
                myATM.checkBalance();
            } else if (choice == 2) {
                System.out.print("Enter amount to deposit: ");
                double amount = sc.nextDouble();
                myATM.deposit(amount);
            } else if (choice == 3) {
                System.out.print("Enter amount to withdraw: ");
                double amount = sc.nextDouble();
                myATM.withdraw(amount);
            } else if (choice == 4) {
                System.out.println("Thank you for using the ATM.");
                break;
            } else {
                System.out.println("Invalid choice. Try again.");
            }
        }

        sc.close();
    }
}
