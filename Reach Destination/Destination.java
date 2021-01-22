
import java.util.*;

public class Destination {
    
    private static int steps(int destination){

        int D = (2) - (4 *((-destination)*2));
        int n = (int)(-1 + Math.sqrt(Math.abs(D)))/(2 * 1);
        int Sum = n*(n+1)/2;
        if(Sum==destination)
            return n;
        Sum=(n+2)*(n+1)/2;
        if(Sum-destination==1)
            return n+2;
        return n+1;
    }

    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        for (int i=0;i<n;i++)
            a[i]=sc.nextInt();
        for (int i=0;i<n;i++){
            System.out.println(steps(a[i]));
        }

    }

}