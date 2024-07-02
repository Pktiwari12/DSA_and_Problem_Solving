// checking Array is sorted or not
import java.util.Scanner;
class CheckSorted{
    public boolean arraySorted(int arr[])
    {
        int i;
        int flag1 = 1;
        int flag2 = 2;
        boolean returnValue = true;
        for(i = 0 ;i<arr.length-1 ;i++){
            if((arr[i+1] >= arr[i]) && flag1 == 1){
                returnValue = true;
                flag2 = 0;
                
            }
            else if(arr[i+1] <= arr[i] && flag2 == 2){
                returnValue = true;
                flag1 = 0;
            }
            else{
                returnValue = false;
            }
        }
        return returnValue;
    }
}
public class SortedArrayCheck{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array :-");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0 ;i<arr.length ; i++){
            arr[i] = sc.nextInt();
        }
        CheckSorted c = new CheckSorted();
        System.out.println("Is Array Sorted  :- "+c.arraySorted(arr));

    }

}
