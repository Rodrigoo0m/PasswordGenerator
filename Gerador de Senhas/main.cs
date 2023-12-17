using System;

public class PasswordGenerator {
    private static Random random = new Random();

    public static string GenerateRandomPassword(int length, bool useLetters, bool useNumbers, bool useSymbols) {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string numbers = "0123456789";
        string symbols = "!@#$%^&*()_+";
        string allowedChars = "";

        if (useLetters) allowedChars += letters;
        if (useNumbers) allowedChars += numbers;
        if (useSymbols) allowedChars += symbols;

        char[] password = new char[length];
        for (int i = 0; i < length; i++) {
            password[i] = allowedChars[random.Next(allowedChars.Length)];
        }

        return new String(password);
    }

    public static void Main(string[] args) {
        Console.Write("Digite o comprimento da senha: ");
        int length = Int32.Parse(Console.ReadLine());
        Console.Write("Usar letras? (Verdadeiro/Falso): ");
        bool useLetters = Boolean.Parse(Console.ReadLine());
        Console.Write("Usar números? (Verdadeiro/Falso): ");
        bool useNumbers = Boolean.Parse(Console.ReadLine());
        Console.Write("Usar símbolos? (Verdadeiro/Falso): ");
        bool useSymbols = Boolean.Parse(Console.ReadLine());

        string password = GenerateRandomPassword(length, useLetters, useNumbers, useSymbols);
        Console.WriteLine($"Senha Gerada: {password}");
    }
}
