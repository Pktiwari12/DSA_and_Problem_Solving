import java.util.Scanner;
public class BetterBruteforceGCD {
    public static int gcd(int a , int b){
        int gcd = 1;    // initailize the gcd by q
        // Finding the minumum number of two number
        if(Math.abs(a)>Math.abs(b)){
            gcd = b;
        }
        else{
            gcd = a;
        }
        // Iterate untill we would get a greatest number of divisor
        while(gcd != 0){
            if(a % gcd == 0 && b % gcd == 0){
                break;
            }
            gcd--;
        }
        return gcd;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers :- ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("The gcd of "+a+"and "+b+" is \t"+BetterBruteforceGCD.gcd(a, b));
    }
}
 