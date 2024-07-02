import java.util.Scanner;
public class SecondLargestElement {
    public static int secondLargestElement(int arr[]){
        boolean flag = true;
        int largest = arr[0];
        int secondLargest = -1;
        int i;  // counter varible
        for(i = 1 ; i<arr.length ; i++){
            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else{
                if(largest != arr[i] && secondLargest < arr[i]){
                    secondLargest = arr[i];
                }
            }
            
            
        }
        // for special condition if all element is -1 
        // then largest will be -1 
        // and mysecondLargest initially initalized by value -1
        if(largest == secondLargest){
            System.out.println("There is no largest value with return value -1");
            // This is for only one condition with array has all elements -1
        }
        return secondLargest;
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
        System.out.println("the second  largest element of array is  \t"+SecondLargestElement.secondLargestElement(arr));
    }
 
}
