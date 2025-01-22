import java.util.Scanner;

public class BruteforceLCM {
    public static int lcm(int a , int b){
        if(a <= 0 || b <= 0){
            System.out.println("please enter positive integer ");
            return 0;
        }
        int lcm;
        if(a > b){
            lcm = a;

        }
        else{
            lcm = b;
        }
        while(true){
            if(lcm % a == 0 && lcm % b == 0){
                break;
            }
            lcm++;
        }
        return lcm;

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any two positive number :-");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("The LCM of "+a+" "+b+" is \t"+BruteforceLCM.lcm(a, b));
    }
}
