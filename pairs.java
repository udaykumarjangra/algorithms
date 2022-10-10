package arrays;
import java.util.Arrays;
import java.util.Scanner;
public  class Pairs {
    public static void main (String[] args){
        //Scanner userInput = new Scanner(System.in);
        //int target = userInput.nextInt();
        //System.out.println("What is the target number ?");
        int[] arraygiven = {1,2,3,4,5,7};
        System.out.println(Arrays.toString(findPair( arraygiven , 6)));

    }
    static int[] findPair(int[] array, int target){
        for (int i = 0; i < array.length; i++) {
            for (int j = i+1; j < array.length; j++) {
                if(array[i] + array[j] == target){
                    return new int[] {i,j};

                }
            }
        }
        throw new IllegalArgumentException("Solution not found");
    }
}
