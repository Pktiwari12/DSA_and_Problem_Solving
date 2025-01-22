import java.util.Scanner;

import javax.swing.text.html.HTMLDocument.Iterator;

import java.util.*;
class Number{
    public int count; // number of digits
    public int digit_var[]; // digits in number which is stored into array
    // function to count the digits in the number
    public int countDigit(int num){
        int count = 0;
        if(num == 0){
            count++;
        }
        while(num != 0){
            num = num/10;
            count++;
        }
        this.count = count;     // initialize the member variable
        return count;
    }
    // function to store digits of The number into array
     public int[] digits(int num){
         int arr[] = new int[this.count];
         for(int i = 0 ;i<arr.length && num != 0 ; i++){
            arr[i] = num%10;
            num = num/10;
           
         }

         for( int i =0 ;i<arr.length/2 ;i++){
            int temp = arr[i];
            arr[i] = arr[arr.length-1-i];
            arr[arr.length-1-i] = temp;
         }
         this.digit_var = new int[count];
         // copying the element into class member array
         for( int i =0 ;i<digit_var.length && i<arr.length;i++){
            this.digit_var[i] = arr[i];
         
         }
        //  System.out.println("The length of digit_var "+digit_var.length);
        //  for(int i =0 ;i<digit_var.length;i++){
        //     System.out.println(""+digit_var[i]);
        //  }
         return arr;
     }
     // To Count the number of digits in N which evenly divide N ie. reminder will be 0
      public ArrayList<Integer> quotiantDigit(int num){
       // System.out.println(this.digit_var[1]);
       ArrayList<Integer>quotiantdigit = new ArrayList<Integer>();
       int i =0;
       while(num!=0 && i<digit_var.length ){
        if(num%digit_var[i]==0){
            quotiantdigit.add(digit_var[i]);
        }
        i++;
       }
    //    ListIterator itr = quotiantdigit.listIterator();
    //    System.out.println("\nQuotiant Digit\n");
    //    while (itr.hasNext()) {
    //        System.out.print(itr.next());
    //        System.out.println("\t");
    //    }
       return quotiantdigit;

      }
 }
public class CountDigits{
    public static void main(String args[]){
        int num;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any number :-");
        num = sc.nextInt();
        Number n = new Number();
        System.out.println("The number of digits :-\t"+n.countDigit(num));
        int arr [] = n.digits(num);
        for(int i = 0 ;i<arr.length ;i++){
            System.out.print("\t"+arr[i]);
        }
        // n.quotiantDigit(num);
        // ArrayList<Integer>quotiantDigits = new ArrayList<Integer>();
        ArrayList<Integer>quotiantDigits = n.quotiantDigit(num);
        ListIterator itr = quotiantDigits.listIterator();
        System.out.println("\nQuotiant Digit\n");
        while (itr.hasNext()) {
           System.out.print(itr.next());
           System.out.println("\t");
        }
        // ArrayList<Integer>quotiantDigits = n.quotiantDigit(num);
        // ArrayList<Integer>quotiantDigits = new ArrayList<Integer>();
        // ListIterator itr = quotiantDigits.listIterator();
        // System.out.println("Quotiant Digit");
        // while (itr.hasNext()) {
        //     System.out.print(itr.next());
        // }
        
        // System.out.println("The count = "+n.count);

    }
}

