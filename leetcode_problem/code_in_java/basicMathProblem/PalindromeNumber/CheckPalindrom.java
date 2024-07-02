import java.util.Scanner;
public class CheckPalindrom {
    public static boolean checkPalindrom(int num){
        // If number is negative then it is not palindrome 
        if(num < 0){
            return false;
        }
        // if reversed num and num be equall , then the number is palindrome
        // first step is find the reversed number
        int x = num;
        int reverse_num = 0;
        int digit;
        while(x != 0){
            digit = x % 10;
            x = x / 10;
            // check overflow condition 
            if(reverse_num > Integer.MAX_VALUE/10 || reverse_num < Integer.MIN_VALUE/10 ){
                System.out.println("The reversed integer is beyond of limit.");
                reverse_num = 0;
                break;
            }
            reverse_num = reverse_num *10 + digit;
        }
        if(num == reverse_num){
            return true;
        }
        else{
            return false;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any number  :- ");
        int num = sc.nextInt();
        System.out.println("the number is palindrome :\t"+CheckPalindrom.checkPalindrom(num));

        
    }
}
