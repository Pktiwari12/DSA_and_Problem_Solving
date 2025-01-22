import java.util.Scanner;
public class LargestElement{
    public static int largestElement(int arr[]){
        int largest = arr[0];
        int i;  // counter varible
        for(i = 1 ; i<arr.length ; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
            
        }
        return largest;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array :-");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the element of array ");
        int i;
        for(i = 0 ; i<arr.length ; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Your Entered array is :- ");
        for(i = 0 ; i<arr.length ; i++){
            System.out.print(arr[i]+"\t");
        }
        System.out.println();
        System.out.println("the largest element of array is  \t"+LargestElement.largestElement(arr));
    }
    
}