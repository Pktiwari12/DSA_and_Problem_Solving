import java.util.Scanner;

public class ModulousWorkOnNegative {
    public static void main(String [] args){
        System.out.println("Enter any two numbers :-");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("The reminder :-\t"+a%b);
        System.out.println("The quotiant :-\t"+a/b);
    }
    
}
