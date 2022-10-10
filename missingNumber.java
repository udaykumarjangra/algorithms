package arrays;
public class MissingNumber {
    public static void  missingNumber(int[] intArray) {
        for(int i=1; i<= intArray.length; i++) {
            if (intArray[i - 1] != i) {
                System.out.print(i);

            }

        }
    }



    public static void main(String[] args){
        int [] intArray = {1,2,3,4,5,6,7,8,10};
        missingNumber(intArray);
        //System.out.println(missingNumber(intArray));
    }
}
