import java.util.Scanner;

public class E_1_3_4_1_1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        double num = sc.nextDouble();

        System.out.println(((int)(num * 1000)) / 1000);

        sc.close();
    }
}