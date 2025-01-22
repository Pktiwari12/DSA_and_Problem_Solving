import java.util.ArrayList;
import java.util.Scanner;
public class ReversedNumber {

    public static int reverse(int x) {
        // first task is to find digits
        ArrayList<Integer>digits = new ArrayList<Integer>();
        while(x != 0){
            digits.add(x % 10);
            x = x/ 10;

        }
        // ListIterator itr = digits.listIterator();
        int mult = 1;
        int i = digits.size()-1;
        int reverse_num = 0;
        while(i>=0){
            // if(reverse_num > Integer.MAX_VALUE/mult || reverse_num < Integer.MIN_VALUE/mult){
            //     reverse_num = 0;
            //     break;
            // }    // this condition does not hold good for overflow condition because we use mult var
            // in place of 10 
            // So we move to correct way to reverse the number
            reverse_num = reverse_num + digits.get(i)*mult;
            mult = mult*10;
            i--;
        }
        return reverse_num;


        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any number :-");
        int num = sc.nextInt();
        System.out.println("The reversed number :-\t"+ReversedNumber.reverse(num));
        
    }
}
