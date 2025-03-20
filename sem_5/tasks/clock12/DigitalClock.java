import java.util.Scanner;

public class DigitalClock {
    private int currentHours;
    private int currentMinutes;
    private int currentSeconds;
    private String period; // AM or PM

    public DigitalClock() {
        initializeClock();
    }

    public void advanceTime() {
        currentSeconds++;
        if (currentSeconds == 60) {
            currentSeconds = 0;
            currentMinutes++;
            if (currentMinutes == 60) {
                currentMinutes = 0;
                currentHours++;
                if (currentHours == 12) {
                    currentHours = 0;
                    period = (period.equals("AM")) ? "PM" : "AM";
                }
            }
        }
    }

    public void adjustTime(int newHours, int newMinutes, int newSeconds, String newPeriod) {
        if (newHours >= 1 && newHours <= 12 && newMinutes >= 0 && newMinutes < 60 && newSeconds >= 0 && newSeconds < 60) {
            currentHours = newHours % 12;
            if (currentHours == 0) {
                currentHours = 12;
            }
            currentMinutes = newMinutes;
            currentSeconds = newSeconds;
            period = newPeriod;
        } else {
            System.out.println("Invalid time input.");
        }
    }

    public void initializeClock() {
        currentHours = 12;
        currentMinutes = 0;
        currentSeconds = 0;
        period = "AM";
    }

    public void showTime() {
        System.out.printf("Current Time: %02d:%02d:%02d %s%n", currentHours, currentMinutes, currentSeconds, period);
    }

    public static void main(String[] args) {
        DigitalClock clock = new DigitalClock();
        Scanner inputScanner = new Scanner(System.in);
        int userChoice;

        do {
            System.out.println("Menu:");
            System.out.println("1. Advance Time");
            System.out.println("2. Adjust Time");
            System.out.println("3. Initialize Clock");
            System.out.println("4. Show Time");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            userChoice = inputScanner.nextInt();

            switch (userChoice) {
                case 1:
                    clock.advanceTime();
                    break;
                case 2:
                    System.out.print("Enter hours (1-12): ");
                    int newHours = inputScanner.nextInt();
                    System.out.print("Enter minutes (0-59): ");
                    int newMinutes = inputScanner.nextInt();
                    System.out.print("Enter seconds (0-59): ");
                    int newSeconds = inputScanner.nextInt();
                    System.out.print("Enter period (AM/PM): ");
                    String newPeriod = inputScanner.next();
                    clock.adjustTime(newHours, newMinutes, newSeconds, newPeriod);
                    break;
                case 3:
                    clock.initializeClock();
                    System.out.println("Clock initialized to 12:00:00 AM.");
                    break;
                case 4:
                    clock.showTime();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (userChoice != 5);

        inputScanner.close();
    }
}
