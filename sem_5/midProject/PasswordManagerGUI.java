import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.security.SecureRandom;
import java.util.Base64;

public class PasswordManagerGUI extends JFrame {
    private static SecretKey secretKey;
    private static final String FILE_NAME = "passwords.txt";
    private String masterPassword;

    private JTextField websiteField;
    private JPasswordField passwordField;
    private JPasswordField masterPasswordField;
    private JTextArea resultArea;

    public PasswordManagerGUI() {
        // Initialize encryption key
        try {
            KeyGenerator keyGen = KeyGenerator.getInstance("AES");
            keyGen.init(128);
            secretKey = keyGen.generateKey();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Error initializing encryption: " + e.getMessage(),
                                         "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        // Set up master password dialog
        masterPassword = JOptionPane.showInputDialog(this, "Set your master password:");
        if (masterPassword == null || masterPassword.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Master password is required!",
                                         "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        // Set up main window
        setTitle("Password Manager");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Create panels
        JPanel mainPanel = new JPanel(new BorderLayout(10, 10));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Input panel
        JPanel inputPanel = new JPanel(new GridLayout(3, 2, 5, 5));
        inputPanel.setBorder(BorderFactory.createTitledBorder("Password Details"));

        inputPanel.add(new JLabel("Website:"));
        websiteField = new JTextField(20);
        inputPanel.add(websiteField);

        inputPanel.add(new JLabel("Password:"));
        passwordField = new JPasswordField(20);
        inputPanel.add(passwordField);

        inputPanel.add(new JLabel("Master Password:"));
        masterPasswordField = new JPasswordField(20);
        inputPanel.add(masterPasswordField);

        // Button panel
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));

        JButton saveButton = new JButton("Save Password");
        JButton retrieveButton = new JButton("Retrieve Password");
        JButton otpButton = new JButton("Generate OTP");

        buttonPanel.add(saveButton);
        buttonPanel.add(retrieveButton);
        buttonPanel.add(otpButton);

        // Result area
        resultArea = new JTextArea(10, 40);
        resultArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(resultArea);

        // Add components to main panel
        mainPanel.add(inputPanel, BorderLayout.NORTH);
        mainPanel.add(buttonPanel, BorderLayout.CENTER);
        mainPanel.add(scrollPane, BorderLayout.SOUTH);

        // Add main panel to frame
        add(mainPanel);

        // Add action listeners to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                savePassword();
            }
        });

        retrieveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                retrievePassword();
            }
        });

        otpButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                generateOTP();
            }
        });
    }

    private void savePassword() {
        String website = websiteField.getText().trim();
        String password = new String(passwordField.getPassword());

        if (website.isEmpty() || password.isEmpty()) {
            resultArea.setText("Website and password cannot be empty!");
            return;
        }

        try {
            // Encrypt password
            Cipher cipher = Cipher.getInstance("AES");
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);
            byte[] encryptedBytes = cipher.doFinal(password.getBytes());
            String encodedPassword = Base64.getEncoder().encodeToString(encryptedBytes);

            // Save to file
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true))) {
                writer.write(website + ":" + encodedPassword);
                writer.newLine();
            }

            resultArea.setText("Password saved successfully for: " + website);
            websiteField.setText("");
            passwordField.setText("");

        } catch (Exception e) {
            resultArea.setText("Error saving password: " + e.getMessage());
        }
    }

    private void retrievePassword() {
        String website = websiteField.getText().trim();
        String inputMaster = new String(masterPasswordField.getPassword());

        if (website.isEmpty()) {
            resultArea.setText("Please enter a website to retrieve password!");
            return;
        }

        if (!inputMaster.equals(masterPassword)) {
            resultArea.setText("Incorrect master password!");
            return;
        }

        try {
            String encryptedPassword = null;

            // Read from file
            try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] parts = line.split(":");
                    if (parts.length == 2 && parts[0].equals(website)) {
                        encryptedPassword = parts[1];
                        break;
                    }
                }
            }

            if (encryptedPassword != null) {
                // Decrypt password
                Cipher cipher = Cipher.getInstance("AES");
                cipher.init(Cipher.DECRYPT_MODE, secretKey);
                byte[] decryptedBytes = cipher.doFinal(Base64.getDecoder().decode(encryptedPassword));
                String decryptedPassword = new String(decryptedBytes);

                resultArea.setText("Retrieved password for " + website + ":\n" + decryptedPassword);
            } else {
                resultArea.setText("No password found for: " + website);
            }

        } catch (Exception e) {
            resultArea.setText("Error retrieving password: " + e.getMessage());
        }
    }

    private void generateOTP() {
        SecureRandom random = new SecureRandom();
        int otp = 100000 + random.nextInt(900000);
        resultArea.setText("Generated OTP: " + otp);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new PasswordManagerGUI().setVisible(true);
            }
        });
    }
}