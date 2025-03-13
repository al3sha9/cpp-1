import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.io.*;
import java.security.SecureRandom;
import java.util.Base64;
import java.util.Scanner;

public class SimplePasswordManager {
    private static SecretKey secretKey;
    private static final String FILE_NAME = "passwords.txt";

    public static void main(String[] args) {
        try {
            // Generate encryption key
            KeyGenerator keyGen = KeyGenerator.getInstance("AES");
            keyGen.init(128);
            secretKey = keyGen.generateKey();

            Scanner scanner = new Scanner(System.in);
            System.out.print("Set your master password: ");
            String masterPassword = scanner.nextLine();

            while (true) {
                System.out.println("\n1. Save password\n2. Retrieve password\n3. Generate OTP\n4. Exit");
                System.out.print("Choose an option: ");
                int choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                switch (choice) {
                    case 1:
                        // Save password
                        System.out.print("Website: ");
                        String website = scanner.nextLine();
                        System.out.print("Password: ");

                        // Encrypt and save password
                        Cipher encryptCipher = Cipher.getInstance("AES");
                        encryptCipher.init(Cipher.ENCRYPT_MODE, secretKey);
                        byte[] encryptedBytes = encryptCipher.doFinal(scanner.nextLine().getBytes());
                        String encoded = Base64.getEncoder().encodeToString(encryptedBytes);

                        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true))) {
                            writer.write(website + ":" + encoded);
                            writer.newLine();
                        }
                        System.out.println("Password saved!");
                        break;

                    case 2:
                        // Retrieve password
                        System.out.print("Website: ");
                        String site = scanner.nextLine();
                        String storedPassword = null;

                        // Search for password in file
                        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
                            String line;
                            while ((line = reader.readLine()) != null) {
                                String[] parts = line.split(":");
                                if (parts.length == 2 && parts[0].equals(site)) {
                                    storedPassword = parts[1];
                                    break;
                                }
                            }
                        }

                        if (storedPassword != null) {
                            System.out.print("Master password: ");
                            if (scanner.nextLine().equals(masterPassword)) {
                                // Decrypt password
                                Cipher decryptCipher = Cipher.getInstance("AES");
                                decryptCipher.init(Cipher.DECRYPT_MODE, secretKey);
                                byte[] decryptedBytes = decryptCipher.doFinal(Base64.getDecoder().decode(storedPassword));
                                System.out.println("Password: " + new String(decryptedBytes));
                            } else {
                                System.out.println("Wrong master password!");
                            }
                        } else {
                            System.out.println("No password found.");
                        }
                        break;

                    case 3:
                        // Generate 6-digit OTP
                        int otp = 100000 + new SecureRandom().nextInt(900000);
                        System.out.println("Generated OTP: " + otp);
                        break;

                    case 4:
                        System.out.println("Exiting...");
                        scanner.close();
                        return;

                    default:
                        System.out.println("Invalid choice. Try again.");
                }
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
// working one