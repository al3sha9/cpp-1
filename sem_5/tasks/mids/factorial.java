import java.util.Scanner;

public class factorial {

    public static void main(String[] args) {
        int i;
        int fact = 1;
        int userNumber;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a Number");
        userNumber = input.nextInt();
        for (i = 1; i <= userNumber; i++) {
            fact = fact * i;
        }
        System.out.println("Factorial of the given number is " + fact);
    }
}
