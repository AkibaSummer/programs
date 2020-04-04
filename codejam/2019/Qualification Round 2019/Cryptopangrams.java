import java.math.BigInteger;
import java.util.Scanner;


public class Solution {
    private static BigInteger _0=BigInteger.valueOf(0);

    private static BigInteger gcd(BigInteger a, BigInteger b){
        if (b.compareTo(_0)==0){
            return a;
        }
        else {
            return gcd(b,a.mod(b));
        }
    }

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        int t;
        t=scanner.nextInt();
        for (int ii = 1; ii <= t; ii++) {
            scanner.nextBigInteger();
            int l=scanner.nextInt();

            System.out.printf("Case #%d: ",ii);

            BigInteger []input=new BigInteger[200];
            BigInteger []ans=new BigInteger[200];
            for (int i=0;i<l;i++){
                input[i]=scanner.nextBigInteger();
            }

            int pos = 0;
            for (int i=0;i<l;i++){
                if (input[i].compareTo(input[i+1])!=0){
                    ans[i+1]=gcd(input[i],input[i+1]);
                    pos=i+1;
                    break;
                }
            }
            for (int i=pos-1;i>=0;i--){
                ans[i]=input[i].divide(ans[i+1]);
            }
            for (int i=pos+1;i<=l;i++){
                ans[i]=input[i-1].divide(ans[i-1]);
            }

            BigInteger []hashtable=new BigInteger[30];

            for (int i=0;i<=l;i++){
                for (int j=0;j<26;j++){
                    if (hashtable[j]==null){
                        hashtable[j]=ans[i];
                        break;
                    }
                    else {
                        final int i1 = hashtable[j].compareTo(ans[i]);
                        if (i1 ==0){
                            break;
                        }
                        else if (i1 >0){
                            for (int k=25;k>j;k--){
                                hashtable[k]=hashtable[k-1];
                            }
                            hashtable[j]=ans[i];
                            break;
                        }
                    }
                }
                if (hashtable[25]!=null)break;
            }

            for (int i=0;i<=l;i++){
                for (int j=0;j<26;j++){
                    if (hashtable[j].compareTo(ans[i])==0){
                        System.out.print((char)(j+(int)'A'));
                        break;
                    }
                }
            }
            System.out.print("\n");
        }
        scanner.close();
    }
}
