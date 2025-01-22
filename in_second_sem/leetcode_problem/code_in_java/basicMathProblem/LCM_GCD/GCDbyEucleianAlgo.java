// Finding the GCD Using the Eucledian algorithm

import java.util.Scanner;

public class GCDbyEucleianAlgo{
    public static int gcd(int a , int b){
        int gcd = 1;
        while (!((a == 0 && b !=0) || (b == 0 && a !=0))  ) {
            if(a>b){
                a = Math.abs(a) - Math.abs(b);
            }
            else{
                b = Math.abs(b) - Math.abs(a);
            }
        }
        if(a == 0){
            gcd = b;
        }
        else{
            gcd = a;
        }
        return gcd;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers :- ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("The gcd of "+a+"and "+b+" is \t"+GCDbyEucleianAlgo.gcd(a, b));

    }
 }