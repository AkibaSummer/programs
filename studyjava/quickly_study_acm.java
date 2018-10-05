import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class quickly_study_acm{
    public static void main(String[] args){
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int a;
        double b;
        BigInteger c;
        String st;
//输入：
//Scanner cin = new Scanner (new BufferedInputStream(System.in));
        a = cin.nextInt();
        b = cin.nextDouble();
        c = cin.nextBigInteger();
        st = cin.nextLine();
//输出
//System.out.print(); // cout << …;
//System.out.println(); // cout << … << endl;
//System.out.printf(); // 与C中的printf用法类似.
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.printf("%s\n",st);
    }
}