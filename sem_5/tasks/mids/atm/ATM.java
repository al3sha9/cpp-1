import java.utils.Scanner;

public class ATM{
    double balance;

    ATM(double ini){
        this.balance = ini;
    }

    void checkBalance(){
        System.out.println("Your current balance is: $" + balance);
    }

    void deposit(double amount){
        if(amount==0){
            System.out.println("Cant add 0")
        }
        balance += amount;
        System.out.println("new balance is :" + balance);
    }

    void withdraw(double amount){
        if(amount>balance){
            System.out.println("You exeded");
        }
        if(balance == 0){
            System.out.println("Not enough balance");
        }
        balance -= amount;
        System.out.println("new balance is :" + balance);

    }
}
