package arrays;
import java.util.Arrays;

public class bestScore {
    static String firstSecond(Integer[] myArray) {
        Arrays.sort(myArray);
        System.out.println(Arrays.toString(myArray));
         return "a";

    }
public static void main(String[] args){
        Integer[] array = {87,65,78,34,78,34,67,56,45,9,98};
        System.out.print(firstSecond(array));
}

}
