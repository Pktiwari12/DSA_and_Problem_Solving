import java.util.Scanner;
public class ModifiedReverseNumber {
    // Function to return reversed number
    public static  int  reverseNum(int num){
        // first step finding the digits of number 
        // with divid and modulous operator with operand 10
        int digit;
        int reversedNum = 0;
        while(num != 0){
            digit = num%10; // finding the last digit of current num in iteration
            num = num/10;   // updating the number removing last digit
            // forming the number by digits
            if(reversedNum > ((Integer.MAX_VALUE/10)) || reversedNum < (Integer.MIN_VALUE/10)){
                reversedNum = 0;
                break;
            }
            reversedNum = reversedNum*10 + digit;
        }
        return reversedNum;
    }
    public static void main(String [] args){
        System.out.println("Enter any number ");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println("Reversed number of "+num);
        System.out.println(ModifiedReverseNumber.reverseNum(num));

    }
    
}
