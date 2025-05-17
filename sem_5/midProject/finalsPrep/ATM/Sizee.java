import java.util.Scanner;

public class Sizee {

    double money;

    Sizee(double money) {
        this.money = money;
    }

    void checkBalance() {
        System.out.println("Your current balance is" + money);
    }

    void deposit(double cash) {
        if (cash < 0) {
            System.out.println("Bro you entered false cash");
        }
        money += cash;
    }
}
